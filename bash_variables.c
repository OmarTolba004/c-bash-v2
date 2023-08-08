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
