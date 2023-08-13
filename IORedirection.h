/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IORdirection.h
 *  Module:  	  input output redirection
 *
 *  Description:  header file for IORedirection handler
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  12/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/
#define IO_STDIN_FD_VALUE 0
#define IO_STDOUT_FD_VALUE 1
#define IO_STDERR_FD_VALUE 2

/**********************************************************************************************************************
 *  FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/


/*******************************************************************************
 * Service Name: IORedirection_redirecting_trunc
 * Parameters (in):  redirectionType - unsigned int, pathName - pointer to const char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to IORedirection and truncate the redirected file
 *******************************************************************************/
void IORedirection_redirecting_trunc(unsigned int redirectionType, const char *pathName);


/*******************************************************************************
 * Service Name: IORedirection_redirecting_append
 * Parameters (in):  redirectionType - unsigned int, pathName - pointer to const char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to IORedirection and appaned on the redirected file
 *******************************************************************************/
void IORedirection_redirecting_append(unsigned int redirectionType, const char *pathName);




char * IORedirection_Seperating_the_command(char ***input, unsigned char index);
