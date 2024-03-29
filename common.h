#include <iostream>
#include <vector>
using namespace std;

/* Define a large enough value 
   that value will be used for 
   vertices that are not connected
   to each other
*/
#define INF 99998765

template<class T>
void print(T a[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
     if (i < n -1)
        cout << a[i] << ", ";
     else 
        cout << a[i];
  }
  cout << "]" << endl; 
}


template<class T>
void print(T* mat, int row, int col) {
   for (int i = 0; i < row; i++) {
        for (int j =0; j < col; j++) {
           if (mat[i][j] == INF)
               cout << " INF ";
            else 
               cout << " " << mat[i][j] << " ";
        }
         cout << endl;
   }
}

// utility method to print the contents of vector
template<class T> 
void print(vector<T> &v) {
   cout << "Vector: [";
   for (int i =0; i < v.size(); i++) {
      if (i < v.size() -1)
         cout << v[i] << ", ";
      else
         cout << v[i];
   }
   cout << "]" << endl;
        
}
// Utility method to swap two values
template<class T>
void swap(T* x, T* y) {
   T temp = *x;
   *x = *y;
   *y = temp;
}