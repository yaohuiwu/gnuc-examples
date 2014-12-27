#include<stdio.h>

int main()
{
	char fname[50];
	
	puts("输入文件名:");
	scanf("%s",fname);

	FILE *f = fopen(fname,"r");
	
	if(f==NULL){
		printf("No file named %s.",fname);
		return 1;
	}

	printf("%s:\n",fname);
	char c;
	while((c=fgetc(f))!=EOF)
	{
		if(c=='\t')
			printf("    ");
		else
			printf("%c",c);
	}
	fclose(f);
	return 0;
}
