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


/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/
#define BUFFER_SIZE 1000

/* Special MACROS for Errors*/
#define ER_FORKING -1
#define ER_WAITING_ON_CHILD_PROCESS  -2
#define ER_EXEC -3
#define ER_CWD -4
#define ER_VARIABLE_DEREF   -5
#define ER_WHILE_VARIABLE_DEREF -6
#define ER_WHILE_REPLACING_VALUE_BY_NAME -7
#define ER_WHILE_REDIRECTING -8

/* Special Macros for identifying which special char exist in the command*/
#define SPECIAL_CHR_NULL    0
#define SPECIAL_CHR_VARIABLE    1
#define SEPCIAL_CHR_VARIABLE_DEREF  2
#define SEPCIAL_CHR_IOREDIRECTION_TRUNC  3
#define SEPCIAL_CHR_IOREDIRECTION_APPEND  4



/**********************************************************************************************************************
 *  FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: CommandTokenizer
 * Parameters (in):  input - pointer to char, Pin - Dio_PinType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
char **CommandTokenizer(char *input, unsigned int *tokensCount);


/*******************************************************************************
 * Service Name: CommandTokenizer
 * Parameters (in):  input - pointer to pointer to char, location - pointer to unsigned char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
unsigned char special_character_locater(char **input,
					unsigned char *location);

char **special_character_handler(char **input, unsigned char *state, char ** pathName);



#endif
