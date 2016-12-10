
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phone_book.h"

// Reads entire line until \n character
char* getLine();

// Reads entire line from file
char* getLineFromFile(FILE *fp);


// ***** WRAPPERS FOR RPC FUNCTIONS ***** //

// Wrapper function for adding an entry
void Add(entry *arg, CLIENT *clnt);

#endif