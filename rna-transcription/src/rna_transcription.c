#include "rna_transcription.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


char* to_rna (const char* dna) 
{
	size_t dnalen = strlen(dna);

	char* rna = (char*) malloc(dnalen * sizeof(char));
	rna[dnalen] = '\0';

	for (size_t index = 0; index < dnalen; ++index) {
		if (dna[index] == 'G') { rna[index] = 'C'; }
		else if (dna[index] == 'C') { rna[index] = 'G'; }
		else if (dna[index] == 'T') { rna[index] = 'A'; }
		else if (dna[index] == 'A') { rna[index] = 'U'; }
		else { return NULL; }
	}
	return rna;
}

