#include "catcher.h"
#include <stdlib.h>
#include <string.h>

// Create a new catcher
void create_catcher(Catcher *catcher)
{
   create_vector(&catcher->errors, 5, 150);
}

// Insert an error into the catcher
void insert_catcher(Catcher *catcher, char *error)
{
   // Errors cannot exceed 149 characters
   if (strlen(error) >= 150)
   {
      printf("Cannot insert an error longer than 150 characters into the catcher.\n");
      exit(1);
   }
   push_back_vector(&catcher->errors, error);
}

// Check if there are any errors
bool any_errors_catcher(Catcher *catcher)
{
   return !empty_vector(&catcher->errors);
}

// Display all errors if there are any
bool display_catcher(Catcher *catcher)
{
   if (empty_vector(&catcher->errors))
      return false;
   
   printf("\n%zu error%c occurred:\n", catcher->errors.size, (catcher->errors.size == 1 ? 0 : 's'));
   for (size_t i = 0; i < catcher->errors.size; ++i)
      printf("%s\n", (char*)at_vector(&catcher->errors, i));
   
   clear_vector(&catcher->errors);
   printf("\n");
   return true;
}

// Free the catcher
void free_catcher(Catcher *catcher)
{
   for (size_t i = 0; i < catcher->errors.size; ++i)
   {
      void* ptr = at_vector(&catcher->errors, i);
      if (ptr) free(ptr);
   }
   free_vector(&catcher->errors);
}
