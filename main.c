#include <stdio.h>
#include <stdlib.h>
#include "counter.h" 

int main(int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Error: You haven't entered a filename. Please try again!\n");
		return 1;
	} else if(argc == 2) {
		fprintf(stderr, "Error: You haven't entered an input and an output file. Please try again!\n");
		return 1;
	}

	FILE* input = fopen(argv[1], "r");
	if(input == NULL) {
		fprintf(stderr, "Error: The input file, %s, couldn't be opened. Please try again!\n", argv[1]);
		return 1; 
	}

	dataSet_t* inputData = inputreader(input);
	if(inputData == NULL) {
		fprintf(stderr, "Error: The input file, %s, contained a fatal formatting error. Please try again!\n", argv[1]);
	}
	printf("The total size is: %d \n", inputData -> size);
	for(int i = 0; i < inputData -> size; i++) {
		printf("Index %d is: %d and has the name %s \n", i, inputData -> counts[i], inputData -> names[i]);
	}
}
