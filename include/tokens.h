#ifndef TOKENS_H
#define TOKENS_H

// Token types
typedef enum
{
   NUMBER, CONSTANT, FUNCTION, PLUS, MINUS, STAR, SLASH, PERCENT, POWER, BANG,
   COMMA, L_PAREN, R_PAREN, END_OF_FILE
} TType;

// Tokens used in the parser
typedef struct
{
   TType type;
   char* lexeme;
} Token;

#endif // TOKENS_H
