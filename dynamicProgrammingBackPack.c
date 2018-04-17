#include <stdio.h>
#include <stdlib.h>

#define ITEMS_SIZE 4

int gerCurrentPrice(int i){

	int result;

	switch(i){

		case 0: //吉他
			result = 1500;
			break;
		case 1: //筆電
			result = 2000;
			break;
		case 2: //iPhone
			result = 2000;
			break;
		case 3: //音響
			result = 3000;
			break;		 	

	}
	return result;
}

int gerCurrentPounds(int i){

	int result;

	switch(i){

		case 0: //吉他
			result = 1;
			break;
		case 1: //筆電
			result = 3;
			break;
		case 2: //iPhone
			result = 1;
			break;
		case 3: //音響
			result = 4;
			break;		 	

	}
	return result;
}

int main(int argc, char const *argv[])
{
	
	int arr[ITEMS_SIZE][ITEMS_SIZE];

	int currentPrice;

	int currentPounds;

	for(int i=0; i<ITEMS_SIZE;i++){

		currentPrice = gerCurrentPrice(i);

		currentPounds = gerCurrentPounds(i);

		int finalPrice = 0;

		if(i==2){
			printf("目前價格:%d\n", currentPrice);
		}

		for(int j=0; j<ITEMS_SIZE; j++){

			//第一列
			if(i == 0){
				arr[i][j] = currentPrice;
			}
			else{
				//先前最高價[i-1][j]
				int previousPrice = arr[i-1][j];

				//剩餘重量
				int remainingWeight = (j+1) - currentPounds;
				
				//剩餘重量<0, 以先前價格為主
				if(remainingWeight < 0){
					finalPrice = previousPrice;
				}
				//剩餘重量==0, 用先前最高價跟目前價格去比較
				else if(remainingWeight == 0){
					if(previousPrice > currentPrice){
						finalPrice = previousPrice;
					}else{
						finalPrice = currentPrice;
					}
				}
				//剩餘重量>0, 用先前價格跟目前價格+剩餘重量價格 去比較
				else if(remainingWeight >0){
					  int tmp = currentPrice + arr[i-1][remainingWeight-1];
					  if(previousPrice > tmp){
						finalPrice = previousPrice;
					  }else{
						finalPrice = tmp;
					  }
				}
				
				arr[i][j] = finalPrice;

			}/* end else 非第一列 */

			
		}/* end for 每一欄 */
			
	}/* end for 每一列 */

	//最大價格為  arr 最後一個元素			
	for(int i=0; i<ITEMS_SIZE;i++){
		for(int j=0; j<ITEMS_SIZE; j++){
			printf("arr[%d][%d]:%d", i, j, arr[i][j]);
		}
		printf("\n");	
	}

	printf("Max price:%d\n", arr[ITEMS_SIZE - 1][ITEMS_SIZE -1]);	


	return 0;
}
