#include <stdio.h>

int linearSearch(int *a, int length, int checkNum){
		
		int location = 0;	

		int counter = 0;
		
		/* key point */
		//if the checkNum is finded, get it's location
		while(counter<length && *(a+counter)!= checkNum){
			counter++;
		}

		if(counter <length){
			location = counter;
		}
		else{
			location = 0;
		}
		return location;
}


int main(void)
{
	int arr[8] = {2, 5, 6, 8, 11, 9, 10, 7};

	int length = sizeof(arr)/sizeof(arr[0]);

	//enter the number is to be searched
	int checkNum;
	printf("Enter a checkNum:\n");
	scanf("%d", &checkNum);

	printf("the checkNum: %d location is in:%d\n", checkNum, linearSearch(arr, length, checkNum));

	return 0;
}