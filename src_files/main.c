#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "layer.h"
#include "printer.h"

int main(int argc, char** argv){
	struct patch *images; 
	struct patch field;
	int aaa,x,y;
	
		
	
	char ** names = (char**)malloc(sizeof(char) * 256);
	for(aaa = 0; aaa < 256; aaa++)
		names[aaa] = (char*)malloc(sizeof(char) * 256);
	images = (struct patch*)malloc(sizeof(patch) * 256);
		for(x = 0; x < 256; x++){
			images[x].image = (char**)malloc(sizeof(char)*256);
			for(y = 0; y < 256; y++)
				images[x].image[y] = (char*)malloc(sizeof(char)*256);
		}
		field.image = (char**)malloc(sizeof(char)*256);
		for(y = 0; y < 256; y++)
				field.image[y] = (char*)malloc(sizeof(char)*256);
	FILE *F;
	char* output;
	//void overlay(struct patch *images[], struct patch *field, char* input, int imagesSize){

	char ch;
	//void printer(struct patch *field, char* output, char* patches, char* commands){

	for(aaa = 0; aaa < (argc-1)/2; aaa++){
		initialize(images,argv[aaa+2],names, sizeof(images));
		for(x = 0; x < 10; x++){
			printf("patch%d: %d\n",x,images[x].x);
		}
		overlay(images, &field, argv[aaa+3],256);
		printer(&field,argv[1], argv[aaa+2], argv[aaa+3]);
		
	}
	printf("Cleanup");
	//for(x = 0;x < 256;x++)
			free(names[x]);
		//free(names);
		
		//for(x = 0;x<256;x++){
		//	free(images[x].image);
		//}//end for
		//free(images);
	return 0;
}

