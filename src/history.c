#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()

{
  List *list = malloc( sizeof( List));
  list -> root = malloc( sizeof( Item));
  return list;
}

void add_history(List *list, char *str)
{
  int pos = 1;
  Item *temp = list->root;
  while(temp){
    temp = temp->next;
    pos++;
  }
  temp=malloc(sizeof(Item));
  temp->id = pos;
  temp->str = str;
}

char *get_history(List *list, int id)
{
  Item *tmp;
  if(!list){
    return '\0';
  }
  else{
    tmp = list->root;
    while(tmp){
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
    while(tmp){
      printf("%d: %s\n",tmp->id,tmp->str);
      tmp->next;
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

