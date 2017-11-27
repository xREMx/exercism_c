#include "beer_song.h"
#include <stdio.h>
#include <string.h>


void verse (char* response, int line)
{
	if (line > 2) {
		sprintf(response, "%d bottles of beer on the wall, %d bottles of beer.\n", line, line);
		sprintf(response, "%sTake one down and pass it around, %d bottles of beer on the wall.\n", response, line - 1);
	}
	if (line == 2) {
		sprintf(response, "2 bottles of beer on the wall, 2 bottles of beer.\n");
		sprintf(response, "%sTake one down and pass it around, 1 bottle of beer on the wall.\n", response);
	}
	if (line == 1) {
		sprintf(response, "1 bottle of beer on the wall, 1 bottle of beer.\n");
		sprintf(response, "%sTake it down and pass it around, no more bottles of beer on the wall.\n", response);
	}
	if (line == 0) {
		sprintf(response, "No more bottles of beer on the wall, no more bottles of beer.\n");
		sprintf(response, "%sGo to the store and buy some more, 99 bottles of beer on the wall.\n", response);
	}

	return;
}


void sing (char* response, int line1, int line2) 
{
	char aVerse[1000];
	response[0] = '\0';
	while (line1 >= line2) {
		verse(aVerse, line1);
		sprintf(response, "%s%s\n",response , aVerse);
		--line1;
	}
	response[strlen(response) - 1] = '\0';  //remove last \n

	return;
}

