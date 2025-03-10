#include "vector.h"
#include <stdlib.h>
#include <string.h>

// Create a new vector
void create_vector(vector *vector, size_t capacity, size_t element_size)
{
   // Allocate memory in bytes
   vector->data = malloc(capacity * element_size);
   vector->capacity = capacity;
   vector->element_size = element_size;
   vector->size = 0;
}

// Get an element
void* at_vector(vector* vector, size_t index)
{
   if (index >= vector->size)
      return NULL;
   return (char*)vector->data + index * vector->element_size;
}

// Push back an element
void push_back_vector(vector* vector, void* element)
{
   // Resize the vector if there are too many elements
   if (vector->size >= vector->capacity)
   {
      vector->capacity += (vector->capacity ? vector->capacity : 1);
      void* new_data = realloc(vector->data, vector->capacity * vector->element_size);

      if (!new_data)
      {
         printf("Vector memory reallocation failed.\n");
         exit(1);
      }
      vector->data = new_data;
   }
   memcpy((char*)vector->data + vector->size * vector->element_size, element, vector->element_size);
   ++vector->size;
}

// Check if the vector is empty
bool empty_vector(vector* vector)
{
   return vector->size == 0;
}

// Clear the vector
void clear_vector(vector* vector)
{
   vector->size = 0;
}

// Free the vector, the pointers have to be freed manually
void free_vector(vector* vector)
{
   if (vector->data)
      free(vector->data);
   vector->data = NULL;
   vector->size = vector->element_size = vector->capacity = 0;
}

// Free a mallocated vector
void free_mallocated_vector(vector *vector)
{
   if (vector->data)
   {
      for (size_t i = 0; i < vector->size; ++i)
      {
         void* ptr = (char*)vector->data + i * vector->element_size;
         if (ptr && *((void**)ptr))
            free(*((void**)ptr));
      }

      free(vector->data);
   }
   vector->data = NULL;
   vector->size = vector->element_size = vector->capacity = 0;
}
