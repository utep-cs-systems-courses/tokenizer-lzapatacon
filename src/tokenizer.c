#include <stdlio.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if( c == '' || c == \t)
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if (c == '' || c == \t){
    return 0;
  }
  return 1;
}

char *word_start(char *str)
{
  if (count_words(str) > 0)
  {
    int ptr = 0;
    while(space_char(str[ptr]))
      {
	ptr++;
      }
    return (ptr++);
  }
  return 0;
}
char *word_terminator(char *word)
{
  int ptr = 0;
  while(non_space_char(str))
    {
      ptr++;
    }
  return ptr;
}

int count_words(char *str)
{
  int count = 0;
  int i = 0;
  
  while(non_space_char(str[i]))
    {
      i++;
      if (space_char[str[i+1])
	{
	  count++;
	  i = i + 2;
	}
    }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *s = (char)malloc(len);
  s = strcpy(inStr, len);
  return s;
}


char **tokenize(char* str)
{
  int *ptr = 0;
  while(space_char[ptr])
    {
      
    }
}

void print_tokens(char **tokens)
{

}



void free_tokens(char **tokens)
{

}
