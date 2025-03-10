#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "ast.h"
#include "catcher.h"

// Evaluate the AST tree and return the result
typedef struct
{
   Catcher* catcher;
   ExprVector* program;
} Evaluator;

// Create a new evaluator
void create_evaluator(Evaluator* evaluator, Catcher* catcher, ExprVector* program);

// Evaluate the AST tree
long double evaluate(Evaluator* evaluator);

// Evaluate an expression
long double evaluate_expr(Evaluator* evaluator, Expr* expr);

// Evaluate a function call expressions
long double evaluate_function_expr(Evaluator* evaluator, Expr* expr);

// Evaluate a binary expression
long double evaluate_binary_expr(Evaluator* evaluator, Expr* expr);

// Evaluate an unary expression
long double evaluate_unary_expr(Evaluator* evaluator, Expr* expr);

#endif // EVALUATOR_H
