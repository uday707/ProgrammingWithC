#include <iostream>

using namespace std;

int main() {
  float *x;
  try {
    x = new float[100];
  }catch(bad_alloc e) {
    cerr << "out of memory" << endl;
  }
 
}