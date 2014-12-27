#include<stdio.h>

#define LINE_LEN 100

int main()
{
	char fname[50];
	
	puts("输入文件名:");
	scanf("%s",fname);

	FILE *f = fopen(fname,"w");
	
	if(f==NULL){
		printf("No file named %s.",fname);
		return 1;
	}

	char content[100];
	
	printf("输入内容:");
	scanf("%s",content);
    
	int i;
	for(i=0;i<LINE_LEN;i++){
		if(content[i]=='\0')
		     break ;
		fputc(content[i],f);
	}
	
	fclose(f);
	return 0;
}
