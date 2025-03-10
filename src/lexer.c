#include "lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Create a new lexer
void create_lexer(Lexer* lexer, Catcher *catcher, char *source)
{
   lexer->catcher = catcher;
   lexer->source = source;

   // Tokens can only contain 16 characters
   create_vector(&lexer->tokens, 10, sizeof(TType) + 17);
}

// Tokenize the input
void tokenize(Lexer* lexer)
{
   size_t source_size = strlen(lexer->source);

   for (size_t index = 0; index < source_size; ++index)
   {
      char ch = lexer->source[index];
      
      if (isspace(ch))
         continue;

      if (ch == '+')
         push_back_token(lexer, PLUS, "+");
      else if (ch == '-')
         push_back_token(lexer, MINUS, "-");
      else if (ch == '*')
         push_back_token(lexer, STAR, "*");
      else if (ch == '/')
         push_back_token(lexer, SLASH, "/");
      else if (ch == '%')
         push_back_token(lexer, PERCENT, "%");
      else if (ch == '^')
         push_back_token(lexer, POWER, "^");
      else if (ch == '!')
         push_back_token(lexer, BANG, "!");
      else if (ch == ',')
         push_back_token(lexer, COMMA, ",");
      else if (ch == '(')
         push_back_token(lexer, L_PAREN, "(");
      else if (ch == ')')
         push_back_token(lexer, R_PAREN, ")");
      else if (isalpha(ch))
      {
         char* keyword = malloc(17);
         size_t keyword_index = 0;

         for (; index < source_size; ++index)
         {
            ch = lexer->source[index];

            if (!isalnum(ch))
            {
               --index;
               break;
            }
            keyword[keyword_index] = ch;
            ++keyword_index;
         }
         keyword[keyword_index] = '\0';

         if (keyword_index >= 17)
         {
            insert_catcher(lexer->catcher, "Keyword length cannot exceed 16 characters.");
            free(keyword);
            return;
         }

         bool found = false;

         for (size_t i = 0; i < constant_count; ++i)
         {
            if (!strcmp(keyword, constants[i]))
            {
               found = true;
               push_back_token(lexer, CONSTANT, keyword);
               break;
            }
         }

         if (found) continue;

         for (size_t i = 0; i < function_count; ++i)
         {
            if (!strcmp(keyword, functions[i]))
            {
               found = true;
               push_back_token(lexer, FUNCTION, keyword);
               break;
            }
         }

         if (!found)
         {
            insert_catcher(lexer->catcher, "Unknown keyword while lexing.");
            free(keyword);
            return;
         }
      }
      else if (isdigit(ch) || ch == '.')
      {
         char* number = malloc(17);
         size_t number_index = 0;
         bool floating  = false;
         bool lastQuote = false;

         for (; index < source_size; ++index)
         {
            ch = lexer->source[index];

            if (ch == '\'')
            {
               if (lastQuote || (index + 1 < source_size && (!isdigit(lexer->source[index + 1]) || lexer->source[index + 1] == '.')))
               {
                  insert_catcher(lexer->catcher, "Invalid quote placement in a number.");
                  free(number);
                  return;
               }
               lastQuote = true;
               continue;
            }
            lastQuote = false;

            if (ch == '.' && !floating)
            {
               floating = true;
               number[number_index] = ch;
               ++number_index;
               continue;
            }
            else if (ch == '.')
            {
               insert_catcher(lexer->catcher, "Invalid number with two or more commas.");
               free(number);
               return;
            }

            if (!isdigit(ch))
            {
               --index;
               break;
            }
            number[number_index] = ch;
            ++number_index;
         }
         number[number_index] = '\0';

         if (number_index >= 17)
         {
            insert_catcher(lexer->catcher, "Number length cannot exceed 16 characters.");
            free(number);
            return;
         }

         push_back_token(lexer, NUMBER, number);
      }
      else
         insert_catcher(lexer->catcher, "Unexpected character while lexing.");
   }
   push_back_token(lexer, END_OF_FILE, "eof");
}

// Push back a new token
void push_back_token(Lexer *lexer, TType type, char *lexeme)
{
   Token token;
   token.type = type;
   token.lexeme = lexeme;
   push_back_vector(&lexer->tokens, &token);
}

// Free the lexer
void free_lexer(Lexer *lexer)
{
   for (size_t i = 0; i < lexer->tokens.size; ++i)
   {
      Token* token = ((Token*)at_vector(&lexer->tokens, i));

      // Only number, function and constant types are allocated
      if (token->type == NUMBER || token->type == FUNCTION || token->type == CONSTANT)
      {
         free(token->lexeme);
         token->lexeme = NULL;
      }
   }
   free_vector(&lexer->tokens);
}
