#include <stdio.h>
#include <stdlib.h>

#pragma pack (push, 1)
typedef struct
{
	unsigned short signature;
	unsigned int filesize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct
{
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bitsPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int xPixelsPerMeter;
	unsigned int yPixelsPerMeter;
	unsigned int colorsInColorTable;
	unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
} Rgb;

#pragma pack(pop)

void printFileHeader(BitmapFileHeader header){
	printf("signature:\t%x (%hu)\n", header.signature, header.signature);
	printf("filesize:\t%x (%u)\n", header.filesize, header.filesize);
	printf("reserved1:\t%x (%hu)\n", header.reserved1, header.reserved1);
	printf("reserved2:\t%x (%hu)\n", header.reserved2, header.reserved2);
	printf("pixelArrOffset:\t%x (%u)\n", header.pixelArrOffset, header.pixelArrOffset);
}

void printInfoHeader(BitmapInfoHeader header){
	printf("headerSize:\t%x (%u)\n", header.headerSize, header.headerSize);
	printf("width:     \t%x (%u)\n", header.width, header.width);
	printf("height:    \t%x (%u)\n", header.height, header.height);
	printf("planes:    \t%x (%hu)\n", header.planes, header.planes);
	printf("bitsPerPixel:\t%x (%hu)\n", header.bitsPerPixel, header.bitsPerPixel);
	printf("compression:\t%x (%u)\n", header.compression, header.compression);
	printf("imageSize:\t%x (%u)\n", header.imageSize, header.imageSize);
	printf("xPixelsPerMeter:\t%x (%u)\n", header.xPixelsPerMeter, header.xPixelsPerMeter);
	printf("yPixelsPerMeter:\t%x (%u)\n", header.yPixelsPerMeter, header.yPixelsPerMeter);
	printf("colorsInColorTable:\t%x (%u)\n", header.colorsInColorTable, header.colorsInColorTable);
	printf("importantColorCount:\t%x (%u)\n", header.importantColorCount, header.importantColorCount);
}

void swap(char *a, char *b){
	char t = *a;
	*a = *b;
	*b = t;
}


int main(){
	FILE *f = fopen("simpsonsvr.bmp", "rb");
	BitmapFileHeader bmfh;
	BitmapInfoHeader bmif;
	fread(&bmfh,1,sizeof(BitmapFileHeader),f);
	fread(&bmif,1,sizeof(BitmapInfoHeader),f);
	printFileHeader(bmfh);
	printInfoHeader(bmif);

	unsigned int H = bmif.height;
	unsigned int W = bmif.width;

	Rgb **arr = malloc(H*sizeof(Rgb*));
	for(int i=0; i<H; i++){
		arr[i] = malloc(W * sizeof(Rgb) + (W*3)%4);
		fread(arr[i],1,W * sizeof(Rgb) + (W*3)%4,f);
	}
		
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++)
			swap(&arr[i][j].r, &arr[i][j].g);
	}

	FILE *ff = fopen("out.bmp", "wb");

	bmif.height = H;
	bmif.width = W/2;
	fwrite(&bmfh, 1, sizeof(BitmapFileHeader),ff);
	fwrite(&bmif, 1, sizeof(BitmapInfoHeader),ff);
	unsigned int w = (W/2) * sizeof(Rgb) + ((W/2)*3)%4;
	for(int i=0; i<H; i++){
		fwrite(arr[i],1,w,ff);
	}
	fclose(ff);

	printf("\n");


return 0;
}
