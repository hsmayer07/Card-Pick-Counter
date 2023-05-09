#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

dataSet_t* inputreader(FILE* dataSource) {
	int count; 
	if(fscanf(dataSource, "%d\n", &count) != 1) {
		return NULL;
	}

	dataSet_t* inputData = malloc(sizeof(dataSet_t));
	if(inputData == NULL) {
		fprintf(stderr, "Fatal Memory Error! Terminating");
		exit(1);
	}

	inputData -> counts = malloc(count * sizeof(int));
	inputData -> size = count;
	if(inputData -> counts == NULL) {
		fprintf(stderr, "Fatal Memory Error! Terminating");
		exit(1);
	}

	inputData -> names = malloc(count *sizeof(char *));
	if(inputData -> names == NULL) {
		fprintf(stderr, "Fatal Memory Error! Terminating");
		exit(1);
	}

	int currentLength; 
	for(int i = 0; i < count; i++) {
		if(fscanf(dataSource, "%d ", &currentLength) != 1) {
			return NULL;
		}

		if(currentLength < 0 || currentLength > 20) {
			return NULL;
		}

		inputData -> names[i] = malloc(sizeof(String_t));

		if(inputData -> names[i] == NULL) {
			fprintf(stderr, "Fatal Memory Error! Terminating");
			exit(1);
		}

		inputData -> names[i] -> data = malloc(sizeof(char)*currentLength + 1);

		if(inputData -> names[i] == NULL) {
			fprintf(stderr, "Fatal Memory Error! Terminating");
			exit(1);
		}

		inputData -> names[i] -> size = currentLength+1;
		
		if(fscanf(dataSource, "%s ", inputData -> names[i] -> data ) != 1) {
			return NULL;
		}

		if(fscanf(dataSource, "%d\n", &(inputData -> counts[i])) != 1) {
			return NULL;
		}
	}

	return inputData;
}
