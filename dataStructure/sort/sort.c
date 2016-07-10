#include "sort.h"


int findMin(int list[], int f, int t){
	int i, min;
	for(i=f+1, min=f; i<=t; i++)
		if(list[i] < list[min])
			min = i;
	return min;
}

void selectSort(int list[], int n){
	int i, j, min, t;

	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++)
			if(list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], t);
	}
}
