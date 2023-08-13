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
#include <string.h>
#include "functions.h"
#include "IORedirection.h"

/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: IORedirection_redirecting_trunc
 * Parameters (in):  redirectionType - unsigned int, pathName - pointer to const char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to IORedirection and truncate the redirected file
 *******************************************************************************/
void IORedirection_redirecting_trunc(unsigned int redirectionType, const char *pathName)
{
    int open_flags = O_RDWR | O_TRUNC | O_CREAT;                                               /* setting open flags*/
    mode_t open_modes = (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); /* setting open modes */
    int new_fd = open(pathName, open_flags, open_modes);

    /* Checking redirection type*/
    if (redirectionType == 0)
    { /* Input redirection*/
        dup2(new_fd, IO_STDIN_FD_VALUE);
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

/*******************************************************************************
 * Service Name: IORedirection_redirecting_append
 * Parameters (in):  redirectionType - unsigned int, pathName - pointer to const char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to IORedirection and appaned on the redirected file
 *******************************************************************************/
void IORedirection_redirecting_append(unsigned int redirectionType, const char *pathName)
{
    int open_flags = O_RDWR | O_APPEND | O_CREAT;                                              /* setting open flags*/
    mode_t open_modes = (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); /* setting open modes */
    int new_fd = open(pathName, open_flags, open_modes);

    /* Checking redirection type*/
    if (redirectionType == 0)
    { /* Input redirection*/
        dup2(new_fd, IO_STDOUT_FD_VALUE);
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


/*******************************************************************************
 * Service Name: IORedirection_Seperating_the_command
 * Parameters (in):  input - pointer to pointer to char, state - unsigned char index
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: char *
 * Description: Function to seperate the command in the case of IORedirection
 *******************************************************************************/
char * IORedirection_Seperating_the_command(char ***input, unsigned char index)
{
    unsigned short after_arrow_size = 0; /* after arrow size which need to be calculated*/

    char **before_arrow; /* Befroe arrow pointer to pointer to char , adjusted input*/

    char *pathName;

    unsigned int i = 0; /* counter used to loop over the input command*/

    /* Dynamically allocating the inner pointers*/
    before_arrow = (char **)malloc(sizeof(before_arrow) * (index + 1)); /* +1 for the last null*/

    for (i = 0; i < index; i++)
    {
        before_arrow[i] = (*input)[i]; /* make both internal pointers equal*/
    }

    before_arrow[i] = NULL; /* adding Null pointer*/

    i = index + 1;
    while ((*input)[i] != NULL)
        i++;

    after_arrow_size = i - index - 1; /* Calculating after arrow size*/

    if (after_arrow_size > 1)
    {
        printf("Error : you can't add more than one string after redirection \n");
    }


    /* Dynamically allocating the string of pathName size*/
    pathName = (char *)malloc(sizeof(char) * sizeof((*input)[index + 1]));
    strcpy(pathName, (*input)[index + 1]);

    /* assign before arrow to input , adjusing input*/
    *input = before_arrow;


    return pathName;
}