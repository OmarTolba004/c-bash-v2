/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  bash_variables.c
 *  Module:  	  bash variables
 *
 *  Description:  header file for bash variables handler
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  8/8/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "bash_variables.h"
#include "data_structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/**********************************************************************************************************************
 *  STATIC GLOBAL TO THE FILE VARIABLES
 *********************************************************************************************************************/
static struct node *head = NULL;	/* linked list head */


/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  bash_variable - variable
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to insert bash variable to the end of data structures
 *******************************************************************************/
void insertAtLast(struct bash_variable variable)
{
    struct node *current = NULL;	/* used to loop over the linked list */

    /* Allocating memory for new node */
    struct node *link = (struct node *) malloc(sizeof(struct node));

    /* Allocating memory for bash variable strucutre */
    link->data =
	(struct bash_variable *) malloc(sizeof(struct bash_variable));

    /* Allocating memory for new bash variable */
    link->data->name =
	(char *) malloc(sizeof(char) * strlen(variable.name));
    link->data->value =
	(char *) malloc(sizeof(char) * strlen(variable.value));

    /* Copying data to the new node data */
    strcpy((link->data)->name, variable.name);
    strcpy((link->data)->value, variable.value);

    /* making new node pointing to NULL */
    link->next = NULL;

    /* if head is empty create new linked list */
    if (head == NULL) {
	head = link;
	return;
    }

    /* setting current to head to loop with */
    current = head;

    /* Go forward till the last node */
    while (current->next != NULL) {
	current = current->next;
    }

    /* make the last node points to the new created note */
    current->next = link;

}

/*******************************************************************************
 * Service Name: insertAtLast
 * Parameters (in):  void
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function to print the content of the linked list
 *******************************************************************************/
void printList(void)
{
    struct node *ptr = head;
    printf("[head] =>");
    /* looping over the linked list */
    while (ptr != NULL) {
	printf(" %s, %s =>", (ptr->data)->name, (ptr->data)->value);
	ptr = ptr->next;
    }
    printf(" [NULL]\n");
    free(ptr);			/* free ptr */
}


/*******************************************************************************
 * Service Name: return_value_by_name
 * Parameters (in):  char * - name
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: char *
 * Description: Function value of data structure using the name
 *******************************************************************************/
char *return_value_by_name(char *name)
{
    struct node *current = head;	/* Initializing current pointer to point to head */

    if (head == NULL) {
	printf("No Variable are assigned before at all\n");
	return NULL;
    }

    while (current != NULL) {
	if (strcmp(current->data->name, name) == 0)	/* strings are equal */
	    return current->data->value;
	current = current->next;
    }

    printf("your variable %s doesn't exits \n", name);
    // free(current); /* free current*/
    return NULL;		/* No variable with that name are assigned before */
}


/*******************************************************************************
 * Service Name: return_valueSize_by_name
 * Parameters (in):  void
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: void
 * Description: Function value of data structure string size using the name
 *******************************************************************************/
unsigned char return_valueSize_by_name(char *name)
{
    struct node *current = head;	/* Initializing current pointer to point to head */

    if (head == NULL) {
	return 0;
    }

    while (current != NULL) {
	if (strcmp(current->data->name, name) == 0) {	/* strings are equal */
	    return strlen(current->data->value);
	}
	current = current->next;
    }

    return 0;			/* No variable with that name are assigned before */
}
