#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "counter.h" 

int main(int argc, char* argv[]) {
	
	if(argc < 6) {
		fprintf(stderr, "Error: You haven't specified enough arguments. You must specify, in order, the input file, the output file, the number of rounds, the number of players, and the number of cards per round. \n");
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
	fclose(input);
	int games, rounds, players, cards; 
	if(sscanf(argv[3], "%d", &games) != 1 || sscanf(argv[4], "%d", &rounds) != 1 || sscanf(argv[5], "%d", &players) != 1 || sscanf(argv[6], "%d", &cards) != 1) {
		fprintf(stderr, "One or more of the arguments you supplied were invalid.\n");
	}

    time_t t;

    srand((unsigned) time(&t));

	//printf("The total size is: %d \n", inputData -> size);
	int ****randCards; //= cardpicker(inputData, rounds, players, cards);
	randCards = (int ****) malloc(games * sizeof(int *));
	for(int i = 0; i < games; i++) {
		randCards[i] = cardpicker(inputData, rounds, players, cards);
	}

	printf("UWU \n\n\n");
	FILE* output = fopen(argv[2], "w");
	if(output == NULL) {
		fprintf(stderr, "Error: The output file, %s, couldn't be opened. Please try again! \n", argv[2]);
	}

	int *cumulativeCounts = malloc(sizeof(int) * inputData -> size);
	for(int i = 0; i < inputData -> size; i++) {
		cumulativeCounts[i] = 0;
	}
	//Output the data correctly + in order.
	for(int z = 0; z < games; z++) {
		fprintf(output, "GAME %d\n", (z +1));
		for(int i = 0; i < rounds; i++) {
			fprintf(output, "Round %d,", i+1);
			for(int j = 0; j < players; j++) {
				fprintf(output, "Player %d,", j+1);
			}
		}
		fprintf(output, "\n");
		for(int i = 0; i < inputData -> size; i++) {
			for(int j = 0; j < players; j++) {
				fprintf(output, "%s,", inputData -> names[i] -> data);
				for(int k = 0; k < rounds; k++) {
					fprintf(output, "%d,", randCards[z][k][j][i]);
					cumulativeCounts[i] += randCards[z][k][j][i];
				}
			}
			fprintf(output, "\n");
		}
	}

	fprintf(output, "\nSums=\n");
	for(int i = 0; i < inputData -> size; i++) {
		fprintf(output, "%s,", inputData -> names[i] -> data);
		fprintf(output, "%d\n", cumulativeCounts[i]);
	}
	fclose(output);
	
}
