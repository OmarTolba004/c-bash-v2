/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  bash_variable.c
 *  Module:  	  bash_variable
 *
 *  Description:  Source file for bash variables
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  5/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "bash_variables.h"
#include "data_structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  STATIC FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATIONS
 *********************************************************************************************************************/
void adding_bash_var(char **input, unsigned int index) /* index represents the location of token who has assignment operation*/
{
    struct bash_variable bashVar;
    char *name;
    char *value;
    unsigned char nameSize;
    unsigned char valueSize;
    unsigned int j = 0;

    while (input[index][j] != '=')
        j++;

    nameSize = j;                         /* assigning nameSize*/
    valueSize = strlen(input[index]) - 1; /* assigning valueSize*/

    name = (char *)malloc(sizeof(char) * (nameSize + 1));   /* +1 for the null termiator*/
    value = (char *)malloc(sizeof(char) * (valueSize + 1)); /* +1 for the null termiator*/

    for (j = 0; j < nameSize; j++)
    {
        name[j] = input[index][j];
    }
    name[j] = '\0'; /* adding null terminator*/

    for (j = 0; j < valueSize; j++)
    {
        value[j] = input[index][j + nameSize + 1];
    }
    value[j] = '\0'; /* adding null terminator*/
    bashVar.name = name;
    bashVar.value = value;

    insertAtLast(bashVar);

}

char **bash_variable_deref(char **input, unsigned int index)
{
    char * value;
    char * name;
    unsigned char valueSize = 0;
    unsigned char nameSize = 0; /*Variable to hold name size*/
    unsigned int j =0;             /* Counter used to loop over sring*/

    if (input[index][j] != '$')
    {
        printf("unexpected error while derefrencing variable\n");
        // exit(ER_WHILE_VARIABLE_DEREF);
    }

    j = 1;
    while (input[index][j] != 0)
        j++; /* counting name size*/

    nameSize = j; /* assigning j to nameSize, +1 for null terminator*/

    /* dynamically allocating size for name*/
    name = (char *)malloc(sizeof(char) * (nameSize + 1));

    for (j = 0; j < nameSize; j++)
    {
        name[j] = input[index][j + 1];
    }

    name[j] = '\0'; /* adding null terminator*/

    // printf("name is %s\n", name);

    valueSize = return_valueSize_by_name(name);

    // printf("valus size %d\n", valueSize);

    if (valueSize == 0)
    {
        printf("Variable doesn't exist\n");
        return input; /* return input as it is*/
    }


    input[index]= (char *) malloc(sizeof(char)*valueSize);

    input[index] = return_value_by_name(name);

    // printf("value of name is %s and value of value is %s\n",name,input[index]);

    return input;
    // free(name);
    // free(value);
}