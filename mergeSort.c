#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r){

	//L[]
	int leftLength = m - l + 1;
	int L[leftLength];

	//R[]
	int rightLength = r - m;
	int R[rightLength];

	//開始指定 L[]
	int i = 0; //給 L[] 用的計數器
	int k = l; //給 arr 用的計數器,預設為 l
	while(i<leftLength){
		L[i] = arr[k];
		i++;
		k++;
	}

	//開始指定 R[]
	int j = 0; //給 R[] 用的計數器
	k = m + 1;
	while(j <rightLength){
		R[j] = arr[k];
		j++;
		k++;
	}

	//開始進行 comparisons 並指定至 mergedList
	i = 0;
	j = 0;
	k = l;
	while(i < leftLength && j < rightLength){
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
			k++;
		}
		else{
			arr[k] = R[j];
			j++;
			k++;
		}
	}/* end while comparisons */

	//comparisons 結束以後, 剩餘非 empty 的 elements 指定至 mergedList
	while(i<leftLength){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<rightLength){
		arr[k] = R[j];
		j++;
		k++;
	}	

}/* end method merge */

void mergeSort(int *arr ,int l, int r){

	if(l<r){
		int m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}	


int main(int argc, char const *argv[])
{
	int arr[8] = {1,2,3,4,5,7,6,8}; 

	int l = 0;
	int r = 7;

	mergeSort(arr, l, r);
	

	for(int i=0; i<8; i++){
		printf("arr[%d]:%d\n", i, arr[i]);
	}



	return 0;
}