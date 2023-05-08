typedef struct dataSet {
	char **names;
	int *counts;
	int size; 
} dataSet_t;

dataSet_t* inputreader(FILE*);
