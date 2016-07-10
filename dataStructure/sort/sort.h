/**
 * sort functions.
 */
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

//find the min value in list from index f to t. 
int findMin(int list[], int f, int t);

//sort an int array by select sort.
void selectSort(int list[], int n);
