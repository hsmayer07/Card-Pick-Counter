typedef struct Str {
	char *data;
	int size; 
} String_t;

typedef struct dataSet {
	String_t **names;
	int *counts;
	int size; 
} dataSet_t;

dataSet_t* inputreader(FILE*);
int ***cardpicker(dataSet_t*, int, int, int);
void writeoutput(int***, FILE*);