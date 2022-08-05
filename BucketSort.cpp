#include <iostream>
#include <vector>
#include <algorithm>
#include "common.h"

using namespace std;

void bucketSort(float arr[], int n) {
   // create empty n buckets
   vector<float> b[n];

   // put array elements in different buckets
   for(int i =0; i < n; i++) {
      int bi = n * arr[i]; // index in bucket
      b[bi].push_back(arr[i]);
   }

   // sort individual buckets
   for(int i =0; i< n; i++)
    sort(b[i].begin(), b[i].end());

  // concatenate all bucket elements into arr[]
  int index = 0;
  for(int i =0; i<n; i++) 
     for(int j=0; j < b[i].size(); j++)
       arr[index++] = b[i][j];

}

int main() {
    float arr[] = {0.897, 0.656, 0.1234, 0.665, 0.3434};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Printing array before sort: " << endl;
    print(arr, size);

    bucketSort(arr, size);
    cout << "Printing array after sort: " << endl;
    print(arr, size);

}