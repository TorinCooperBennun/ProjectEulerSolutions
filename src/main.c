#include "problems.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 1024

int main(void)
{
    bool quit;
    char input[INPUT_SIZE];
    int problem_n;
    problem_proc problem_ptr;

    init_problems();

    quit = false;
    do {
        printf("Enter a problem number or (q)uit: ");

        memset(input, 0, INPUT_SIZE * sizeof(char));
        fgets(input, INPUT_SIZE, stdin);

        if (sscanf(input, "%d", &problem_n) != 1) {
            quit = (!strcmp(input, "q\n") || !strcmp(input, "quit\n"));
            if (!quit) {
                printf("Invalid input!\n");
            }
        }
        else {
            problem_ptr = get_problem(problem_n);
            if (problem_ptr == NULL) {
                printf("Problem is not implemented!\n", problem_n);
            }
            else {
                problem_ptr();
            }
        }
    } while (!quit);

    return 0;
}
