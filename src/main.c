#include <stdio.h>
#include <string.h>
#include <math.h>
#define IMGSIZE 256
typedef struct {
    char MagickNumber[3];
    int width;
    int height;
    int Maxval;
    char Name[50];
} ImageStr;

int SaveImg( ImageStr img, int IMG[IMGSIZE*IMGSIZE] ) {
	FILE *fp;

    fp = fopen(img.Name, "w");
    if(fp == NULL) {
        
        printf("File is not exist.\n");
        return -1;
        
    }
    fprintf(fp,"%s\n",img.MagickNumber);
    fprintf(fp,"%d\n",img.width);
    fprintf(fp,"%d\n",img.height);
    fprintf(fp,"%d\n",img.Maxval);

    for(int i=0; i<IMGSIZE; i++) {
        for(int j=0; j<IMGSIZE; j++) {
            fprintf(fp,"%d\n",IMG[j+i*256]);
            
        }
        
    }
    return 0;
}

int Grad(ImageStr *img, int *IMG ) {
    strcpy(img->MagickNumber,"P2");
    img->width = 256;
    img->height = 256;
    img->Maxval = 255;
    strcpy(img->Name,"Grad.pgm");

    for(int i=0; i<IMGSIZE; i++) {
        for(int j=0; j<IMGSIZE; j++) {
            IMG[256*i+j]=i;
            
        }
        
    }
    return 0;
}
int main(void) {
    ImageStr img;
    int IMG[IMGSIZE*IMGSIZE];

    ImageStr *ImG = &img;
	
    for(int i=0; i<IMGSIZE; i++) {
        for(int j=0; j<IMGSIZE; j++) {
            IMG[256*i+j] = 0;
        }
    }
	
    Grad(ImG, IMG);
    SaveImg(img, IMG);
    return 0;
}

int DrawCircle(ImageStr *img, int *IMG) {
	int x, y;
	double theta;
	int r = 50;
	
	strcpy(img->MagickNumber,"P2");
    img->width = 256;
    img->height = 256;
    img->Maxval = 255;
    strcpy(img->Name,"Circle.pgm");

	for(int i = 0;i < 360; i++){
		theta = i * (3.1415/180);
		x = (int)(r * cos(theta));
		y = (int)(r * sin(theta));
		IMG[256 * (x + 128) + (y + 128)] = 255;
	}
	return 0;
}