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
#include "functions.h"

/**********************************************************************************************************************
 *  local functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATIONS
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: CommandTokenizer
 * Parameters (in):  input - pointer to char, Pin - Dio_PinType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
char **CommandTokenizer(char *input, unsigned int *tokensCount)
{
	unsigned int tokenSeperator = 0;
	unsigned int i = 0, j = 0; /* Loops counters*/
	char **tokens;			   /* hold all token*/
	unsigned int k = 0;		   /*Reset the value of k to zero */

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

	/* Allocating Space for Token
	 * tokens nneed to allocate the size of number of pointers which will be tokenSeperator + 2
	 */
	tokens = (char **)malloc((sizeof(char *) * (tokenSeperator + 2)));

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

		for (j = tokenSize; j > 0; j--)
		{
			tokens[i][tokenSize - j] = input[k - j];
		}
		tokens[i][tokenSize] = '\0'; // adding null terminator
	}

	tokens[i] = NULL; /* Adding the last Null*/

	*tokensCount = tokenSeperator + 1;

	return tokens;
}

/*******************************************************************************
 * Service Name: CommandTokenizer
 * Parameters (in):  input - pointer to pointer to char, location - pointer to unsigned char
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function to locate the type and the location of special character
 *******************************************************************************/
unsigned char special_character_locater(char **input, unsigned char *location)
{
	unsigned int i; /* Counter to loop over input pointer to characters*/
	unsigned int j; /* Counter to loop over the characters*/

	for (i = 0; input[i] != NULL; i++)
	{
		/* Inner loop to loop over the characters*/
		for (j = 0; input[i][j] != 0; j++)
		{
			if (input[i][j] == 61) /* The Ascii value for = is 61*/
			{
				*location = i; /* Setting the location of special character*/
				return SPECIAL_CHR_VARIABLE;
			}
		}
	}
	return SPECIAL_CHR_NULL;
}

