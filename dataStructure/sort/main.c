#include <stdio.h>
#include "sort.h"

int main(void){
	int i;
	int list[] = {3, 5, 1, 2, 9};

	int min = findMin(list, 0, 4);
	printf("The min index is %d, min value is %d\n", min, list[min]);

	selectSort(list, 5);
	for(i=0; i<5; i++){
		printf("%d", list[i]);
		if(i==4)
			puts("");
		else
			printf(" ");
	}

	int index = binarySearch(list, 5, 0, 4);
	printf("The binary search result: index %d, value:%d\n", index, index != -1 ? list[index] : -1);

	int indexR = binarySearchR(list, 5, 0, 4);
	printf("The binary search result: index %d, value:%d\n", indexR, indexR!= -1 ? list[indexR] : -1);

	return 0;
}
