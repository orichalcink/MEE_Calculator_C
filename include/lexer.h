#ifndef LEXER_H
#define LEXER_H

#include "catcher.h"
#include "tokens.h"

// Convert the user's input into tokens and check for any unexpected characters
typedef struct
{
   Catcher* catcher;
   char* source;
   vector tokens;
} Lexer;

// Constants and functions used in the lexer
static const size_t constant_count = 6;
static const size_t function_count = 42;

static char* constants[] = {"e", "pi", "tau", "phi", "gamma", "pie"};
static char* functions[] =
{
   "sin", "csc", "asin", "sinh", "asinh", "cos", "sec", "acos", "cosh",
   "acosh", "tan", "cot", "atan", "atan2", "tanh", "atanh", "pow", "sqrt",
   "cbrt", "exp", "ln", "log", "log2", "log10", "fact", "perm", "comb", "add",
   "sub", "mul", "div", "abs", "neg", "min", "max", "clamp", "floor", "ceil",
   "round", "rand", "randf", "randi"
};

// Create a new lexer
void create_lexer(Lexer* lexer, Catcher* catcher, char* source);

// Tokenize the input
void tokenize(Lexer* lexer);

// Push back a new token
void push_back_token(Lexer* lexer, TType type, char* lexeme);

// Free the lexer
void free_lexer(Lexer* lexer);

#endif // LEXER_H
