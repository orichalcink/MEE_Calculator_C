#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "catcher.h"

// Parse the tokens into an AST tree and check for valid syntax
typedef struct
{
   Catcher* catcher;
   vector* tokens;
   ExprVector exprs;
   size_t index;
} Parser;

// Create a new parser
void create_parser(Parser* parser, Catcher* catcher, vector* tokens);

// Parse the tokens
void parse(Parser* parser);

// Parse binary plus and minus expressions
Expr* parse_additive_expr(Parser* parser);

// Parse implicit multiplication expression
Expr* parse_implicit_multiplication_expr(Parser* parser);

// Parse binary multiplication and division expressions
Expr* parse_multiplicative_expr(Parser* parser);

// Parse binary exponentiation expressions
Expr* parse_exponentiation_expr(Parser* parser);

// Parse unary expressions
Expr* parse_unary_expr(Parser* parser);

// Parse percentage expressions
Expr* parse_percentage_expr(Parser* parser);

// Parse factorial expressions
Expr* parse_factorial_expr(Parser* parser);

// Parse function calls
Expr* parse_function_calls(Parser* parser);

// Parse types and parenthesis
Expr* parse_primary_expr(Parser* parser);

// Get current token
Token* current(Parser* parser);

// Check if the current token is the given type
bool is(Parser* parser, TType type);

// Advance the index
void advance(Parser* parser);

// Free the parser
void free_parser(Parser* parser);

#endif // PARSER_H
