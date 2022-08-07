#include <iostream>
#include "common.h"

using namespace std;

#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

bool isSafe(int maze[N][N], int x, int y) {
   // if x & y are outsite the maze or current position is invalid,
   // then return false
   if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
      return true;
   return false;
}

bool solveMaze(int maze[N][N]) {
  int sol[N][N] = {{0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {0, 0, 0, 0}};
   if(solveMazeUtil(maze, 0, 0, sol) == false) {
      cout << "Solution doesn't exists.";
      return false;
   }
   print(sol, N, N);
   return true;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
  // if x and y is goal, then return true
  if(x == N -1 && y == N -1 && maze[x][y] == 1) {
    sol[x][y] = 1;
    return true;
  }

  // check if maze[x][y] is valid
  if(isSafe(maze, x, y) == true) {
     // check if current maze position is already
     // in the solution path.
     if(sol[x][y] == true) 
        return false;
     
     // Setting current position as part of solution
     sol[x][y] = 1;

     // move forward in x direction
     if(solveMazeUtil(maze, x + 1, y, sol) == true)
        return true;

      // if moving forward in x doesn't work, then
      // move down and try in y direction
      if(solveMazeUtil(maze, x, y + 1, sol) == true)
         return true;
        
      // now, moving in both x & y direction does work
      // setting current path not possible and return false
      sol[x][y] = 0;
  }
  return false;
}

int main() {
  int maze[N][N] = {{1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 0, 0},
                    {1, 1, 1, 1}};

  cout << "Maze topgraphy to find path" << endl;
  cout << "-------------------------------------" << endl;
  print(maze, N, N);
  cout << "-------------------------------------" << endl;
  cout << "Maze Solution Path: " << endl;
  cout << "-------------------------------------" << endl;
  solveMaze(maze);
  cout << endl << endl;                   
  return 0;
}