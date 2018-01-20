#include <stdio.h>

#define SIZE 10


void printArray(int data[SIZE])
{
   int i;
   for (i=0; i < SIZE; i++){

   		if(i<SIZE-1){
			printf("%d,", data[i]);	
		}
		else{
			printf("%d\n", data[i]);
		}		
   }
   printf("\n");
}

void insertionSort(int data[SIZE]){

	int tmp;
	
	for(int i=1; i< SIZE; i++){
		
		for(int j=0; j<i; j++){
			if(data[i] < data[j]){
				tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}/* end for j*/
	}/* end for i */
}

int main(void){

	int data[SIZE] = {1, 8, 12, 9, 11, 2, 14, 5, 10, 4};

	printf("before insertionSort\n");

	printArray(data);

	printf("after insertionSort\n");

	insertionSort(data);

	printArray(data);


	return 0;
}