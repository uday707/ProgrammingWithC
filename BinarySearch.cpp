#include <iostream>
#include "common.h"

using namespace std;

int binarySearch(int arr[], int num, int size) {
   int left = 0;
   int right = size -1;
   while(right >= left) {
      int middle = (right + left)/2;
      if(arr[middle] == num) {
        return middle;
      }else if(arr[middle] > num) {
        right = middle - 1;
      }else {
        left = middle + 1;
      }
   }
   return -1;
}

int main() {
  int arr[] = {12,15,17,23,27,37,41,49,56,67,73};
  int num;
  cout << "Enter number to search in sorted array" << endl;
  cin >> num;
  cout << "Position of " << num << " in binary search is " << binarySearch(arr, num, 11) << endl;
  return 0;
}