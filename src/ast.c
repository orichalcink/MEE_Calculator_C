#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

// Free an expression
void free_expr(Expr* expr)
{
   if (expr && expr->free)
      expr->free(expr);
}

// Free the binary expression
void free_binary_expr(Expr *expr)
{
   BinaryExpr* bin = (BinaryExpr*)expr;
   if (bin->left)  free_expr(bin->left);
   if (bin->right) free_expr(bin->right);
   free(bin);
}

// Create a new binary expression
BinaryExpr* new_binary_expr(Expr* left, TType op, Expr* right)
{
   BinaryExpr* bin = malloc(sizeof(BinaryExpr));
   if (!bin) return NULL;

   bin->base.type = EXPR_BINARY;
   bin->base.free = free_binary_expr;
   bin->op = op;
   bin->left = left;
   bin->right = right;
   return bin;
}

// Free the unary expression
void free_unary_expr(Expr *expr)
{
   UnaryExpr* unary = (UnaryExpr*)expr;
   if (unary->value) free_expr(unary->value);
   free(unary);
}

// Create a new unary expression
UnaryExpr* new_unary_expr(TType op, Expr* value)
{
   UnaryExpr* unary = malloc(sizeof(UnaryExpr));
   if (!unary) return NULL;

   unary->base.type = EXPR_UNARY;
   unary->base.free = free_unary_expr;
   unary->op = op;
   unary->value = value;
   return unary;
}

// Free a function call
void free_func_call_expr(Expr *expr)
{
   FunctionCallExpr* call = (FunctionCallExpr*)expr;
   for (size_t i = 0; i < call->args.size; ++i)
   {
      Expr* expr = *(Expr**)at_vector(&call->args, i);
      free_expr(expr);
   }
   free_vector(&call->args);
   free(call);
}

// Create a new function call expression
FunctionCallExpr* new_func_call_expr(char* name, vector* args)
{
   FunctionCallExpr* call = malloc(sizeof(FunctionCallExpr));
   if (!call) return NULL;

   call->base.type = EXPR_FUNCTION;
   call->base.free = free_func_call_expr;
   call->name = name;
   call->args = *args;
   return call;
}

// Free a number literal
void free_number_literal(Expr *expr)
{
   if (expr) free((NumberLiteral*)expr);
}

// Create a new number literal
NumberLiteral* new_number_literal(long double value)
{
   NumberLiteral* number = malloc(sizeof(NumberLiteral));
   if (!number) return NULL;

   number->base.type = EXPR_NUMBER;
   number->base.free = free_number_literal;
   number->value = value;
   return number;
}

// Create a new expression vector
void init_expr_vector(ExprVector *vector)
{
   create_vector(&vector->data, 5, sizeof(Expr*));
}

// Free the expression vector
void free_expr_vector(ExprVector *vector)
{
   for (size_t i = 0; i < vector->data.size; ++i)
   {
      Expr* expr = *(Expr**)at_vector(&vector->data, i);
      free_expr(expr);
   }
   free_vector(&vector->data);
}
