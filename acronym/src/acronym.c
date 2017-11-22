#include "acronym.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char* abbreviate (const char* phrase) 
{
	if (phrase == NULL) { return NULL; }
	if (strcmp(phrase, "") == 0) { return NULL; }

	char* token = (char*) malloc(strlen(phrase) * sizeof(char));
	strcpy(token, phrase);
	char* acro = (char*) calloc(10, sizeof(char));
	while ((token = strtok(token, " -")) != NULL) {
		sprintf(acro, "%s%c", acro, toupper(*token));
		token = NULL;
	}
	
	free(token);
	return acro;
}

