/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  simpleShell.c
 *  Module:  	  simple Shell
 *
 *  Description:  Source file for third assignment
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  5/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#define _GNU_SOURCE /* For execvpe*/
#include <stdio.h>  /*for printf standard library*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> /* for fork() syscall*/
#include <unistd.h>    /* for fork() syscall*/
#include <sys/wait.h>  /* For wait() syscall*/
#include "functions.h"
#include <limits.h> /* For PATH_MAX*/

/**********************************************************************************************************************
 *  EXTERN GLOBAL VARIABLES
 *********************************************************************************************************************/

extern char **environ;

/**********************************************************************************************************************
 *  MAIN FUNCTIONS
 *********************************************************************************************************************/

int main(int argc, char **argv)
{
    char input[BUFFER_SIZE];
    unsigned int tokensCount;
    char current_working_dir[PATH_MAX];
    while (1)
    {
        if (getcwd(current_working_dir, sizeof(current_working_dir)) == NULL)
            return ER_CWD;

        printf("usr@VirtualBox$:%s$ ", current_working_dir);

        /* Reading input from user*/
        /* Important Note:
         * in fgets, If a newline is read, it is stored  into the buffer.  A terminating null byte ('\0') is stored after the last character in
         * the buffer. so to check the end of
         */
        fgets(input, sizeof(input), stdin);
        /* Tokenizing the input*/
        char **prog_argv = CommandTokenizer(input, &tokensCount); 

        /* Handling special commands*/
        if (strcmp(prog_argv[0], "exit") == 0)
        {
            free(prog_argv);
            exit(0);
        }

        
        /* Forking*/
        pid_t ret_pid = fork();

        if (ret_pid == -1) /* Forking failed*/
        {
            printf("Forking Failed \n");
            return ER_FORKING;
        }
        else if (ret_pid > 0) /* Parent Process*/
        {
            unsigned int status;
            pid_t wait_pid;
            while (1)
            {
                wait_pid = wait(&status);
                if (wait_pid == -1)
                {
                    printf("Waiting on child process returned with an Erorr\n");
                    return ER_WAITING_ON_CHILD_PROCESS;
                }

                if (WIFEXITED(status)) /* Break if the process terminated normally*/
                {
                    printf("\n"); /* Printing new line for visualiztion*/
                    break;
                }
            }
        }
        else if (ret_pid == 0) /*child process*/
        {
            execvpe(prog_argv[0], prog_argv, environ);
            printf("Exec Failed\n");
            return ER_EXEC;
        }
    }

    return 0;
}
