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

#define ER_FORKING -1
#define ER_WAITING_ON_CHILD_PROCESS  -2
#define ER_EXEC -3
#define ER_CWD -4



void gettingTheCommand(char *input, char **command, char *commandSize);

void gettingTheRestOfCommand(char *input, char **restOfCommand, char commandSize, char *restOfCommandSize);

char **CommandTokenizer(char *input, unsigned int *tokensCount);



#endif 
