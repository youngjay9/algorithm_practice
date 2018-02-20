#include<stdio.h>

//c(n+1,r) = c(n,r-1) + c(n, r)
//c(n,n) = c(n,0) = 1
int p(int n, int r){

	if(n > r && r > 0){
		return p(n-1, r-1) + p(n-1, r);
	}
	else{
		return 1;
	}

}


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

	//calculate c(n, r)
	printf("c(%d, %d) =%d\n", n, r, p(n, r));

	return 0;
}