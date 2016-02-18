#include <stdlib.h>
#include "mergeSort.h"

void merge(int* array, int* left, int lsize, int* right, int rsize, int* trackers) {
	int x,y,z;
	x = 0; y = 0; z = 0;
	while (x < lsize  && y < rsize) {
		if (left[x] < right[y])
			array[z++] = left[x++];
		else array[z++] = right[y++];
		trackers[0]++;
		trackers[1] += 4;
	}
	while (x < lsize) {
		array[z++] = left[x++];
		trackers[1] += 2;
	}
	while (y < rsize) {
		array[z++] = right[y++];
		trackers[1] += 2;
	}
}


void split(int* array, int max, int* trackers) {
	int mid, i;
	int *left, *right;
	if (max < 2)
	return;
	mid = max/2;
	left = (int*) malloc(mid*sizeof(int));
	right = (int*) malloc((max-mid)*sizeof(int));
	for (i = 0; i < mid; i++) {
		left[i] = array[i];
		trackers[1] += 2;
	}
	for (i = mid; i < max; i++) {
		right[i - mid] = array[i];
		trackers[1] += 2;
	}
	split(left, mid, trackers);
	split(right, max - mid, trackers); 	
	merge(array, left, mid, right, max - mid, trackers);
 } 
