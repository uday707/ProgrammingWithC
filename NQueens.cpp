#include <iostream>
#include "common.h"

using namespace std;

#define N 4

// Utility to check if placing the Queen on
// current board[row][col] will be safe or not
// Note that this function is called when "col"
// queen is already placed on 0 to col - 1.
// So need to check only the left side for 
// attacking queens. 
bool isSafe(int board[N][N], int row, int col) {
   int i, j;
   // Check this row on left side
   for (i = 0; i < col; i++)
       if (board[row][i])
           return false;
   
   // check upper diagonal on left side
   for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
       if (board[i][j])
           return false;

   // check lower diagoal on left side
   for (i = row, j = col; i < N && j >= 0; i++ & j --)
        if (board[i][j])
            return false;

   // Everything is clear, so return true
   return true;                 
}

bool solveNQUtil(int board[N][N], int col) {
  
  if(col >= N)
    return true;

  // consider this column as start and try 
  // try placing this queen in all rows 
  // one by one
  for(int row = 0; row <= N; row++) {
      // check if queen can be placed in 
      // given row and col board[row][col]
      if (isSafe(board, row, col)) {
          board[row][col] = 1;

          // recurrsion to place rest of Queens in columns
          if (solveNQUtil(board, col + 1))
              return true;

          // recursion solution for next column
          // is failed, back-tracking to set current 
          // board[row][col] = false, and move to 
          // next row.
          board[row][col] = 0; // Backtracking 
      }
  }// Iterate to next row.
  
  // if the queen can't be placed in any row of
  // given column, then return false
  return false;
}

void solveNQ() {

    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

   if(solveNQUtil(board, 0) == false) {
    cout << "Solution doesn't exits" << endl;
   }                  

   print(board, N, N);
}

int main() {

  solveNQ();
  return 0;
}