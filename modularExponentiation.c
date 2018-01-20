#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  //over initial size, so let it be bigger 2 times
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}



int main(int argc, char const *argv[])
{
	
	//caculate 3^644 mod 645

	int base =  1819;

	int exponential = 13;

	int moduloNum = 2537;

	

	int divided = exponential;

	int tmpQuotient = divided / 2;

	int tmpRemainder = divided % 2;

	//translate exponential to binary array
	Array binaryArray;

	//initial 5 elements
	initArray(&binaryArray, 5);

	insertArray(&binaryArray, tmpRemainder);

	while(tmpQuotient > 0){
		divided = tmpQuotient;
		tmpQuotient = divided /2;
		tmpRemainder = divided % 2;
		insertArray(&binaryArray, tmpRemainder);
	}

	printf("binaryArray size:%zu\n", binaryArray.used);

	int result = 1;

	for(int i=0; i<binaryArray.used; i++){
		printf("%d\n", binaryArray.array[i]);

		int binaryNum = binaryArray.array[i];

		//算每個次方的餘數
		//弟一項 
		if(i == 0){
			tmpRemainder = base % moduloNum;
		}
		else{
			tmpRemainder = (tmpRemainder*tmpRemainder) % moduloNum;
		}
		
		//該次方的項數是1, 放進 result
		if(binaryNum == 1){
			result = (result * tmpRemainder) % moduloNum;
		}
	}/* end for */	

	printf("result:%d\n", result);	



	freeArray(&binaryArray);

	return 0;
}