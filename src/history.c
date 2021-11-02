#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *history;
  history = (List*)malloc(sizeof(List));
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *new = malloc(sizeof(Item));
  if(list->root == NULL)
    {
      new->id = 1;
      list->root = new;
    }
  else
    {
      Item *temp = list->root;
      while(temp != NULL)
	{
	  temp = temp->next;
	}
      temp = new;
    }
  new -> str = str;
  new -> next = NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  if (list ->root == NULL)
    {
      return "empty";
    }
  else
    {
      Item *temp = list->root;
      while(temp != NULL)
	{
	  if(temp->id == id)
	    {
	      return temp->str;
	    }
	  temp = temp -> next;
	}
    }
  return "Nothing";
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL)
    { 
      printf("History Item [%d]: %s \n", temp->id, temp->str);
      temp = temp -> next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  while(list -> root != NULL)
    {
      free(list -> root -> str);
      list->root = list->root -> next;
    }
  free(list);
}
