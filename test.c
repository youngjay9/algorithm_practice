#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int l, int r){

	int m = (l+r-1)/2;	

	int leftLength = (m - l)+1;

	int rightLength = r - m;

	int L[leftLength];

	int R[rightLength];

	int lIndex, rIndex;

	

	for(lIndex =0; lIndex<leftLength; lIndex++){
		L[lIndex] = arr[l+lIndex];
	}

	for(rIndex =0; rIndex<leftLength; rIndex++){
		R[lIndex] = arr[m+1+rIndex];

	}

	lIndex = 0;

	rIndex = 0;

	int mIndex = l;

	while(lIndex < leftLength && rIndex< rightLength){

		if(L[lIndex] <= R[rIndex]){
			arr[mIndex] = L[lIndex];
			lIndex++;
		}

		if(R[rIndex] < L[lIndex]){
			arr[mIndex] = R[rIndex];
			rIndex++;
		}

		mIndex++;

	}/* end while */

	while(lIndex < leftLength){
		arr[mIndex] = L[lIndex];
		lIndex++;
		mIndex++;
	}

	while(rIndex < rightLength){
		arr[mIndex] = R[rIndex];
		rIndex++;
		mIndex++;
	}	

}


int main(int argc, char const *argv[])
{
	
	int arr[6] = {4, 5, 7, 3, 2, 1};

	printf("Before sort!!\n");

	for(int i=0; i<6; i++){
		printf("%d", arr[i]);
	} 
	printf("\n\n");
	
	merge(arr, 0, 5);

	printf("After sort!!\n");

	for(int i=0; i<6; i++){
		printf("%d", arr[i]);
	}

	printf("\n\n");
	

	return 0;
}