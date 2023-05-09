#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "counter.h"


int ***cardpicker(dataSet_t* input, int numRounds, int numPlayers, int numCards) {
    int targetSize = input->size;
    printf("The target size is = %d \n", targetSize);
    int ***output = malloc(numRounds * sizeof(int *));
    if(output == NULL) {
        fprintf(stderr, "Fatal Memory Error! Terminating");
        exit(1);
    }

    int *roundCards = malloc(targetSize * sizeof(int));
    for(int i = 0; i < targetSize; i++) {
        *(roundCards + i) = input -> counts[i];
    }

    time_t t;

    srand((unsigned) time(&t));

    for(int i = 0; i < numRounds; i++) {
        output[i] = malloc(numPlayers * sizeof(int * ));
        if(output[i] == NULL) {
            fprintf(stderr, "Fatal Memory Error! Terminating");
            exit(1);
        }
        for(int j = 0; j < numPlayers; j++) {
            output[i][j] = malloc(targetSize * sizeof(int));
            if(output[i][j] == NULL) {
                fprintf(stderr, "Fatal Memory Error! Terminating");
                exit(1);
            }
            for(int k = 0; k < targetSize; k++) {
                output[i][j][k] = 0;
            }
        }
    }

    int index;
    for(int i = 0; i < numRounds; i++) {
        for(int j = 0; j < numPlayers; j++) {
            for(int k = 0; k < numCards; k++) {
                 while(roundCards[index = rand() % targetSize] <= 0) {
                    //Do something until we get a valid number
                 }
                printf("%d, %d, %d, Index = %d \n", i, j, k, index);
                roundCards[index]--;
                output[i][j][index]++; 
            }
        }
    }
    return output;
}