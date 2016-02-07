#ifndef PROBLEMS_H_INCLUDED
#define PROBLEMS_H_INCLUDED

/* Internal macros */
#define PROBLEM_FUNC(n) p##n
#define PROBLEM_FUNC_SIGNATURE(n) void PROBLEM_FUNC(n) (void)
#define PROBLEM_REGISTER_FUNC(n) register_p##n
#define PROBLEM_REGISTER_FUNC_SIGNATURE(n) \
    void PROBLEM_REGISTER_FUNC(n) (void)
#define g_problems g_problems

/* See problems.c for usage of these two macros */
#define DECLARE_PROBLEM(n) PROBLEM_REGISTER_FUNC_SIGNATURE(n) ;

#define REGISTER_PROBLEM(n) PROBLEM_REGISTER_FUNC(n) ();

/* See p54.c for an example of how to use these two macros */
#define BEGIN_PROBLEM(n) \
    PROBLEM_FUNC_SIGNATURE(n); \
    PROBLEM_REGISTER_FUNC_SIGNATURE(n) { \
        register_problem(n, PROBLEM_FUNC(n)); \
    } \
    PROBLEM_FUNC_SIGNATURE(n) {

#define END_PROBLEM }

/* There are 535 problems as of 6 February 2016, so 600 seems a reasonable
   limit. */
#define MAX_PROBLEMS 600

typedef void (*problem_proc)(void);

extern problem_proc g_problems[MAX_PROBLEMS];

void         init_problems(void);
problem_proc get_problem(int number);
void         register_problem(int number, problem_proc proc);

#endif
