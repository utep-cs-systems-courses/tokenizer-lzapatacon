#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if( c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if (c != ' ' && c != '\t' && c != '\0'){
    return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  while(space_char(*str) == 1 || *str != '\0')
    {
      str++;
    }
  return str;
}
char *word_terminator(char *word)
{
  word = word_start(word);
  while(non_space_char(*word) == 1 || *word != '\0')
    {
      word++;
    }
  return word;
}

int count_words(char *str)
{
  int count = 0;
  char *temp = word_start(str);
  while(*temp)
    {
      if(non_space_char(*temp))
	{
	  count++;
	}
      temp = word_terminator(str);
      temp = word_start(str);
    }
  return count++;
}

char *copy_str(char *inStr, short len)
{
  char *copy = NULL;
  copy =(char*)malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++)
    {
      copy[i] = inStr[i];
    }
  copy[i] = '\0';
  return copy;
}


char **tokenize(char *str)
{
  int size = count_words(str);
  char **tokens = (char**)malloc(size+1 * sizeof(char*));
  char *end;

  int i = 0;
  for(i = 0; i < size; i++)
    {
      str = word_start(str);
      end = word_terminator(str);
      tokens[i] = copy_str(str,(end - str));
      str = word_terminator(str);
    }
  tokens[i] = NULL;
  return tokens;
}
void print_tokens(char **tokens)
{
int i;
for(i = 0;tokens[i]!=NULL;i++)
  {
printf("Token[%d]: %s\n\n",i,tokens[i]);
  }
}



void free_tokens(char **tokens)
{
int i;
for(i = 0; tokens[i] != NULL; i++)
  {
free(tokens[i]);
}
free(tokens);
}
