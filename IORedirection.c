/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IORdirection.c
 *  Module:  	  input output redirection
 *
 *  Description:  source file for IORedirection handler
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  12/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "IORedirection.h"

/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/
void IORedirection_redirecting_turnc(unsigned int redirectionType, const char *pathName)
{
    int open_flags = O_RDWR | O_TRUNC | O_CREAT; /* setting open flags*/
    mode_t open_modes = (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); /* setting open modes */
    int new_fd = open(pathName, open_flags, open_modes);

    /* Checking redirection type*/
    if (redirectionType == 0)
    { /* Input redirection*/
        dup2(new_fd, IO_STDOUT_FD_VALUE );
        close(new_fd);
    }
    else if (redirectionType == 1)
    { /* output redirection*/
        dup2(new_fd, IO_STDOUT_FD_VALUE);
        close(new_fd);
    }
    else if (redirectionType == 2)
    { /* error redirection*/
        dup2(new_fd, IO_STDERR_FD_VALUE);
        close(new_fd);
    }
    else
    {
        printf("unexpected error while redirecting, in correct redirection type\n");
        exit(ER_WHILE_REDIRECTING);
    }
}
