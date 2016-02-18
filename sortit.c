#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int* newArray(size_t size) {
        int *array = (int *) malloc(size);
        printf("Array was made with size: %ld\n", size);
        int on;
        srand((unsigned)time(NULL));
	for (on = 0; on < 1000; on++) {
                array[on] = rand() % (size*10);
        }
        return array;
}

void printArray(int* array, size_t size) {
        int x;
        int numInRow = 0;
        printf("\n[");
	for (x = 0; x < size; x++) {
                if (numInRow >= 5) {
                        printf("\n ");
                        numInRow = 0;
                }
                printf("%d ", array[x]);
                numInRow++;
        }
        printf("]\n");
}

int* bogoSort(int *array, size_t size) {
	int done = size - 1;
	int x;
	int random;
	int temp;
	int nums = 0;
	srand((unsigned)time(NULL));
	while (done) {
		done = size - 1;
		printf("Iteration on: %d\n", ++nums);
		for (x = 0; x < size; x++) {
			printf("Iteration on: %d\n", ++nums);
			random = rand() % size;		
			temp = array[random];
			array[random] = array[x];
			array[x] = temp;
		}
		for (x = 0; x < size - 1; x++) { 	
			printf("Iteration on: %d\n", ++nums);
			if (array[x] < array[x+1])
				done--;
		}
	}
	return array;
}

int* bubbleSort(int *array, size_t size) {
	int x;
	int y;
	int temp;
	int nums = 0;
	for (x = 0; x < size; x++) {
		for (y = 0; y < size; y++) {	
			printf("Iteration on: %d\n", ++nums);
			if (array[x] < array[y]) {
				temp = array[y];
				array[y] = array[x];
				array[x] = temp;	
			}
		} 
	}
	return array;
}

int main(int argc, char **argv) {
	size_t size;
	size = atoi(argv[1]);
	if (argc != 3) {
	printf("Usage: sortit [size to sort] [algorithm(bogo or bubble)]\n");
	return 1;
	}
	int *array = newArray(size);
	printArray(array, size);
	char *selection = argv[2];
	if (strcmp(selection, "bogo") == 0)
		array = bogoSort(array, size);
	else if (strcmp(selection, "bubble") == 0)
		array = bubbleSort(array, size);
	else printf("Usage: sortit [size to sort] [algorithm(bogo or bubble)]\n");
	printArray(array, size);
	return 0;
}
