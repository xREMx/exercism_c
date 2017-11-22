#include "bob.h"
#include <string.h>
#include <ctype.h>


char* hey_bob (const char* text) 
{
	char* end = text + strlen(text) - 1;
	while (end > text && isspace(*end)) { end--; }
	*(end + 1) = '\0';

	if (strcmp(text, "") == 0) { return "Fine. BE that way!"; }

	int textlen = strlen(text);
	int yell = 0;
	for (int i = 0; i < textlen; i++) {
		if (text[i] >= 'a' && text[i] <= 'z') { 
			yell = 0;
			break; 
		}
		if (text[i] >= 'A' && text[i] <= 'Z') { yell = 1; }
	}

	if (yell) { return "Whoa, chill out!"; }

	if (strrchr(text, '?') == text + textlen - 1) { return "Sure."; }

	return "Whatever.";
}
