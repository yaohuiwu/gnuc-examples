#include <stdio.h>
#include "sort.h"

int main(void){
	int i;
	int list[] = {3, 5, 1, 2, 9};

	int min = findMin(list, 0, 4);
	printf("The min index is %d, min value is %d\n", min, list[min]);

	selectSort(list, 5);
	for(i=0; i<5; i++){
		printf("%d ", list[i]);
	}
	puts("");

	return 0;
}
