#include "problems.h"
#include <assert.h>
#include <string.h>

void p54(void);

problem_proc g_problems[MAX_PROBLEMS];

void init_problems(void)
{
    memset(g_problems, 0, MAX_PROBLEMS * sizeof(problem_proc));

    g_problems[53] = &p54;
}

problem_proc get_problem(int number)
{
    if (number >= 1 && number <= MAX_PROBLEMS) {
        return g_problems[number - 1];
    }
    else {
        return NULL;
    }
}

void register_problem(int number, problem_proc proc)
{
    assert(number >= 1 && number <= MAX_PROBLEMS);
    g_problems[number - 1] = proc;
}
