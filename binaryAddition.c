#include <stdio.h>
#define SIZE 5

int main(void){

	//Ex: get quotient
	printf("1 div 2:%d\n", 3/2);

	//Ex: get remainder
	printf("1 mod 2:%d\n", 3 % 2); 

	// binary a: 1110
	int a[SIZE] = {0,1,1,1};
	//binary b: 1011
	int b[SIZE] = {1,1,0,1};

	//binary a +b sumation
	int s[SIZE] = {0,0,0,0};

	//carry
	int c = 0;

	for(int j=0; j<SIZE-1; j++){
		s[j] = (a[j] + b[j] + c) % 2;
		c = (a[j] + b[j] + c) / 2;
	}

	s[4] = c;

	for(int j=SIZE-1; j>= 0; j--){
		printf("%d",s[j]);
	}

	printf("\n");


	return 0;
}