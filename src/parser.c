#include "parser.h"
#include <stdlib.h>
#include <string.h>

// Create a parser
void create_parser(Parser *parser, Catcher *catcher, vector *tokens)
{
   parser->catcher = catcher;
   parser->tokens = tokens;
   parser->index = 0;
   init_expr_vector(&parser->exprs);
}

// Parse the tokens into an AST tree
void parse(Parser* parser)
{
   while (!is(parser, END_OF_FILE))
   {
      Expr* expr = parse_additive_expr(parser);
      push_back_vector(&parser->exprs.data, &expr);
   }
}

// Parse additive expression
Expr* parse_additive_expr(Parser* parser)
{
   Expr* left = parse_implicit_multiplication_expr(parser);

   while (is(parser, PLUS) || is(parser, MINUS))
   {
      TType op = current(parser)->type;
      advance(parser);

      Expr* right = parse_implicit_multiplication_expr(parser);
      left = (Expr*)new_binary_expr(left, op, right);
   }
   return left;
}

// Parse implicit multiplication expression
Expr* parse_implicit_multiplication_expr(Parser* parser)
{
   Expr* left = parse_multiplicative_expr(parser);
   
   while (is(parser, NUMBER) || is(parser, L_PAREN) || is(parser, FUNCTION) || is(parser, CONSTANT))
   {
      Expr* right = (is(parser, L_PAREN) ? parse_primary_expr(parser) : (is(parser, FUNCTION) ? parse_function_calls(parser) : parse_multiplicative_expr(parser)));
      left = (Expr*)new_binary_expr(left, STAR, right);
   }
   return left;
}

// Parse binary multiplication and division expressions
Expr* parse_multiplicative_expr(Parser* parser)
{
   Expr* left = parse_exponentiation_expr(parser);

   while (is(parser, STAR) || is(parser, SLASH))
   {
      TType op = current(parser)->type;
      advance(parser);

      Expr* right = parse_exponentiation_expr(parser);
      left = (Expr*)new_binary_expr(left, op, right);
   }
   return left;
}

// Parse binary exponentiation expressions
Expr* parse_exponentiation_expr(Parser* parser)
{
   Expr* left = parse_unary_expr(parser);

   while (is(parser, POWER))
   {
      advance(parser);
      Expr* right = parse_exponentiation_expr(parser);
      left = (Expr*)new_binary_expr(left, POWER, right);
   }
   return left;
}

// Parse unary expressions
Expr* parse_unary_expr(Parser* parser)
{
   if (is(parser, MINUS) || is(parser, PLUS))
   {
      TType op = current(parser)->type;
      advance(parser);

      return (Expr*)new_unary_expr(op, parse_percentage_expr(parser));
   }
   return parse_percentage_expr(parser);
}

// Parse percentage expressions
Expr* parse_percentage_expr(Parser* parser)
{
   Expr* value = parse_factorial_expr(parser);

   if (is(parser, PERCENT))
   {
      advance(parser);
      value = (Expr*)new_unary_expr(PERCENT, value);
   }
   return value;
}

// Parse factorial expressions
Expr* parse_factorial_expr(Parser* parser)
{
   Expr* value = parse_function_calls(parser);

   if (is(parser, BANG))
   {
      advance(parser);
      value = (Expr*)new_unary_expr(BANG, value);
   }
   return value;
}

// Parse function calls
Expr* parse_function_calls(Parser* parser)
{
   if (!is(parser, FUNCTION))
      return parse_primary_expr(parser);
   
   vector args;
   create_vector(&args, 2, sizeof(Expr*));
   char* name = current(parser)->lexeme;
   advance(parser);

   if (!is(parser, L_PAREN))
   {
      insert_catcher(parser->catcher, "Expected left parenthesis '(' after function call.");
      return NULL;
   }
   advance(parser);

   if (is(parser, R_PAREN))
   {
      advance(parser);
      return (Expr*)new_func_call_expr(name, &args);
   }

   Expr* value = parse_additive_expr(parser);
   push_back_vector(&args, &value);

   while (is(parser, COMMA))
   {
      advance(parser);
      value = parse_additive_expr(parser);
      push_back_vector(&args, &value);
   }

   if (!is(parser, R_PAREN))
      insert_catcher(parser->catcher, "Expected right parenthesis ')' to close function call.");
   
   advance(parser);
   return (Expr*)new_func_call_expr(name, &args);
}

// Parse types and parenthesis
Expr* parse_primary_expr(Parser* parser)
{
   if (is(parser, NUMBER))
   {
      char* endptr;
      long double number = strtod(current(parser)->lexeme, &endptr);
      advance(parser);

      if (*endptr != '\0')
      {
         insert_catcher(parser->catcher, "Could not convert string to number.");
         return NULL;
      }
      return (Expr*)new_number_literal(number);
   }
   else if (is(parser, CONSTANT))
   {
      char* lex = current(parser)->lexeme;
      advance(parser);

      if (!strcmp(lex, "e"))
         return (Expr*)new_number_literal(2.718281828459045);
      else if (!strcmp(lex, "pi"))
         return (Expr*)new_number_literal(3.141592653589793);
      else if (!strcmp(lex, "tau"))
         return (Expr*)new_number_literal(6.283185307179586);
      else if (!strcmp(lex, "phi"))
         return (Expr*)new_number_literal(1.618033988749895);
      else if (!strcmp(lex, "gamma"))
         return (Expr*)new_number_literal(0.577215664901532);
      else
         return (Expr*)new_number_literal(3.451726147100000);
   }
   else if (is(parser, L_PAREN))
   {
      advance(parser);
      Expr* value = parse_additive_expr(parser);

      if (!is(parser, R_PAREN))
         insert_catcher(parser->catcher, "Unclosed parenthesis.");
      
      advance(parser);
      return value;
   }
   else
   {
      insert_catcher(parser->catcher, "Expected a primary expression.");
      advance(parser);
      return NULL;
   }
}

// Get current token
Token* current(Parser* parser)
{
   return ((Token*)at_vector(parser->tokens, parser->index));
}

// Check if the current token is the given type
bool is(Parser *parser, TType type)
{
   return current(parser)->type == type;
}

// Advance the index by one
void advance(Parser *parser)
{
   if (parser->index + 1 < parser->tokens->size)
      ++parser->index;
}

// Free the parser
void free_parser(Parser *parser)
{
   free_expr_vector(&parser->exprs);
}
