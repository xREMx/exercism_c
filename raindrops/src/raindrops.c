#include "raindrops.h"
#include <stdio.h>
#include <string.h>


void convert (char result[], int drops)
{
	if (drops % 3 == 0) { sprintf(result, "%s%s", result, "Pling"); }
	if (drops % 5 == 0) { sprintf(result, "%s%s", result, "Plang"); }
	if (drops % 7 == 0) { sprintf(result, "%s%s", result, "Plong"); }

	if (strcmp(result, "") == 0) { sprintf(result, "%d", drops); }

	return;
}
