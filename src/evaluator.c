#include "evaluator.h"
#include "functions.h"
#include <math.h>
#include <stdlib.h>

// Create a new evaluator
void create_evaluator(Evaluator *evaluator, Catcher *catcher, ExprVector *program)
{
   evaluator->catcher = catcher;
   evaluator->program = program;
}

// Evaluate an AST tree
long double evaluate(Evaluator* evaluator)
{
   long double result = 0.0;

   for (size_t i = 0; i < evaluator->program->data.size; ++i)
   {
      Expr* expr = *(Expr**)at_vector(&evaluator->program->data, i);
      result = evaluate_expr(evaluator, expr);
   }
   return result;
}

// Evaluate an expression
long double evaluate_expr(Evaluator *evaluator, Expr *expr)
{
   switch (expr->type)
   {
   case EXPR_FUNCTION:
      return evaluate_function_expr(evaluator, expr);
   case EXPR_BINARY:
      return evaluate_binary_expr(evaluator, expr);
   case EXPR_UNARY:
      return evaluate_unary_expr(evaluator, expr);
   case EXPR_NUMBER:
      return ((NumberLiteral*)expr)->value;
   }
}

// Evaluate a function call
long double evaluate_function_expr(Evaluator *evaluator, Expr *expr)
{
   FunctionCallExpr* func = (FunctionCallExpr*)expr;
   vector args;
   create_vector(&args, 2, sizeof(long double*));

   for (size_t i = 0; i < func->args.size; ++i)
   {
      long double* value = malloc(sizeof(long double));
      *value = evaluate_expr(evaluator, *(Expr**)at_vector(&func->args, i));
      push_back_vector(&args, &value);
   }

   MathFunction callable = get_math_function(func->name);
   long double result = 0.0;

   if (callable)
      result = callable(evaluator->catcher, &args);
   else
      insert_catcher(evaluator->catcher, "Unexpected function while evaluating.");

   free_mallocated_vector(&args);
   return result;
}

// Evaluate a binary expression
long double evaluate_binary_expr(Evaluator *evaluator, Expr *expr)
{
   BinaryExpr* binary = (BinaryExpr*)expr;

   switch (binary->op)
   {
   case PLUS:
      return evaluate_expr(evaluator, binary->left) + evaluate_expr(evaluator, binary->right);
   case MINUS:
      return evaluate_expr(evaluator, binary->left) - evaluate_expr(evaluator, binary->right);
   case STAR:
      return evaluate_expr(evaluator, binary->left) * evaluate_expr(evaluator, binary->right);
   case SLASH:
   {
      long double right = evaluate_expr(evaluator, binary->right);
      if (right == 0.0)
      {
         insert_catcher(evaluator->catcher, "Division by zero is undefined.");
         return 0.0;
      }
      return evaluate_expr(evaluator, binary->left) / right;
   }
   case POWER:
      return pow(evaluate_expr(evaluator, binary->left), evaluate_expr(evaluator, binary->right));
   default:
      insert_catcher(evaluator->catcher, "Unsupported binary operator while evaluating.");
      return 0.0;
   }
}

// Evaluate an unary expression
long double evaluate_unary_expr(Evaluator *evaluator, Expr *expr)
{
   UnaryExpr* unary = (UnaryExpr*)expr;

   switch (unary->op)
   {
   case PLUS:
      return +evaluate_expr(evaluator, unary->value);
   case MINUS:
      return -evaluate_expr(evaluator, unary->value);
   case PERCENT:
      return evaluate_expr(evaluator, unary->value) * .01;
   case BANG:
      return tgammal(evaluate_expr(evaluator, unary->value) + 1);
   default:
      insert_catcher(evaluator->catcher, "Unsupported unary operator while evaluating.");
      return 0.0;
   }
}
