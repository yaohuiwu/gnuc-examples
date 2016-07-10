/**
 * sort functions.
 */
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x, y) (((x)<(y))? -1 : ((x)==(y)) ? 0 : 1)

//find the min value in list from index f to t. 
int findMin(int list[], int f, int t);

//sort an int array by select sort.
void selectSort(int list[], int n);

//do a binary search aginst the list, return the index if number exists, -1 if not.
int binarySearch(int list[], int number, int left, int right);

int binarySearchR(int list[], int number, int left, int right);
