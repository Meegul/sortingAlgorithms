#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
* Function that creates and returns a new randomized int array of the specified size
*/
int* newArray(size_t size) {
        int *array = (int *) malloc(size);
        printf("Array was made with size: %ld\n", size);
        int on;
        srand((unsigned)time(NULL));
	for (on = 0; on < 1000; on++) {
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
        printf("\n[");
	for (x = 0; x < size; x++) {
                //moves to next line if there are 5 values displayed
		if (numInRow == 5) {
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
*/
int* bogoSort(int *array, size_t size) {
	int done = size - 1; //used to keep loop going until it reaches 0
	int x;
	int random;
	int temp;
	int nums = 0;
	srand((unsigned)time(NULL)); //sets random() to use the current time as a seed
	while (done) {
		done = size - 1; //resets the done counter
		printf("Iteration on: %d\n", ++nums);
		//shuffles array
		for (x = 0; x < size; x++) {
			printf("Iteration on: %d\n", ++nums);
			random = rand() % size;		
			temp = array[random];
			array[random] = array[x];
			array[x] = temp;
		}
		//checks if array is in order
		for (x = 0; x < size - 1; x++) { 	
			printf("Iteration on: %d\n", ++nums);
			if (array[x] < array[x+1])
				done--; //decrements done if a value is in order 
		}
	}
	return array;
}

/*
* Sorts an array using the bubble sort method
*/
int* bubbleSort(int *array, size_t size) {
	int x;
	int y;
	int temp;
	int nums = 0;
	//will always run size^2 times
	for (x = 0; x < size; x++) {
		for (y = 0; y < size; y++) {	
			printf("Iteration on: %d\n", ++nums);
			//swaps values if the first is smaller than the second
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
	//ensures that there are 2 arguments
	if (argc != 3) {
	printf("Usage: sortit [size to sort] [algorithm(bogo or bubble)]\n");
	return 1;
	}
	size = atoi(argv[1]); //sets size to the second argument passed
	int *array = newArray(size);
	//prints the initial array
	printArray(array, size);
	char *selection = argv[2];
	//runs the appropriate sort
	if (strcmp(selection, "bogo") == 0)
		array = bogoSort(array, size);
	else if (strcmp(selection, "bubble") == 0)
		array = bubbleSort(array, size);
	else printf("Usage: sortit [size to sort] [algorithm(bogo or bubble)]\n");
	//prints off the sorted array
	printArray(array, size);
	return 0;
}
