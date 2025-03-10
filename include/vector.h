#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

// Define booleans
#ifndef bool
#define bool char
#define true 1
#define false 0
#endif

// Define a vector
typedef struct
{
   void* data;
   size_t element_size;
   size_t size;
   size_t capacity;
} vector;

// Create a new vector with the given capacity and element size
void create_vector(vector* vector, size_t capacity, size_t element_size);

// Retrieve an element
void* at_vector(vector* vector, size_t index);

// Push back an element
void push_back_vector(vector* vector, void* element);

// Check if the vector is empty
bool empty_vector(vector* vector);

// Clear everything from the vector
void clear_vector(vector* vector);

// Free the vector
void free_vector(vector* vector);

// Free a mallocated vector
void free_mallocated_vector(vector* vector);

#endif // VECTOR_H
