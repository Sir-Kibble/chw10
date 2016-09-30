#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "layer.h"

void overlay(struct patch *images, struct patch *field, char* input, int imagesSize){
	FILE *F;
	char line[1000], *p,*name;
	int x,y,z,xoffset,yoffset,framex,framey;
	x = 0;
	y = 0;
	z = 0;
	F = fopen(input,"r");
	if(F == NULL)
		return;
	fgets(line, 1000, F);
	field->x = strtol(strtok(line," "),&p,10);
	field->y = strtol(strtok(NULL," "),&p,10);
	//for(x = 0; x < field->x; x++)
	//	field->image[x] = (char*)malloc(sizeof(char)*field->y);
		
	while(fgets(line,1000,F)){
		xoffset = strtol(strtok(line," "),&p,10);
		yoffset = strtol(strtok(NULL," "),&p,10);
		name = strtok(NULL," \n	\0");
		printf("%d %d %s %s\n",xoffset,yoffset,name,images[z].name);
		//for(x = 0; x < 256; x++){
		//	if(strcmp(images[x].name, name) == 0)
		//		break;
		//}//end for
		
		for(y = 0; y < images[x].x; y++){
			memmove(&field->image[xoffset+y]+yoffset, &images[x].image[y], images[x].y*sizeof(char));
		}//end for
	}//end 
	
	fclose(F);//*/
}//end overlay

void initialize(struct patch *images, char* input, char** names, int namesSize){
	FILE *F;
	char line[1000], temp[1000], *p;
	strcpy(temp,"123 321");
	int x,y,z,aa, b;
	b = 1000;
	//y = -1;
	x = 0;
	//p = "  ";
	z = 0;
	F = fopen(input,"r");
	if(F == NULL)
		return;
		
	/*//if the line == sometrhing in names
		//save to name
		//save next line to x and y, splitting on space
	//until line == names
		//save to image
		
	//strtol
	//printf("%d\n",namesSize);
	
		//aa = strtol(strtok(temp," 	\n\0"),&p,10);
		//z = strtol(strtok(NULL," "),&p,10);
		//printf("%d %d",aa,z);*/
	while(fgets(line, 1000, F)){
		line[strlen(line)-1] = '\0';
		images[x].name = line;
		names[x] = line;
		printf("%s\n",line);
		fgets(line,1000,F);
		images[x].x = strtol(strtok(line," 	\n\0"),&p,10);
		images[x].y = strtol(strtok(NULL," "),&p,10);
		printf("%d ",images[x].x);
		printf("%d\n",images[x].y);
		for(y = 0; y < images[x].x ; y++){
			fgets(line, 1000, F);
			line[strlen(line)-1] = '\0';
			strcpy((images[x].image[y]), line);
			printf("%s\n",line);
		}//*/
		x++;
	}//end while*/
	
	/*while(fgets(line, 1000, F)){
		for(x = 0; x < namesSize; x++){
			if(strcmp(line, names[x]) == 0){
				printf("%s, \n",line);
				y++;
				z = 0;
				fgets(line,1000,F);
				images[y].x = strtol(strtok(line," "),&p,10);
				images[y].y = strtol(strtok(line,"\0 \n	"),&p,10);
				//images[y].image = malloc(sizeof(char) * images[y].x);
				//for(aa = 0; aa < images[y].x; aa++){
				//	malloc(sizeof(char) * images[y].y);
				//}//end for
			}//end if
			fgets(line,1000,F);
			line[strlen(line)-1] = '\0';
			printf("%s\n ",line);
			//images[y]->image[z] = line;
			z++;
		}//end for
	}//end while
	*/
	
	//fgets(line,b,F);
	fclose(F);
}//end initialize

