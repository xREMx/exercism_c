#include "acronym.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char* abbreviate (const char* phrase) 
{
	if (phrase == NULL) { return NULL; }
	if (strcmp(phrase, "") == 0) { return NULL; }

	char* token = strdup(phrase);
	char* acro = (char*) calloc(10, sizeof(char));

	char* pAcro = acro;
	while ((token = strtok(token, " -")) != NULL) {
		if (pAcro - acro < 10) { 
			*pAcro = toupper(*token);
			++pAcro;
		}
		token = NULL;
	}
	
	free(token);
	return acro;
}
