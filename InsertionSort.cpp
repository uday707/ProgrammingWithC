#include <iostream>
#include "common.h"

using namespace std;

template<class T>
void insert(T a[], int n, const T& x) {
   // Insert x into a sorted array a[0:n-1]
   int j = n - 1;
   while (j >= 0 && x < a[j]) {
      a[j+1] = a[j];
      j--;
   }
   a[j + 1] = x;
}

template<class T>
void insertionSort01(T a[], int n) {
   // Sort a[0:n-1] array using insertion sort method.
   for(int i = 1; i < n; i++) {
      T x = a[i];
      insert(a, i, x);
   }
}

template<class T>
void insertionSort02(T a[], int size) {
   for(int i = 1; i < size; i++) {
      // picking element to compare with insertion list;
      T x = a[i];
      // Checking element x with already sorted list.
      int j;
      for(j = i -1; j >= 0 && x < a[j]; j--) {
          a[j+1] = a[j];
      }
      a[j+1] = x;
   }
}

int main() {
   int a[] = {3,2,5,7,1,9,4};
   insertionSort02(a, 7);
   cout << "Array a = "; print(a, 7);

   return 0;
}