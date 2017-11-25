#include "pangram.h"
#include <string.h>
#include <ctype.h>


int is_pangram (const char* string) 
{
	int abcArry[26] = { 0 };
	size_t count = 0;

	if (string == NULL) { return 0; }
	if (strcmp(string, "") == 0) { return 0; }

	int stringlen = strlen(string);
	for (int i = 0; i < stringlen; i++) {
		char lowerChar = tolower(string[i]);
		if (lowerChar >= 'a' && lowerChar <= 'z') {
			if (!abcArry[lowerChar - 'a']) { 
				abcArry[lowerChar - 'a']++;
				count++;
			}
		}
		if (count == 26) { return 1; }
	}
	return 0;
}
