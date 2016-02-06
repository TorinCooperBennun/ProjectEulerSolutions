#ifndef PROBLEMS_H_INCLUDED
#define PROBLEMS_H_INCLUDED

/* There are 535 problems as of 6 February 2016, so 600 seems a reasonable
   limit. */
#define MAX_PROBLEMS 600

typedef void (*problem_proc)(void);

extern problem_proc g_problems[MAX_PROBLEMS];

void         init_problems(void);
problem_proc get_problem(int number);

void         register_problem(int number, problem_proc proc);

#endif
