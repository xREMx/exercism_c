#include "bob.h"
#include <string.h>
#include <ctype.h>


char* hey_bob (const char* text) 
{
	const char* end = text + strlen(text) - 1;
	while (end > text && isspace(*end)) { end--; }

	if (text >= end) { return "Fine. Be that way!"; }

	int textlen = end - text;
	int yell = 0;
	for (int i = 0; i < textlen; i++) {
		if (text[i] >= 'a' && text[i] <= 'z') { 
			yell = 0;
			break; 
		}
		if (text[i] >= 'A' && text[i] <= 'Z') { yell = 1; }
	}

	if (yell) { return "Whoa, chill out!"; }

	if (strrchr(text, '?') == end) { return "Sure."; }

	return "Whatever.";
}
