#include <stdio.h>


int count(int n){
	n += 1;
	return n;
}

int main(void){
	int n = 5;

	n = count(n);
	printf("Testing test: %d\n", n);
	return 0;
}
