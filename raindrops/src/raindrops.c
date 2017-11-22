#include "raindrops.h"
#include <stdio.h>
#include <string.h>


void convert (char result[], int drops)
{
	for (int i = 1; i <= drops; i++) {
		if (drops % i == 0) {
			if (i == 3) { sprintf(result, "%s%s", result, "Pling"); }
			if (i == 5) { sprintf(result, "%s%s", result, "Plang"); }
			if (i == 7) { sprintf(result, "%s%s", result, "Plong"); }
		}
	}

	if (strcmp(result, "") == 0) { sprintf(result, "%d", drops); }

	return;
}
