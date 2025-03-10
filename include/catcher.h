#ifndef CATCHER_H
#define CATCHER_H

#include "vector.h"

// Catcher and display errors
typedef struct
{
   vector errors;
} Catcher;

// Create a new catcher
void create_catcher(Catcher* catcher);

// Insert an error into the catcher
void insert_catcher(Catcher* catcher, char* error);

// Check if there are any errors
bool any_errors_catcher(Catcher* catcher);

// Display all errors if there are any
bool display_catcher(Catcher* catcher);

// Free the catcher
void free_catcher(Catcher* catcher);

#endif // CATCHER_H
