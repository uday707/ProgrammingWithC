#include <iostream>
using namespace std;

template<class T>
int sequentialSearch(T a[], int n, const T& x) {
   //Search unordered list a[0:n-1] for x.
   //Return position if found else return -1.
   int i;
   for(i = 0; i< n && a[i] != x; i++ );
   if(i==n) return -1;
   else 
     return i;
}

int main() {
   int a[] = {2,3,6,7,8,5,4,9};
   cout << "index of input " << 1 << " in array is " << sequentialSearch(a, sizeof(a), 1) << endl; 

   int *y = new int(40);
   cout << y << endl;
}