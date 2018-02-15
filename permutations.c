#include<stdio.h>


//using n*(n-1)*(n-2)*...*(n-r+1)
int getNimberOfPermutations(int n, int r){

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

int main(void){

	// the number of elements
	int n = 3;

	// r-permutations
	int r = 2;

	printf("permutations:%d\n", getNimberOfPermutations(n, r));


	return 0;
}