/**
 * James Little
 * Sept 1, 2017
 * GIS Week 1 Warm-Up Assignment
 *
 * Write a program to figure out how much memory (in bytes) the system
 * lets you allocate before malloc fails.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	size_t bytes = 1<<10; // Start with 1 KB
	int spec_depth = 10;
	int failed = 0; // boolean value
	
	// Stage 1: Find lsb
	while(!failed) {
		int *allocated = (int*)malloc(bytes);
		if(allocated == NULL) {
			failed = 1;
			
			// reset to last successful malloc
			bytes = bytes >> 1;
			spec_depth--;
		} else {			
			bytes = bytes<<1;
			spec_depth++;
		}
		
		free(allocated);
	}

	while(spec_depth > 0) {
		spec_depth--;
		size_t next_bit = 1 << spec_depth;
		size_t possible_bytes = bytes | next_bit;

		int *allocated = (int*)malloc(possible_bytes);
		if(allocated != NULL) {
			bytes = possible_bytes;
		}	

		free(allocated);
	} 

	printf("System can allocate %ld bytes.\n", bytes);
	printf("  = %.3f MB\n", (float)bytes/(1<<20));

	return EXIT_SUCCESS;
}
	
