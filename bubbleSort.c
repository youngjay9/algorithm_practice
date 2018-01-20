#include <stdio.h>
#define SIZE 5

void interChange(int *v1, int *v2){
	int tmp = *v1;

	*v1 = *v2;

	*v2 = tmp;
}

void bubbleSort(int *d){
	for(int i=0; i<SIZE-1; i++){
		for(int j=0; j<(SIZE-1)-i; j++) {
			if(d[j] > d[j+1]){
				interChange(d+j, d+j+1);
			}
		}
	}/* end for i */
}

int main(void){

	int data[SIZE] = {3, 2, 5, 4, 1};

	for(int i=0; i<SIZE; i++){
		if( i < SIZE - 1){
			printf("data[%d]:%d,", i, data[i]);
		}
		else{
			printf("data[%d]:%d\n", i, data[i]);
		}
	}

	bubbleSort(data);

	printf("After bubble sort!!\n");

	for(int i=0; i<SIZE; i++){
		if( i < SIZE - 1){
			printf("data[%d]:%d,", i, data[i]);
		}
		else{
			printf("data[%d]:%d\n", i, data[i]);
		}
	}
	
	return 0;
}