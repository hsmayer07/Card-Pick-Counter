typedef struct dataSet {
	char **names;
	int *counts;
} dataSet_t;

dataSet_t* inputreader(FILE*);
