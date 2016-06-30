#include <stdio.h>
#include <string.h>

//return the right most index of t in s, -1 if not found.
int rightMostIndex(char s[], char t[]);

//print args from command line
void printArgs(char **argv, int argc);

int main(int argc, char **argv)
{
	printArgs(argv, argc);
	if(argc < 3){
		printf("Usage: ./rightMostIndex source target\n");
		return 0;
	}

	int index = rightMostIndex(argv[1], argv[2]);

	printf("right most index is %d\n", index);

	return 0;
}

int rightMostIndex(char s[], char t[]){
	int i, j, k;
	int rMostIndex = -1;

	for(i=0; s[i] != '\0'; i++){
		for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
		;
		//at least compare one char, and couner of t end
		if(k>0 && t[k] == '\0'){
		 	rMostIndex = i;
			printf("%d\n", i);
		}
	}

	return rMostIndex;
}

void printArgs(char **argv, int argc){
	int i, j;

	for(i=0; i< argc; i++){
		printf("%s", argv[i]);
		if(i != argc)
			printf(" ");
	}
	printf("\n");
}
