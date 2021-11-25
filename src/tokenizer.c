#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if (( c == ' '|| c == '\t')&&c!='\0' ){//checks if space or tab
    return 1;
  }
  return 0;
}
int non_space_char(char c)
{
  if ((c==' '||c=='\t') || c== '\0' ){//checks if space or tab
    return 0;
  }
  return 1;
}
char *word_start(char *word)
{
  int i=0;

  while(*(word + i)){

    if (non_space_char(*(word + i))){
      return word + i;
    }
    i++;
  }
  return word + i;
}
char *word_terminator(char *word)
{
  int i=0;
  while(*(word + i)){
    if(space_char(*(word + i))){
      return word + i;
    }
    i++;
  }
  return word + i;
}

int count_words(char *str)

{
  char *tmp = str;
  int count = 0;
  int i = 0;//pointer is on the first char in the first word
  tmp = word_start(tmp);
  while(*tmp){
    if(non_space_char(*tmp)){
      count++;
    }
    tmp=word_terminator(tmp);
    tmp=word_start(tmp);
  }
  return count;
}
char *copy_str(char *inStr, short len)
{
  char *copyStr = malloc(( len + 1) * sizeof(char));
  int i;

  for (i=0; i < len; i++){

    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;

}
char **tokenize(char *str)
{
  int size = count_words(str);
  char **tokens = malloc((size + 1) * sizeof(char *));
  int i;
  int length;
  char *p = str;
  for(i = 0; i < size; i++){
    p = word_start(p);
    char *f = word_start(p);
    char *e = word_terminator(p);
    tokens[i] = copy_str(p,e-f);
    p = word_terminator(p);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  int i=0;
  while(tokens[i])
    {
      printf("Token[%d] = %s\n", i, tokens[i]);
      i++;
    }
}
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
