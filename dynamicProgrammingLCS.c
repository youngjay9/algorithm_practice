#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	//輸入的字串
	char *inputStr = "clues";

	//從字典裡被拿來比較的字串
	char *compareStr = "blue";


 	int columns = strlen(inputStr);

 	int rows = strlen(compareStr);
	

 	printf("length of inputStr:%lu\n", strlen(inputStr));
 	printf("length of compareStr:%lu\n", strlen(compareStr));

 	int cell[rows][columns];
 	
 	
 	//開始找共用序列最長的長度
 	for(int i=0; i<rows;i++){
 		for(int j=0; j<columns;j++){
 			//字元相同
 			if(compareStr[i] == inputStr[j]){
 				if(i==0 && j ==0){
 					cell[i][j] = 1;
 				}
 				else if(i==0 && j>0){
 					cell[i][j] = cell[i][j-1] +1;//左邊一格的值+1
 				}
 				else if(i>0 && j==0){
 					cell[i][j] = cell[i-1][j]+1;//上面一格的值+1
 				}
 				else if(i>0 && j>0){
 					cell[i][j] = cell[i-1][j-1] +1;//左上角的值=1
 				}
 				
 			}/* end if 字元相同 */
 			else{
 				if(i==0 && j ==0){
 					cell[i][j] = 0;
 				}
 				else if(i==0 && j>0){
 					cell[i][j] = cell[i][j-1];//左邊一格的值
 				}
 				else if(i>0 && j==0){
 					cell[i][j] = cell[i-1][j];//上面一格的值
 				}
 				else if(i>0 && j>0){
 					int leftOne = cell[i][j-1];
 					int upOne = cell[i-1][j];
 					if(leftOne > upOne){
 						cell[i][j] = leftOne;
 					}
 					else{
 						cell[i][j] = upOne;
 					}
 				}
 			}/* end else 字元不同*/	

 		}/* end for columns */
 	}/* end for rows */

 	
 	//印出最長共用序列的表格			
 	for(int i=0; i<rows;i++){
		for(int j=0; j<columns; j++){
			printf("cell[%d][%d]:%d", i, j, cell[i][j]);
		}
		printf("\n");	
	}

	//共用序列最長的長度
	int lesLength = cell[rows -1][columns -1];

	int lcsArr[lesLength];

	int tmpMax = 0;

	int counter = 0;

	//找出共用序列的元素(橫著找)
	for(int i=0; i<rows;i++){
		for(int j=0; j<columns; j++){
			if(cell[i][j] > tmpMax){
				tmpMax = cell[i][j];
				lcsArr[counter] = inputStr[i];
				printf("%c\n", inputStr[i]);
				counter++;
			}
		}
		printf("\n");	
	}

	int lcsArr2[lesLength];

	int tmpMax2 = 0;

	int counter2 = 0;
	//找出共用序列的元素(直著找)
	for(int j=0; j<columns;j++){
		for(int i=0; i<rows; i++){
			//columns 固定
			if(cell[i][j] > tmpMax2){
				tmpMax2 = cell[i][j];
				lcsArr2[counter2] = inputStr[i];
				printf("%c\n", inputStr[i]);
				counter2++;
			}
		}
		printf("\n");	
	}

			

	return 0;
}