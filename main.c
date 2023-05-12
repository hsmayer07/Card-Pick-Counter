#include <stdio.h>
#include <stdlib.h>
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
	int rounds, players, cards; 
	if(sscanf(argv[3], "%d", &rounds) != 1 || sscanf(argv[4], "%d", &players) != 1 || sscanf(argv[5], "%d", &cards) != 1) {
		fprintf(stderr, "One or more of the arguments you supplied were invalid.\n");
	}

	//printf("The total size is: %d \n", inputData -> size);
	int ***randCards = cardpicker(inputData, 3, 3, 9);
	FILE* output = fopen(argv[2], "w");
	if(output == NULL) {
		fprintf(stderr, "Error: The output file, %s, couldn't be opened. Please try again! \n", argv[2]);
	}

	/*for(int i = 0; i < 3; i++) {
		printf("\n Currently on round %d \n", i);
		for(int j = 0; j < 3; j ++) {
			printf("Player %d: ", j);
			for(int k = 0; k < 12; k++) {
				printf(" %d ", randCards[i][j][k]);
			}
		}
	}*/
	/*for(int i = 0; i < inputData->size; i++) {
		printf("%s ", inputData -> names[i] -> data);
		for(int j = 0; j < rounds; j++) {
			printf("%d ", randCards[i][j][0]);
		}
		printf("\n");
	}*/

	for(int i = 0; i < rounds; i++) {
		for(int j = 0; j < players; j++) {
			for(int k = 0; k < inputData -> size; k++) {
				printf("%d ", randCards[i][j][k]);
			}
			printf("\n");
		}
		printf("UwU \n");
	}
	printf("\n");
}
