#include <stdio.h>

/**
 * This program prompts the user for two input values to compute the average of the two values.
 *
 * @author Michael Long and Kirby Gagne
 * @date 8/29/2016
 * @info Course COP4634
 */


/* don’t test program with more than this many tokens for input */
#define MAXARGS 32

/* structure to hold input data */
struct PARAM
{
    char *inputRedirect;            /* file name or NULL */
    char *outputRedirect;           /* file name or NULL */
    int  argumentCount;             /* number of tokens in argument vector */
    char *argumentVector[MAXARGS];  /* array of strings */
};

/* a typedef so we don’t need to use "struct PARAM" all the time */
typedef struct PARAM Param_t;

/**
 * Print the contents of the structure when the shell is started with the debug option –Debug.
 * @param param the parameters from the user input
 */
void printParams(Param_t * param)
{
    int i;
    printf ("InputRedirect: [%s]\n",
            (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
    printf ("OutputRedirect: [%s]\n",
            (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
    printf ("ArgumentCount: [%d]\n", param->argumentCount);
    for (i = 0; i < param->argumentCount; i++)
        printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}

/**
 * This function starts the program.
 */
int main(int argc, const char * argv[]) {
    //
    char input[MAXARGS];
    
    // Prompt the user for input
    fprintf(stdout, "$$$ ");
    fgets(input, MAXARGS, stdin);
    printf("%s\n",input);
    
    return 0;
}
