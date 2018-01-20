#include<stdio.h>

int f(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * f(n-1);
	}
}


int main(int argc, char const *argv[])
{
	
	printf("factorial:%d\n", f(4));

	return 0;
}