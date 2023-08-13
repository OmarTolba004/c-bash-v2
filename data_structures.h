/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  data_strucutres.h
 *  Module:  	  data_structures
 *
 *  Description:  header file for data structures
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  8/8/2023
 *********************************************************************************************************************/

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "bash_variables.h"

/**********************************************************************************************************************
 *  Global structures
 *********************************************************************************************************************/
struct node {
    struct bash_variable *data;
    struct node *next;
};



/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  bash_variable - variable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to insert bash variable to the end of data structures
 *******************************************************************************/
void insertAtLast(struct bash_variable variable);


/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  bash_variable - variable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to insert bash variable to the end of data structures
 *******************************************************************************/
void printList(void);


/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  bash_variable - variable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to insert bash variable to the end of data structures
 *******************************************************************************/
char *return_value_by_name(char *name);


/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  bash_variable - variable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to insert bash variable to the end of data structures
 *******************************************************************************/
unsigned char return_valueSize_by_name(char *name);


/*******************************************************************************
 * Service Name: replace_value_by_name
 * Parameters (in):  char * - name
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: function to relpce value of data structure using the name
 *******************************************************************************/
void replace_value_by_name(char *name, char *value);


#endif
