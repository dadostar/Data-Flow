#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

int main()
{
	const int vectorSize = Vectors_vectorSize;
	const int streamSize = 16;
	size_t sizeBytes = streamSize * sizeof(uint32_t);
	//uint32_t *inVector = malloc(sizeBytes);
	float *outVector1 = malloc(sizeBytes);
	float *outVector2 = malloc(sizeBytes);
	float *expectedVector = malloc(sizeBytes);

    printf("VectorSize %d - StreamSize %d\n", vectorSize, streamSize);

    //uint32_t inVector[] = {0, 16, 13, 0, 0, 0,    0, 0, 10, 12, 0, 0,    0, 4, 0, 0, 14, 0,     0, 0, 9, 0, 0, 20,    0, 0, 0, 7, 0, 4,    0, 0, 0, 0, 0, 0};
    //uint32_t inVector[] = { 2, -1, -2, -4, 6, 3, -4, -2, 8};
    
    float inVector[] = {1, -2, -2, -3, 3, -9, 0, -9, -1, 2, 4, 7, -3, -6, 26, 2};


	printf("Running DFE.\n");
	Vectors(streamSize, inVector, outVector1, outVector2);




	return 0;
}
