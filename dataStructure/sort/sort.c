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

int binarySearch(int list[], int number, int left, int right){
	int middle=0;

	while(left<=right){
		middle = (left + right)/2;
		switch(COMPARE(number, list[middle])){
			case -1:
				right = middle - 1;
				break;
			case 0:
				return middle;
			case 1:
				left = middle + 1;
		}
	}
	return -1;
}

int binarySearchR(int list[], int number, int left, int right){
	int middle=0;

	if(left<=right){
		middle = (left + right)/2;
		switch(COMPARE(number, list[middle])){
			case -1:
				return binarySearchR(list, number, left, middle-1);
			case 0:
				return middle;
			case 1:
				return binarySearchR(list, number, middle + 1, right);
		}
	}
	return -1;
}
