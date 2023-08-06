/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  functions.c
 *  Module:  	  functions
 *
 *  Description:  Source file for functions module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  5/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************************************************
 *  local functions
 *********************************************************************************************************************/

static unsigned int countNumberOfLetters(char *str);


/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATIONS
 *********************************************************************************************************************/

void gettingTheCommand(char *input, char **command, char *commandSize)
{
    /* Calculating the command size*/
    int i = 0; // index used to interate over input string
    while (input[i] != 32 && input[i]!=10) // 10 is the ascii of new line
        i++; // 32 is the ascii value of space
    *commandSize = i;
    *command = (char *)malloc(sizeof(char) * (*commandSize));

    /*assigning command to commandVar*/
    for (i = 0; i < *commandSize; i++)
    {
        (*command)[i] = input[i];
    }
    (*command)[i] = '\0'; // adding null charachter
}

void gettingTheRestOfCommand(char *input, char **restOfCommand, char commandSize, char *restOfCommandSize)
{
    int i = commandSize;
    while (input[i] != 10 && input[i]!= '\0') // 10 is the ascii of new line
        i++;
    char totalCommandSize = i;
    *restOfCommandSize = i - commandSize;
    *restOfCommand = (char *)malloc(sizeof(char) * (*restOfCommandSize));
    /*assigning command to commandVar*/
    for (i = commandSize + 1; i < totalCommandSize; i++)
    {
        (*restOfCommand)[i - (commandSize + 1)] = input[i];
    }
    (*restOfCommand)[i] = '\0'; // adding null charachter
}



char **CommandTokenizer(char *input, unsigned int *tokensCount)
{
	unsigned int tokenSeperator = 0;
	unsigned int i = 0, j = 0; /* Loops counters*/
	char **tokens;			   /* hold all token*/
	unsigned int numberOfLetters;
	unsigned int k = 0; /*Reset the value of k to zero */

	/* Getting Spaces count */
	while (input[i] != 0 && input[i] != 10) // new line ASCII code is 10
	{
		/* Don't count first Space*/
		if (i == 0)
		{
			while (input[i] == 32)
				i++;
		}
		if (input[i] == 32) /* Space in Ascii is 32*/
		{

			tokenSeperator++;
			/* loop till reaching next char, avoiding of counting duplicated space again*/
			while (input[i + 1] == 32)
				i++;

			if (input[i] == 32 && (input[i + 1] == 10 || input[i + 1] == 0)) /* space after last token, abort it*/
			{
				tokenSeperator--; /* same procedure can be done by incrementing only in the situation of not last expression*/
			}
		}
		i++;
	}

	//printf("Token separator Count is %d\n", tokenSeperator);

	/* Allocat internal Tokens Pointer
	 * Notes :
	 * 1 - number of tokens will be number of tokenSeperator + 2(Null + last word)
	 * 2 - malloc will allocate #numberOfPointersToChar pointers to characters and they will be passed to token variable
	 * 	   after derefrencing
	 */
	numberOfLetters = countNumberOfLetters(input);

	//printf("Number of letters is : %d\n", numberOfLetters);

	/* Allocating Space for Token
	 * size of tokens need to calculate the size of pointer NULL
     * +10 for safety
	*/
	tokens = (char **)malloc((sizeof(char) * (numberOfLetters + tokenSeperator + 2))+ sizeof(tokens)+10*sizeof(char)); 

	/* Dynamically allocating each token*/
	for (i = 0; i < tokenSeperator + 1; i++)
	{
		unsigned int tokenSize = 0;

		while (input[k] == 32)
		{
			k++; /* Move k to the next char*/
		}

		/*Count Token Size*/
		while (input[k] != 32)
		{
			tokenSize++;
			k++;
			if (input[k] == 10 || input[k] == 0)
				break; /* break if you get out of the array*/
		}

		/* Allocating each internal token with the current tokenSize*/
		tokens[i] = (char *)malloc(sizeof(char) * (tokenSize + 1)); // adding 1 for null terminator

		//printf("TokenSize is %d\n", tokenSize);

		for (j = tokenSize; j > 0; j--)
		{
			tokens[i][tokenSize - j] = input[k - j];
		}
		tokens[i][tokenSize] = '\0'; // adding null terminator

		//printf("tokens[i], at i = %d and j = %d  is :%s \n", i, j, tokens[i]);

	}

	tokens[i] = (char *)malloc(sizeof(tokens)); /* Allocating space for last null--> note Null is of kind pointer*/
	tokens[i] = NULL; /* Adding the last Null*/

	//printf("Value of i is %d and token speerator %d\n", i, tokenSeperator);

    *tokensCount = tokenSeperator+1;

	return tokens;
}

static unsigned int countNumberOfLetters(char *str)
{
	unsigned int numberOfLetters = 0;
	unsigned int i = 0;
	while (1)
	{
		if (str[i] != 32 && str[i] != 10 && str[i] != 0)
			numberOfLetters++;
		if (str[i] == 10 || str[i] == 0)
			break;
		i++;
	}
	return numberOfLetters;
}
