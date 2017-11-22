#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "isogram.h"

int is_isogram (const char* string)
{
	int charAry[26] = {0};
	size_t length = strlen(string);

	for (size_t i = 0; i < length; i++) {
		char lowerChar = tolower(string[i]);
		if (lowerChar >= 'a' && lowerChar <= 'z') {
			if (charAry[lowerChar - 'a']) {
				return 0;
			}
			else {
				charAry[lowerChar - 'a']++;
			}
		}
	}

	return 1;
}
