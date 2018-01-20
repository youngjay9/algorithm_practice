#include <stdio.h>
#define SIZE 6

int binarySearch(int data[SIZE], int searchNum){
	int location;

	int i = 1;

	int j = SIZE;

	while(i < j){
		int m = (i+j)/2;
		//將搜尋範圍設定在右半部
		if(data[m]<searchNum){
			i = m + 1;
		}
		//將搜尋範圍設定在左半部
		else{
			j = m;
		}
	}/* end while i < j*/

	if(data[i] == searchNum){
		location = i;
	}
	else{
		location = 0;
	}	

	return location;
}

int main(int argc, char const *argv[])
{
	

	int data[SIZE] = {2, 3, 4, 6, 7 , 9};

	int searchNum;
	printf("enter Search Number:\n");
	scanf("%d", &searchNum);

	int location = binarySearch(data, searchNum);

	printf("%d is in the location:%d\n", searchNum,location);

	return 0;
}