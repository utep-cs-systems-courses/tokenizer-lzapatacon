#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


#define STRING_SIZE 100

int main()
{
  char userinput[STRING_SIZE], word[STRING_SIZE], word2[STRING_SIZE];
  char *p, *output, **tokenizer;
  int is_space, is_non_space, word_count, exit;



  List *test_list = init_history();
  exit = word_count = 0;
  p = &word[0];

  while(exit == 0)
    {
      printf("---------------------\nType word to tokenize, ![desired id number] to"

	     " view a specific existing word, or e to exit:\n");
      fgets(word, STRING_SIZE, stdin);
      if(word[0] == 'e')
	{
	  printf("Exiting\n");
	  exit = 1;
	  break;
	}
      else if(word[0] == '!')
	{
	  int index = word[1] - '0';
	  printf("History at [%c]: %s\n", word[1], get_history(test_list, index));
	}
      else
	{
	  printf("\nGiven phrase: %s\n", word);
	  output = word_start(word);

	  printf("Start of word: %c\n", *output);

	  output = word_terminator(word);
	  word_count = count_words(word);

	  printf("Number of words: %d\n", word_count);
	  // Return a copy of word from (0,len)given len.
	  output = copy_str(p, 4);
	  
	  //printing tokens
	  printf("New word copy: %s\n", output);
	  tokenizer = tokenize(word);
	  printf("tokens\n");
	  print_tokens(tokenizer);

	  //printf("Token[%d] = %s\n", 0, tokenizer[0]);
	  
	  
	  add_history(test_list, word);
   
	  //add_history(test_list, *tokenizer);
	  
	  printf("History\n");
	  
	  print_history(test_list);
	  printf("Enter second test sentence\n");
	  fgets(word2, 100, stdin);
	  add_history(test_list, word2);
	  print_history(test_list);

	  printf("History at %d, %s",2,get_history(test_list,2));
	  
	  free_tokens(tokenizer);
	}
    }
}
