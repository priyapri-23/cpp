#include <iostream>
#include <math.h>
using namespace std;

void Print(int board[][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " "; // Print each number with a space
        }
        cout << "\n"; // Explicitly use "\n" for a new line
    }
    cout << "\n"; // Add an extra line after the entire board
}

bool isValid(int board[][9], int i, int j, int num, int n) { 
    // Row and column check
    for (int x = 0; x < n; x++) {
        if (board[i][x] == num || board[x][j] == num) {
            return false;
        }
    }

    // Submatrix check
    int rn = static_cast<int>(sqrt(n)); // Correctly cast the result of sqrt to an int
    int si = i - i % rn; // Starting index for the submatrix row
    int sj = j - j % rn; // Starting index for the submatrix column

    // Ensure loop bounds are within the board size
    for (int x = si; x < si + rn && x < n; x++) {
        for (int y = sj; y < sj + rn && y < n; y++) {
            if (board[x][y] == num) {
                return false;
            }
        }
    }

    return true; // Ensure the function returns true if all checks pass
}

bool Sudoku_Solver(int board[][9], int i, int j, int n){
    //Base Case
    if(i==n){
        cout << "Printing board:\n";
        Print(board, n);
        cout << "Board printed.\n";
        return true;
    }
    //if we are not inside the board
    if(j==n){
        return Sudoku_Solver(board,i+1,0,n);
    }

//if cell already filled just move ahaed
    if(board[i][j]!=0){
        return Sudoku_Solver(board,i,j+1,n);
    }


    //Try to fill the cell with an appropriate num
    for(int num=1;num<=9;num++){
        //check if num can be filled?
        if(isValid(board,i,j,num,n)){
            board[i][j]=num;
            bool subans= Sudoku_Solver(board,i,j+1,n);
            if(subans){
                return true;
            }
            // backtracking undo the changes
            board[i][j]=0;
        }
    }
    return false;
}

int main(){
    int n=9;
    int board[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    Sudoku_Solver(board,0,0,n);
    return 0;
}