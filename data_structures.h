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

#include "bash_variables.h"

struct node
{
    struct bash_variable * data;
    struct node * next;
};

void insertAtLast(struct bash_variable variable);

void printList(void);



#endif
