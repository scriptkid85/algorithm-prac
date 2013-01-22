#include <stdlib.h>
#include <stdio.h>

int main(){
	char *b = "3rd";
	char c = '3';
	char d = 'r';
	char e = 'd';
	long int *a = (long int *)malloc(sizeof(long int));
	*a = 0xffffffe7;
	printf("aaaa %c, %x, %c, %x", d, d, b[3], b[3]);
	
	getchar();
	getchar();
}
