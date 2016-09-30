#include <stdlib.h>
typedef patch;
//typedef struct patch
struct patch{
    char ** image;
	int x;
	int y;
	char* name;
};

void overlay(struct patch image[], struct patch *field, char* input, int imagesSize);
void initialize(struct patch images[], char* input, char** names, int namesSize);

