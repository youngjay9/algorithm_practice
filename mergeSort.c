#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	size_t size;
	int *elements;
} MyArray;


void removeFirstElement(MyArray *m){

	int size = m->size;

	for(int i=0; i< size-1; i++){
		m->elements[i] = m->elements[i+1];
	}

	// free(m->elements[size-1]);

	m->size = m->size -1;
}

int * merge( MyArray *m1,  MyArray *m2){
	
	int length1 = m1->size;//*(m1).size

	int length2 = m2->size;//*(m2).size
	
	int counter = 0;
	
	int tmpArray[length1 + length2];

	
	while(m1->size >0 && m2->size >0){
		
		if(m1->elements[0] < m2->elements[0]){
			tmpArray[counter] = m1->elements[0];
			removeFirstElement(m1);
		}
		else{
			tmpArray[counter] = m2->elements[0];
			removeFirstElement(m2);
		}

		counter++;
	}/* end while */


	if(m1->size == 0){
		for(int j=0; j<length2;j++){
			tmpArray[counter] = m2->elements[j];
			counter++;
		}
	}
	else{
		for (int j = 0; j < length1; j++)
		{
			tmpArray[counter] = m1->elements[j];
			counter++;
		}
	}

	printf("Merger:\n");
	for(int i=0; i<counter; i++){
		printf("%d ", tmpArray[i]);
	}
	printf("\n");
	

	return tmpArray;
}


int * mergeSort(MyArray *m){

	int size = m->size;

	printf("size:%d\n", size);

	
	if(size ==1){
		return m->elements;
	}
	else{
		
		//因爲 index 從 0 開始,所以 size 需減 1
		int middleNum = (size -1)/2;

		// printf("middleNum:%d\n", middleNum);

		int length1 = middleNum + 1;

		int length2 = size -1 - middleNum;

		// printf("length1:%d\n", length1);
		// printf("length2:%d\n", length2);

		int L1[length1];
		int L2[length2];

		for(int i =0; i<(middleNum+1); i++){
			L1[i] = m->elements[i];
		}
		for(int j = 0; j<length2; j++){
			L2[j] = m->elements[middleNum+1+j];
		}

		MyArray m1 = {length1, L1};

		MyArray m2 = {length2, L2};

		//==============test===============//
		for(int k=0; k<length1; k++){
			printf("L1[%d]:%d  ", k, L1[k]);
		}

		printf("\n");

		for(int k=0; k<length2; k++){
			printf("L2[%d]:%d  ", k, L2[k]);
		}

		printf("\n\n");
		//==============test===============//

		int *leftElements = mergeSort(&m1);

		int *rightElements = mergeSort(&m2);

		MyArray leftArray = {length1,  leftElements}; 
		MyArray rightArray = {length2, rightElements};

		return merge(&leftArray, &rightArray);

	}

}

int main(int argc, char const *argv[])
{
	// int l1[2] = {4, 5};

	// int l2[2] = {2, 7};

	// MyArray m1 = {2, l1};

	// MyArray m2 = {2, l2};


	// int *m = merge(&m1, &m2);
	
	// for(int i = 0; i<4; i++){
	// 	printf("m[%d]:%d\n", i, *(m+i));
	// }

	int arr[4] = {5,4, 9,6};

	MyArray m = {4, arr};

	int * result = mergeSort(&m);

	// for(int i = 0; i<4; i++){
	// 	printf("result[%d]:%d\n", i, result[i]);
	// }

	return 0;
}