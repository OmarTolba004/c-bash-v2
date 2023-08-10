/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  bash_variables.c
 *  Module:  	  bash variables
 *
 *  Description:  header file for bash variables handler
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  8/8/2023
 *********************************************************************************************************************/


#ifndef BASH_VARIABLES_H
#define BASH_VARIABLES_H

/**********************************************************************************************************************
 *  STRUCTURES
 *********************************************************************************************************************/
#include "data_structures.h"

/**********************************************************************************************************************
 *  STRUCTURES
 *********************************************************************************************************************/
struct bash_variable		//TODO : is this structure has incomplete type
{
    char *name;			/* Name of the variable */
    char *value;		/* Value of the variable */
};

/**********************************************************************************************************************
 *  FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: adding_bash_var
 * Parameters (in):  input - pointer to pointer to char, index - pointer to unsigned char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to add bash variable to the data structure
 *******************************************************************************/
void adding_bash_var(char **input, unsigned int index);



/*******************************************************************************
 * Service Name: bash_variable_deref
 * Parameters (in):  input - pointer to pointer to char, location - pointer to unsigned char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: char **
 * Description: Function for derefrencing bash variable
 *  *******************************************************************************/
char **bash_variable_deref(char **input, unsigned int index);

#endif
