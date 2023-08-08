#include "bash_variables.h"
#include "data_structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct node *head = NULL; /* linked list head*/

void insertAtLast(struct bash_variable variable)
{
    struct node *current = NULL; /* used to loop over the linked list*/

    /* Allocating memory for new node*/
    struct node *link = (struct node *)malloc(sizeof(struct node));

    /* Allocating memory for bash variable strucutre*/
    link->data = (struct bash_variable *)malloc(sizeof(struct bash_variable));

    /* Allocating memory for new bash variable*/
    link->data->name = (char *) malloc(sizeof(char) * strlen(variable.name));
    link->data->value = (char *) malloc(sizeof(char) * strlen(variable.value));

    /* Copying data to the new node data*/
    strcpy((link->data)->name, variable.name);
    strcpy((link->data)->value, variable.value);
    
    /* making new node pointing to NULL*/
    link->next = NULL;

    /* if head is empty create new linked list*/
    if (head == NULL)
    {
        head = link;
        return;
    }

    /* setting current to head to loop with*/
    current = head;

    /* Go forward till the last node*/
    while (current->next != NULL)
    {
        current = current->next;
    }

    /* make the last node points to the new created note*/
    current->next = link;
}

/* Function to print the content of the linked list*/
void printList(void)
{
    struct node *ptr = head;
    printf("[head] =>");
    /* looping over the linked list*/
    while (ptr != NULL)
    {
        printf(" %s, %s =>", (ptr->data)->name, (ptr->data)->value);
        ptr = ptr->next;
    }
    printf(" [NULL]\n");
}
