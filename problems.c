#include "problems.h"
#include <assert.h>
#include <string.h>

#define REGISTER_PROBLEMS

#define REGISTER_PROBLEM(n) void register_p##n(void);

#define REGISTER_PROBLEM(n) CONCAT(REGISTER_PROBLEMS,

problem_proc g_problems[MAX_PROBLEMS];

void init_problems(void)
{
    memset(g_problems, 0, MAX_PROBLEMS * sizeof(problem_proc));

    /* When a new problem N is added, add REGISTER_PROBLEM(N) to the list
       below. */
    REGISTER_PROBLEM(53)
}

problem_proc get_problem(int number)
{
    if (number >= 1 && number <= MAX_PROBLEMS && g_problems[number] != NULL) {
        return g_problems[number - 1];
    }
    else {
        return NULL;
    }
}

void register_problem(int number, problem_proc proc)
{
    assert(number >= 1 && number <= MAX_PROBLEMS);
    g_problems[number] = proc;
}
