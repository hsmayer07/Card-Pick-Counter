#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

dataSet_t* inputreader(FILE* dataSource) {
	int count; 
	if(fscanf(dataSource, "%d\n", &count) != 1) {
		return NULL;
	}

	dataSet_t* inputData = malloc(sizeof(dataSet_t))m;
	if(inputData == NULL) {
		fprintf(stderr, "Fatal Malloc Error! Terminating");
		exit(1);
	}

	inputData -> counts = malloc(count * sizeof(int));
	if(inputData -> counts == NULL) {
		fprintf(stderr, "Fatal Malloc Error! Terminating");
		exit(1);
	}
	return inputData;
}
