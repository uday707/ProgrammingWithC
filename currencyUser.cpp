#include <iostream>
#include "currency.h"

using namespace std;

int main() {

  currency g, h(positive, 3, 50), i, j;

  // setting the value of g
  g.setValue(positive, 2, 25);
  i.setValue(6.45);

  // do an add and output
  j = h + g;
  cout << h << endl;

  cout << " + ";
  cout << g << endl;

  cout << " = ";
  cout << "j output before do in sequence " << endl;
  cout << j << endl;
  
  cout << "j output after do in sequence " << endl;
  // do add in sequence
  j = i + g + h;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;

  // output sequence is omitted
  j += i;
  cout << "j output after increment method" << endl;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  
  return 0; 
}