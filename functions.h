/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  functions.h
 *  Module:  	  functions
 *
 *  Description:  Header file for functions module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  5/8/2023
 *********************************************************************************************************************/


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define BUFFER_SIZE 1000

/* Special MACROS for Errors*/
#define ER_FORKING -1
#define ER_WAITING_ON_CHILD_PROCESS  -2
#define ER_EXEC -3
#define ER_CWD -4

/* Special Macros for identifying which special char exist in the command*/
#define SPECIAL_CHR_NULL    0
#define SPECIAL_CHR_VARIABLE    1


char **CommandTokenizer(char *input, unsigned int *tokensCount);


/*******************************************************************************
 * Service Name: CommandTokenizer
 * Parameters (in):  input - pointer to pointer to char, location - pointer to unsigned char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
unsigned char special_character_locater(char ** input,unsigned char * location);



#endif 
