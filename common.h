#include <iostream>
using namespace std;

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
