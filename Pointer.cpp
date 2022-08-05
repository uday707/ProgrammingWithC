#include <iostream>

using namespace std;

int main() {
   char ch = 'Q';
   char *p;
   p = &ch;
   cout << *p << endl;
   ch = 'Z';
   cout << *p << endl;
   *p = 'X';
   cout << ch << endl;
   p = NULL;
   return 0;
}