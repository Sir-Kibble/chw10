#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "layer.h"
#include "printer.h"

/******************************************************************
*****  Frame generated from Patches2.txt and Commands2.txt  *****
******************************************************************/

void printer(struct patch *field, char* output, char* patches, char* commands){
	FILE *Fi,*Fo;
	char line[1000];
	int x;
	
	//char * s = malloc(snprintf(NULL, 0, "%s %s", line, "\n") + 1);
	//sprintf(s, "%s%s", line, "\n");
	Fi = fopen(output,"r");
	Fo = fopen(output,"w");
	while(fgets(line, 1000, Fi) != NULL){
		fprintf(Fo, line);
	}//end while
	sprintf(line,"*****************************************************************\n***** Frame generated from %s and %s *****\n*****************************************************************\n",patches,commands);
	fprintf(Fo, line);
	for(x = 0; x < field->x; x++){
		//char * s = malloc(snprintf(NULL, 0, "%s %s", field->image[x], "\n") + 1);
		//sprintf(s, "%s%s", field->image[x], "\n");
		fprintf(Fo, "%s%s", field->image[x], "\n");
		//free(s);
	}//end for
	fclose(Fo);
	fclose(Fi);
}//end printer
