#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mergeSort.h"

/*
* Function that creates and returns a new randomized int array of the specified size
*/
int* newArray(size_t size) {
        int *array = (int *) malloc(size *sizeof(int));
        int on;
        srand((unsigned)time(NULL));
	for (on = 0; on < size; on++) {
                array[on] = rand() % (size*10); //generates a random number between 0-(size*10)
        }
        return array;
}

/*
* Prints out the values in an int array
*/
void printArray(int* array, size_t size) {
        int x;
        int numInRow = 0;
        printf("[");
	for (x = 0; x < size; x++) {
                //moves to next line if there are 5 values displayed
		if (numInRow == 10) {
                        printf("\n ");
                        numInRow = 0;
                }
                printf("%d ", array[x]);
                numInRow++;
        }
        printf("]\n");
}

/*
* The infamous bogosort
* Randomly sorts an array, and repeats if that didn't sort it
*
* The 'done' variable ensures that the while loop doesn't end
* until the array is sorted. It gets reset every loop, and gets
* decremented every time a value is found to be in order, ensuring
* the loop doesn't finish until all values are found to be in order.
*
*/
void bogoSort(int *array, size_t size, int* trackers) {
	int done = size - 1; //used to keep loop going until it reaches 0
	int x;
	int random;
	int temp;
	srand((unsigned)time(NULL)); //sets random() to use the current time as a seed
	while (done) { //will finish if done gets decremented to 0
		done = size - 1; //resets the done counter every loop
		//shuffles array
		for (x = 0; x < size; x++) {
			random = rand() % size;		
			temp = array[random];
			array[random] = array[x];
			array[x] = temp;
			trackers[1] += 4;
		}
		//checks if array is in order
		for (x = 0; x < size - 1; x++) { 	
			if (array[x] < array[x+1])
				done--; //decrements done if a value is in order 
			trackers[1] += 2;
			trackers[0]++;
		}
	}
}

/*
* Sorts an array using the bubble sort method
*/
void bubbleSort(int *array, size_t size, int* trackers) {
	int x;
	int temp;
	int swaps = 1;
	while (swaps != 0) {
		swaps = 0;
		for (x = 0; x < size - 1; x++) {
			if (array[x] > array[x+1]) {
				temp = array[x+1];
				array[x+1] = array[x];
				array[x] = temp;
				trackers[1] += 4;
				swaps++;	
			}
			trackers[0]++;
			trackers[1] += 2;
		}
	}
}

/*
* uses mergesort to sort an array
*/
void mergeSort(int* array, size_t size, int* trackers) {
	split(array, size, trackers);	
}

int main(int argc, char **argv) {
	size_t size;
	int* trackers = (int*) calloc(2, sizeof(int)); //[0] holds comparisons, [1] holds array accesses
	//ensures that there are 2 arguments
	if (argc != 3) {
	printf("Usage: sortit [size to sort] [algorithm(bogo, bubble, or merge)]\n");
	return 1;
	}
	
	size = atoi(argv[1]); //sets size to the second argument passed
	if (size < 1) {	
		printf("Usage: sortit [size to sort] [algorithm(bogo, bubble, or merge)]\n");
	return 1;
	}
	int *array = newArray(size);
	//prints the initial array
	printf("Initial array:\n");
	printArray(array, size);
	char *selection = argv[2];
	//runs the appropriate sort
	if (strcmp(selection, "bogo") == 0)
		bogoSort(array, size, trackers);
	else if (strcmp(selection, "bubble") == 0)
		bubbleSort(array, size, trackers);
	else if (strcmp(selection, "merge") == 0)
		mergeSort(array, size, trackers);
	else {
		printf("Usage: sortit [size to sort] [algorithm(bogo, bubble, or merge)]\n");
		return 1;
	}
	//prints off the sorted array
	printf("Sorted array:\n");
	printArray(array, size);
	printf("Comparisons: %d, Array Accesses: %d\n", trackers[0], trackers[1]);
	free(trackers);
	free(array);
	return 0;
}
