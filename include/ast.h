#ifndef AST_H
#define AST_H

#include "tokens.h"
#include "vector.h"

// Forward declarations
typedef struct Expr Expr;
typedef struct BinaryExpr BinaryExpr;
typedef struct UnaryExpr UnaryExpr;
typedef struct FunctionCallExpr FunctionCallExpr;
typedef struct NumberLiteral NumberLiteral;

// Expression types
typedef enum
{
   EXPR_BINARY,
   EXPR_UNARY,
   EXPR_FUNCTION,
   EXPR_NUMBER
} ExprType;

// Function pointers
typedef void (*ExprFreeFunc)(Expr*);

// Expression
struct Expr
{
   ExprType type;
   ExprFreeFunc free;
};

// Free an expression
void free_expr(Expr* expr);

// Binary expression with two values and a single operator
struct BinaryExpr
{
   Expr base;
   TType op;
   Expr* left;
   Expr* right;
};

// Free the binary expression
void free_binary_expr(Expr* expr);

// Create a new binary expression
BinaryExpr* new_binary_expr(Expr* left, TType op, Expr* right);

// Unary expression with a single value and operator
struct UnaryExpr
{
   Expr base;
   TType op;
   Expr* value;
};

// Free the unary expression
void free_unary_expr(Expr* expr);

// Create a new unary expression
UnaryExpr* new_unary_expr(TType op, Expr* expr);

// Function calls for calling functions
struct FunctionCallExpr
{
   Expr base;
   char* name;
   vector args;
};

// Free a function call
void free_func_call_expr(Expr* expr);

// Create a new function call expression
FunctionCallExpr* new_func_call_expr(char* name, vector* args);

// Number literal
struct NumberLiteral
{
   Expr base;
   long double value;
};

// Free a number literal
void free_number_literal(Expr* expr);

// Create a new number literal
NumberLiteral* new_number_literal(long double value);

// The AST tree node container
typedef struct
{
   vector data;
} ExprVector;

// Initialize the expression vector
void init_expr_vector(ExprVector* vector);

// Free the expression vector
void free_expr_vector(ExprVector* vector);

#endif // AST_H
