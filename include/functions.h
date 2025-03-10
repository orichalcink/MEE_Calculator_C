#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "catcher.h"

// Define a math function
typedef long double (*MathFunction)(Catcher*, vector*);

// Calculate sine
long double f_sin(Catcher* catcher, vector* vector);

// Calculate cosecant
long double f_csc(Catcher* catcher, vector* vector);

// Calculate arcsine
long double f_asin(Catcher* catcher, vector* vector);

// Calculate hyperbolic sine
long double f_sinh(Catcher* catcher, vector* vector);

// Calculate inverse hyperbolic sine
long double f_asinh(Catcher* catcher, vector* vector);

// Calculate cosine
long double f_cos(Catcher* catcher, vector* vector);

// Calculate secant
long double f_sec(Catcher* catcher, vector* vector);

// Calculate arccosine
long double f_acos(Catcher* catcher, vector* vector);

// Calculate hyperbolic cosine
long double f_cosh(Catcher* catcher, vector* vector);

// Calculate inverse hyperbolic cosine
long double f_acosh(Catcher* catcher, vector* vector);

// Calculate tangent
long double f_tan(Catcher* catcher, vector* vector);

// Calculate cotangent
long double f_cot(Catcher* catcher, vector* vector);

// Calculate arctangent
long double f_atan(Catcher* catcher, vector* vector);

// Calculate arctangent
long double f_atan2(Catcher* catcher, vector* vector);

// Calculate hyperbolic tangent
long double f_tanh(Catcher* catcher, vector* vector);

// Calculate inverse hyperbolic tangent
long double f_atanh(Catcher* catcher, vector* vector);

// Exponential function
long double f_exp(Catcher* catcher, vector* vector);

// Exponentiation
long double f_pow(Catcher* catcher, vector* vector);

// Calculate the square root
long double f_sqrt(Catcher* catcher, vector* vector);

// Calculate the cube root
long double f_cbrt(Catcher* catcher, vector* vector);

// Natural logarithm
long double f_ln(Catcher* catcher, vector* vector);

// Calculate Logarithm
long double f_log(Catcher* catcher, vector* vector);

// Logarithm base 2
long double f_log2(Catcher* catcher, vector* vector);

// Logarithm base10
long double f_log10(Catcher* catcher, vector* vector);

// Calculate factorial
long double f_fact(Catcher* catcher, vector* vector);

// Calculate permutation
long double f_perm(Catcher* catcher, vector* vector);

// Calculate combinations
long double f_comb(Catcher* catcher, vector* vector);

// Mass add numbers together
long double f_add(Catcher* catcher, vector* vector);

// Mass subtract numbers
long double f_sub(Catcher* catcher, vector* vector);

// Mass multiply numbers together
long double f_mul(Catcher* catcher, vector* vector);

// Mass divide numbers
long double f_div(Catcher* catcher, vector* vector);

// Get absolute value
long double f_abs(Catcher* catcher, vector* vector);

// Negate the number
long double f_neg(Catcher* catcher, vector* vector);

// Get the smallest number
long double f_min(Catcher* catcher, vector* vector);

// Get the largest number
long double f_max(Catcher* catcher, vector* vector);

// Clamp the number to the given values
long double f_clamp(Catcher* catcher, vector* vector);

// Round down
long double f_floor(Catcher* catcher, vector* vector);

// Round up
long double f_ceil(Catcher* catcher, vector* vector);

// Round to the nearest integer
long double f_round(Catcher* catcher, vector* vector);

// Get a random floating point number
long double f_randf(Catcher* catcher, vector* vector);

// Get a random integer
long double f_randi(Catcher* catcher, vector* vector);

// Define number of functions
#define MATH_FUNCTION_COUNT 42

// Define a map entry
typedef struct
{
   char* key;
   MathFunction func;
} MapEntry;

// Math function map
static MapEntry math_function_map[] =
{
   {"sin", f_sin}, {"csc", f_csc}, {"asin", f_asin}, {"sinh", f_sinh}, {"asinh", f_asinh},
   {"cos", f_cos}, {"sec", f_sec}, {"acos", f_acos}, {"cosh", f_cosh}, {"acosh", f_acosh},
   {"tan", f_tan}, {"cot", f_cot}, {"atan", f_atan}, {"atan2", f_atan2}, {"tanh", f_tanh}, {"atanh", f_atanh},
   {"pow", f_pow}, {"sqrt", f_sqrt}, {"cbrt", f_cbrt},
   {"exp", f_exp}, {"ln", f_ln}, {"log", f_log}, {"log2", f_log2}, {"log10", f_log10},
   {"fact", f_fact}, {"perm", f_perm}, {"comb", f_comb},
   {"add", f_add}, {"sub", f_sub}, {"mul", f_mul}, {"div", f_div}, {"abs", f_abs}, {"neg", f_neg},
   {"min", f_min}, {"max", f_max}, {"clamp", f_clamp}, {"floor", f_floor}, {"ceil", f_ceil}, {"round", f_round},
   {"rand", f_randf}, {"randf", f_randf}, {"randi", f_randi}
};

// Get a function from the map
MathFunction get_math_function(char* key);

#endif // FUNCTIONS_H
