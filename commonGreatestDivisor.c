#include <stdio.h>

int getGCD(int a, int b){

	/*
		a = bQ + r
		gcd(a,b) = gcd(b,r)
	*/
	int r = 0;

	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}


int main(int argc, char const *argv[])
{
	
	int a;

	int b;

	printf("Enter first num:\n");
	scanf("%d", &a);

	printf("Enter second num:\n");
	scanf("%d", &b);

	int gcd = getGCD(a, b);

	printf("gcd of %d and %d: %d\n", a, b, gcd);

	return 0;
}