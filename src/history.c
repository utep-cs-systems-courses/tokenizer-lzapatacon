#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()

{
  List *list = malloc(sizeof( List));
  list -> root = malloc( sizeof( Item));
  return list;
}

void add_history(List *list, char *str)
{
  int pos = 1;
  Item *temp = list->root;
  Item *newItem = malloc(sizeof(str));
  while(temp->next != NULL){
    temp = temp->next;
    pos++;
  }
  temp->next = newItem;
  temp->next-> str = str;
  temp->next-> id = pos;
}

char *get_history(List *list, int id)
{
  Item *tmp;
  if(!list){
    return '\0';
  }
  else{
    tmp = list->root;
    while(tmp!= NULL){
      if(tmp->id == id){
	return tmp->str;
      }
      tmp = tmp->next;
    }
    return '\0';
  }
}



void print_history(List *list)
{
  if (list == NULL){
    printf("History is empty, please enter some sentences.\n");
  }
  else{
    Item *tmp = list->root;
    int i = 0;
    while(tmp != NULL){
      printf("%d: %s\n",tmp->id,tmp->str);
      tmp = tmp->next;
      i++;
    }
    printf("\n");
  }
}



void free_history(List *list)
{
  Item *tmp;
  Item *head = list->root;
  while(head){
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

