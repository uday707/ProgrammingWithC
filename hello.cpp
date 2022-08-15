#include <iostream>

using namespace std;

void myfunc(int &x) {
  x = 5;
}

int func(int &x) {
  x  = x + 3;
  return x;
}

int main() {
   int a = 3;
   int b = 4;

   int* pointerToA = &a;
   int* pointerToB = &b;
   int* p = pointerToA;
   p = pointerToB;
   cout << a << " " << b << " " << *p << endl;

   // reference example
   int& referenceToA = a;
   int& referenceToB = b;
   int& r = referenceToA;
   // now changing reference to B;
   r = referenceToB;
   cout << a << " " << b << " " << r << endl;

  int x = 7;
  myfunc(x);
  cout << "value of x = " << x << endl;

  int i = 7;
  int j;
  j = func(i);
  cout << "i = " << i << " j = " << j << endl; 

  int k = 5;
  int& ref_of_k = k;

  // now modifying k modifies the ref_of_k 
  k = 7;
  cout << "value of ref_of_k = " << ref_of_k << endl;

  // modifying the ref_of_k modifies the actual value of k
  ref_of_k = 9;
  cout << "value of k = " << k << endl;

  int l = 3;
  int* ptr_to_l = &l;

  //modify the l also modifies the pointer to l
  l = 5;
  cout << "ptr_to_l = " << *ptr_to_l << endl;

  // now modify the pointer to l which modify the actual value
  // l also
  *ptr_to_l = 7;
  cout << "value of l = " << l << endl; 

}

