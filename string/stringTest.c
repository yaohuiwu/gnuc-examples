#include <stdio.h>
#include <string.h>

int main()
{
	char *test_s = "Hello,world";
	printf("address %s : %p\n",test_s,&test_s);
	printf("sizeof %s : %ld\n",test_s,(unsigned long)sizeof(test_s));
	size_t len = strlen(test_s);
	printf("length of %s : %ld\n",test_s,(unsigned long)len);
}
