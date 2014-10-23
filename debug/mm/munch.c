#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	int max = -1;
	int mb = 0;
	char* buffer;
	int i;

	unsigned int *p=malloc(1024*1024*800);

	printf("%p\n", p);

	for(i=0;i<1024*1024*200;i++)
		p[i] = 123;

	return 0;
}
