

#include <iostream>
using namespace std;
int main(){
    
	// in this board, a 1 represents a queen
	int board[8][8]={0}; //sets the entire board to 0
    	int row, col=0; //starts the rows and columns at 0
    	board[row][col]=1; //puts the first queen at [0][0], the upper left corner 
    
	next_col:
    	col=col+1; //we now move to the next column 
    	if (col>7){ //columns can't be greater than 7, so when we reach this point it means that we have found all solutions and we must print the board
        	goto print_board;
    	}
    	else row=-1; //we set row to 0 to start at the top of the column
    
   	next_row:
	row = row+1;
	if (row > 7){
		goto backtrack;
	}

	//same row test
    	for (int i=0; i<col; ++i){
 		if(board[row][i]==1) goto next_row; //if there is already a queen (1) in this row, then we can't put another queen here and we must go to the next row
    	}
    
    	//up diagonal test
    	for (int i=1; (row-i >=0 && col-i >=0); ++i){ 
        	if (board[row-i][col-i]==1){ //if there is already a queen in the upper diagonal, then we need to try the next row down
            		goto next_row;
		}
	}
    
	//down diagonal test
    	for (int i=1; (row+i <8 && col-i >=0); i++){
        	if (board[row+i][col-i]==1){ //if there is already a queen in the down diagonal, then we need to go back a row and change the position of the queen
           		 goto next_row;
        	}
   	 }
    
   	 //placing queen
   	 board[row][col]=1; //if there are no conflicts, we can place our queen!
   	 goto next_col; //after doing so, we move to the top of the next column to try to place the next queen
    
	backtrack:
	--col; //go back 1 column
	if (col==-1){
		 return 0; //all solutions found, end the program
	}

	row=0;
	while(board[row][col] !=1){
		++row;
	}
	board[row][col]=0;
	goto next_row;
	
	//print section
	print_board:
	static int sol=1;
	cout << "Solution number: " << sol++ <<endl;
	for (int row=0; row<8; row++){
        	for (int col=0; col<8; col++){
            		cout << board[row][col];
        	}
		cout << endl;
   	 }
	cout << endl;
    	goto backtrack;
    
return 0;
}
