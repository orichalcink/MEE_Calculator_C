#include "functions.h"
#include <stdlib.h>
#include <string.h> // IWYU pragma: export
#include <math.h>

//////////////////////////////////////////////////////////////////////////
// Sine
//////////////////////////////////////////////////////////////////////////

// Calculate sine
long double f_sin(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'sin' function, expected 1 argument.");
      return 0.0;
   }
   return sin(**(long double**)at_vector(vector, 0));
}

// Calculate cosecant
long double f_csc(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'csc' function, expected 1 argument.");
      return 0.0;
   }
   return 1.0 / sin(**(long double**)at_vector(vector, 0));
}

// Calculate arcsine
long double f_asin(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'asin' function, expected 1 argument.");
      return 0.0;
   }
   return asin(**(long double**)at_vector(vector, 0));
}

// Calculate hyperbolic sine
long double f_sinh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'sinh' function, expected 1 argument.");
      return 0.0;
   }
   return sinh(**(long double**)at_vector(vector, 0));
}

// Calculate inverse hyperbolic sine
long double f_asinh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'asinh' function, expected 1 argument.");
      return 0.0;
   }
   return asinh(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Cosine
//////////////////////////////////////////////////////////////////////////

// Calculate cosine
long double f_cos(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'cos' function, expected 1 argument.");
      return 0.0;
   }
   return cos(**(long double**)at_vector(vector, 0));
}

// Calculate secant
long double f_sec(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'sec' function, expected 1 argument.");
      return 0.0;
   }
   return 1.0 / cos(**(long double**)at_vector(vector, 0));
}

// Calculate arccosine
long double f_acos(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'acos' function, expected 1 argument.");
      return 0.0;
   }
   return acos(**(long double**)at_vector(vector, 0));
}

// Calculate hyperbolic cosine
long double f_cosh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'cosh' function, expected 1 argument.");
      return 0.0;
   }
   return cosh(**(long double**)at_vector(vector, 0));
}

// Calculate inverse hyperbolic cosine
long double f_acosh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'acosh' function, expected 1 argument.");
      return 0.0;
   }
   return acosh(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Tangent
//////////////////////////////////////////////////////////////////////////

// Calculate tangent
long double f_tan(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'tan' function, expected 1 argument.");
      return 0.0;
   }
   return tan(**(long double**)at_vector(vector, 0));
}

// Calculate cotangent
long double f_cot(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'cot' function, expected 1 argument.");
      return 0.0;
   }
   return 1.0 / tan(**(long double**)at_vector(vector, 0));
}

// Calculate arctangent
long double f_atan(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'atan' function, expected 1 argument.");
      return 0.0;
   }
   return atan(**(long double**)at_vector(vector, 0));
}

// Calculate arctangent
long double f_atan2(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'atan2' function, expected 2 arguments.");
      return 0.0;
   }
   return atan2(**(long double**)at_vector(vector, 0), **(long double**)at_vector(vector, 1));
}

// Calculate hyperbolic tangent
long double f_tanh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'tanh' function, expected 1 argument.");
      return 0.0;
   }
   return tanh(**(long double**)at_vector(vector, 0));
}

// Calculate inverse hyperbolic tangent
long double f_atanh(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'atanh' function, expected 1 argument.");
      return 0.0;
   }
   return atanh(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Power and Root
//////////////////////////////////////////////////////////////////////////

// Exponential function
long double f_exp(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'exp' function, expected 1 argument.");
      return 0.0;
   }
   return exp(**(long double**)at_vector(vector, 0));
}

// Exponentiation
long double f_pow(Catcher* catcher, vector* vector)
{
   if (vector->size != 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'pow' function, expected 2 arguments.");
      return 0.0;
   }
   return pow(**(long double**)at_vector(vector, 0), **(long double**)at_vector(vector, 1));
}

// Calculate the square root
long double f_sqrt(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'sqrt' function, expected 1 argument.");
      return 0.0;
   }
   if (**(long double**)at_vector(vector, 0) < 0.0)
   {
      insert_catcher(catcher, "Cannot calculate the square root of a negative number.");
      return 0.0;
   }
   return sqrt(**(long double**)at_vector(vector, 0));
}

// Calculate the cube root
long double f_cbrt(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'cbrt' function, expected 1 argument.");
      return 0.0;
   }
   if (**(long double**)at_vector(vector, 0) < 0.0)
   {
      insert_catcher(catcher, "Cannot calculate the cube root of a negative number.");
      return 0.0;
   }
   return cbrt(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Logarithmic
//////////////////////////////////////////////////////////////////////////

// Natural logarithm
long double f_ln(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'ln' function, expected 1 argument.");
      return 0.0;
   }
   return log(**(long double**)at_vector(vector, 0));
}

// Calculate Logarithm
long double f_log(Catcher* catcher, vector* vector)
{
   if (vector->size != 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'log' function, expected 2 arguments.");
      return 0.0;
   }
   if (**(long double**)at_vector(vector, 0) == 0.0)
   {
      insert_catcher(catcher, "Log(0, b) is undefined.");
      return 0.0;
   }
   if (**(long double**)at_vector(vector, 1))
   {
      insert_catcher(catcher, "Log(x, 1) is undefined.");
      return 0.0;
   }
   return log(**(long double**)at_vector(vector, 0)) / log(**(long double**)at_vector(vector, 1));
}

// Logarithm base 2
long double f_log2(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'log2' function, expected 1 argument.");
      return 0.0;
   }
   return log2(**(long double**)at_vector(vector, 0));
}

// Logarithm base10
long double f_log10(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'log10' function, expected 1 argument.");
      return 0.0;
   }
   return log10(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Factorial
//////////////////////////////////////////////////////////////////////////

// Calculate factorial
long double f_fact(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'fact' function, expected 1 argument.");
      return 0.0;
   }
   return tgamma(**(long double**)at_vector(vector, 0) + 1);
}

// Calculate permutation
long double f_perm(Catcher* catcher, vector* vector)
{
   if (vector->size != 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'perm' function, expected 2 arguments.");
      return 0.0;
   }
   long double n = **(long double**)at_vector(vector, 0);
   long double k = **(long double**)at_vector(vector, 1);
   return tgamma(n + 1) / tgamma((n - k) + 1);
}

// Calculate combinations
long double f_comb(Catcher* catcher, vector* vector)
{
   if (vector->size != 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'comb' function, expected 2 arguments.");
      return 0.0;
   }
   long double n = **(long double**)at_vector(vector, 0);
   long double k = **(long double**)at_vector(vector, 1);
   return tgamma(n + 1) / (tgamma(k + 1) * tgamma((n - k) + 1));
}

//////////////////////////////////////////////////////////////////////////
// Utility
//////////////////////////////////////////////////////////////////////////

// Mass add numbers together
long double f_add(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'add' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double result = **(long double**)at_vector(vector, 0);

   for (size_t i = 1; i < vector->size; ++i)
      result += **(long double**)at_vector(vector, i);
   return result;
}

// Mass subtract numbers
long double f_sub(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'sub' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double result = **(long double**)at_vector(vector, 0);

   for (size_t i = 1; i < vector->size; ++i)
      result -= **(long double**)at_vector(vector, i);
   return result;
}

// Mass multiply numbers together
long double f_mul(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'mul' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double result = **(long double**)at_vector(vector, 0);

   for (size_t i = 1; i < vector->size; ++i)
      result *= **(long double**)at_vector(vector, i);
   return result;
}

// Mass divide numbers
long double f_div(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'div' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double result = **(long double**)at_vector(vector, 0);

   for (size_t i = 1; i < vector->size; ++i)
   {
      long double arg = **(long double**)at_vector(vector, i);
      if (arg == 0.0)
      {
         insert_catcher(catcher, "Division by zero is undefined.");
         return 0.0;
      }
      result /= arg;
   }
   return result;
}

// Get absolute value
long double f_abs(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'abs' function, expected 1 argument.");
      return 0.0;
   }
   long double arg = **(long double**)at_vector(vector, 0);
   return (arg < 0.0 ? -arg : arg);
}

// Negate the number
long double f_neg(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'neg' function, expected 1 argument.");
      return 0.0;
   }
   return -**(long double**)at_vector(vector, 0);
}

// Get the smallest number
long double f_min(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'min' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double smallest = 99999999999999999; // Hacky. The lexer does not allow numbers bigger than 16 characters.

   for (size_t i = 0; i < vector->size; ++i)
      if (**(long double**)at_vector(vector, i) < smallest)
         smallest = **(long double**)at_vector(vector, i);
   return smallest;
}

// Get the largest number
long double f_max(Catcher* catcher, vector* vector)
{
   if (vector->size < 2)
   {
      insert_catcher(catcher, "Invalid argument count in 'max' function, expected atleast 2 arguments.");
      return 0.0;
   }
   long double largest = -99999999999999999; // Hacky. The lexer does not allow numbers bigger than 16 characters.

   for (size_t i = 0; i < vector->size; ++i)
      if (**(long double**)at_vector(vector, i) > largest)
         largest = **(long double**)at_vector(vector, i);
   return largest;
}

// Clamp the number to the given values
long double f_clamp(Catcher* catcher, vector* vector)
{
   if (vector->size != 3)
   {
      insert_catcher(catcher, "Invalid argument count in 'clamp' function, expected 3 arguments.");
      return 0.0;
   }
   long double arg = **(long double**)at_vector(vector, 0);
   long double min = **(long double**)at_vector(vector, 1);
   long double max = **(long double**)at_vector(vector, 2);
   return (arg < min ? min : (arg > max ? max : arg));
}

// Round down
long double f_floor(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'floor' function, expected 1 argument.");
      return 0.0;
   }
   return floor(**(long double**)at_vector(vector, 0));
}

// Round up
long double f_ceil(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'ceil' function, expected 1 argument.");
      return 0.0;
   }
   return ceil(**(long double**)at_vector(vector, 0));
}

// Round to the nearest integer
long double f_round(Catcher* catcher, vector* vector)
{
   if (vector->size != 1)
   {
      insert_catcher(catcher, "Invalid argument count in 'round' function, expected 1 argument.");
      return 0.0;
   }
   return round(**(long double**)at_vector(vector, 0));
}

//////////////////////////////////////////////////////////////////////////
// Random
//////////////////////////////////////////////////////////////////////////

// Get a random floating point number
long double f_randf(Catcher* catcher, vector* vector)
{
   if (vector->size != 2 && vector->size != 0)
   {
      insert_catcher(catcher, "Invalid argument count in 'randf' function, expected either 2 or no arguments.");
      return 0.0;
   }

   if (vector->size == 0)
      return (long double)rand() / (long double)RAND_MAX;
   else
   {
      long double min = **(long double**)at_vector(vector, 0);
      long double max = **(long double**)at_vector(vector, 1);
      return min + (long double)rand() / (long double)(RAND_MAX / (max - min));
   }
}

// Get a random integer
long double f_randi(Catcher* catcher, vector* vector)
{
   if (vector->size != 2 && vector->size != 0)
   {
      insert_catcher(catcher, "Invalid argument count in 'randi' function, expected either 2 or no arguments.");
      return 0.0;
   }

   if (vector->size == 0)
      return rand() % 2;
   else
   {
      long long min = **(long double**)at_vector(vector, 0);
      long long max = **(long double**)at_vector(vector, 1);
      return min + (rand() % (max - min + 1));
   }
}

// Get a math function
MathFunction get_math_function(char *key)
{
   for (int i = 0; i < MATH_FUNCTION_COUNT; ++i)
      if (!strcmp(math_function_map[i].key, key))
         return math_function_map[i].func;
   return NULL;
}
