#include <stdio.h>

//using n*(n-1)*(n-2)*...*(n-r+1)
int getNumberOfPermutations(int n, int r){

	int result = 1;

	
	if(r < 1){ // empity list, permutations = 1
		return result;
	}
	else{
		int tmpR = 1;

		while(tmpR <= r){
			result *= n - (tmpR -1);
			tmpR ++;
		}
	}

	return result;
}

int f(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * f(n-1);
	}
}


//combinations uses permutations and factorial technologies to calculate
int main(int argc, char const *argv[])
{
	int n;

	int r;

	printf("Enter n:");
	scanf("%d", &n);

	while(n < 0){
		printf("n must be greater than 0!!");
		scanf("%d", &n);
	}

	printf("Enter r:");
	scanf("%d", &r);

	while(n<r){
		printf("r must be smaller than n!!");
		scanf("%d", &r);	
	}

	//combinations = permutations / r!
	int permutations = getNumberOfPermutations(n, r);

	//r!
	int facR = f(r);

	printf("c(%d, %d) =%d\n", n, r, permutations / facR);

	return 0;
}