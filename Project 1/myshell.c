//
//  main.c
//  Project 1
//
//  Created by skywalker_OG on 8/26/16.
//  Copyright © 2016 Michael Long. All rights reserved.
//

#include <stdio.h>

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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
