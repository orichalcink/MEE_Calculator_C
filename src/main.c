#include "evaluator.h"
#include "lexer.h"
#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Mathematical expression evaluator by chalcinxx, this time in C.
// This works very similarly to an interpreted programming language, but does
// not include any statements. I wasn't going for efficiency while writing
// this, as the calculator taking 1 millisecond longer does not change anything
// for me.
//
// User Input --> Lexer --> Parser --> Evaluator --> Result
//
// Firstly, the input is retrieved from the user.
// Secondly, the lexer converts the input into tokens and checks for any
// unknown characters and keywords.
// Thirdly, the parser reads through the tokens, produces an AST tree and
// checks if the syntax is valid. Any constants are parsed in this step.
// Lastly, the evaluator evaluates the AST tree step by step until it gets the
// final result. Any functions found are called in this tep.
//
// A great reference for creating an interpreted language in typescript, as I
// said before, a MEE is very similar to this:
// https://www.youtube.com/playlist?list=PL_2VhOvlMk4UHGqYCLWc6GO8FaPl8fQTh
//
// Original project in C++:
// https://github.com/orichalcink/MEE_Calculator

int main()
{
   // Seed random for randf and randi functions
   srand(time(NULL));

   printf("Terminal calculator with a mathematical expression evaluator rewritten in C.\n");
   Catcher catcher;
   create_catcher(&catcher);

   while (true)
   {
      // Get input from the user
      printf("> ");
      char command[250];
      fgets(command, sizeof(command), stdin);

      // Too much input
      if (command[strlen(command) - 1] != '\n')
      {
         insert_catcher(&catcher, "Input is too long, maximum is 249 characters.");
         display_catcher(&catcher);

         // Clear the input buffer
         int c;
         while ((c = getchar()) != '\n' && c != EOF);

         continue;
      }

      command[strlen(command) - 1] = '\0';

      // Quit the program
      if (!strcmp(command, "quit") || !strcmp(command, "exit"))
      {
         printf("Exiting...\n");
         free_catcher(&catcher);
         return 0;
      }

      // Tokenize the input
      Lexer lexer;
      create_lexer(&lexer, &catcher, command);
      tokenize(&lexer);

      if (display_catcher(&catcher))
      {
         free_lexer(&lexer);
         continue;
      }

      // Parse the tokens
      Parser parser;
      create_parser(&parser, &catcher, &lexer.tokens);
      parse(&parser);

      if (display_catcher(&catcher))
      {
         free_lexer(&lexer);
         free_parser(&parser);
         continue;
      }

      // Evaluate the result
      Evaluator evaluator;
      create_evaluator(&evaluator, &catcher, &parser.exprs);
      long double result = evaluate(&evaluator);

      if (display_catcher(&catcher))
      {
         free_lexer(&lexer);
         free_parser(&parser);
         continue;
      }

      // Print out the result if everything was successful
      printf("Result: %LF\n", result);

      // Clean up
      free_lexer(&lexer);
      free_parser(&parser);
   }
}