#include <iostream>
#include "../common.h"

#define SHORT_SIZE 16

// function to rotate unsigned short 
// in the left direction
unsigned short leftRotate(unsigned short x, short d) {
  /**
   * by doing, x << d, we move the first (right most) d bits
   * to the left most d bits, and at the same time we move 
   * the left most d bits to the right side,
   * performing OR operation between the two gives use the 
   * required result.
   * 
   */

  return (x << d) | (x >> (SHORT_SIZE -d));
}

using namespace std;

int main() {
  unsigned short n = 28;
  short d = 2;

  cout << leftRotate(n, d) << endl;

  cout << endl << endl;
  return 0;
}