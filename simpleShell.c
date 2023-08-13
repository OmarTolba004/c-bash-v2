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
#define _GNU_SOURCE /* For execvpe */
#include <stdio.h>	/*for printf standard library */
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> /* for fork() syscall */
#include <unistd.h>	   /* for fork() syscall */
#include <sys/wait.h>  /* For wait() syscall */
#include <limits.h>	   /* For PATH_MAX */
#include "functions.h"
#include "data_structures.h"
#include "bash_variables.h"
#include "IORedirection.h"

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
		if (getcwd(current_working_dir, sizeof(current_working_dir)) ==
			NULL)
			return ER_CWD;

		char *user_name = getlogin();
		printf("\033[1;32m%s@%s-VirtualBox$:\033[1;34m%s\033[1;0m$ ", user_name, user_name, current_working_dir);

		/* Reading input from user */
		/* Important Note:
		 * in fgets, If a newline is read, it is stored  into the buffer.  A terminating null byte ('\0') is stored after the last character in
		 * the buffer. so to check the end of
		 */
		fgets(input, sizeof(input), stdin);
		/* Tokenizing the input */
		char **prog_argv = CommandTokenizer(input, &tokensCount);

		/* Handling special character */
		unsigned char state = 0;
		char *pathName; /* is optional to be used*/
		prog_argv = special_character_handler(prog_argv, &state, &pathName);

		if (state == SPECIAL_CHR_VARIABLE)
		{
			continue;
		}

		/* Handling special commands */
		if (strcmp(prog_argv[0], "exit") == 0)
		{
			free(prog_argv);
			exit(0);
		}

		/* Forking */
		pid_t ret_pid = fork();

		if (ret_pid == -1)
		{ /* Forking failed */
			printf("Forking Failed \n");
			return ER_FORKING;
		}
		else if (ret_pid > 0)
		{ /* Parent Process */
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

				if (WIFEXITED(status))
				{ /* Break if the process terminated normally */
					break;
				}
			}
		}
		else if (ret_pid == 0)
		{ /*child process */

			if (state == SEPCIAL_CHR_IOREDIRECTION_TRUNC)
			{ /* Truncating case*/
				IORedirection_redirecting_trunc(1, pathName);
			}

			if (state == SEPCIAL_CHR_IOREDIRECTION_APPEND)
			{ /* appendin case*/
				IORedirection_redirecting_append(1, pathName);
			}

			execvpe(prog_argv[0], prog_argv, environ);
			printf("Exec Failed\n");
			return ER_EXEC;
		}
	}
	return 0;
}
