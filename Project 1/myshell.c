#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * Allocate memory for the struct PARAM
 * @return a pointer to the newly allocated memory for the struct PARAM
 */
Param_t *createPARAM() {
    Param_t *PARAM = (Param_t *) malloc (sizeof (struct PARAM));
    if (!PARAM) {
        fprintf (stderr, "> Ran out of memory! \n");
        exit (1);
    }
    
    return PARAM;
}

/**
 * Add a token to the argumentVector
 */
void addToken(Param_t *PARAM, char *tok, int i) {
    PARAM->argumentVector[i] = tok;
}

/**
 * Free memory allocated for the struct PARAM
 * @param a pointer to memory allocated for the struct PARAM
 *
 * @return a NULL pointer
 */
Param_t *deletePARAM(Param_t *PARAM) {
    free(PARAM);
    return NULL;
}

/**
 * This function starts the program.
 */
int main(int argc, const char * argv[]) {
    //
    char input[MAXARGS];
    char demin[] = " \n\t";
    char *token;
    
    // Prompt the user for input
    fprintf(stdout, "$$$ ");
    fflush(stdout);
    fgets(input, MAXARGS, stdin);
    
    // Continues to prompt user for input until "exit" command is entered
    while(strcmp(input, "exit\n") != 0)
    {
        // Get the first token and add it to the struct
        Param_t *PARAM = createPARAM();
        int i = 0;
        token = strtok(input, demin);
        addToken(PARAM, token, i);
        
        // Get the rest of the tokens and add them to the struct
        while(token) {
            i++;
            token = strtok(NULL, demin);
            if(token) addToken(PARAM, token, i);
        }
        
        printf("%s\n",input);
        fprintf(stdout, "$$$ ");
        fflush(stdout);
        deletePARAM(PARAM);
        fgets(input, MAXARGS, stdin);
    }
    return 0;
}
