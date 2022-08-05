#include <iostream>

using namespace std;

class gcd {
  public:
    gcd() {
      cout << "creating gcd object " << endl;
    }
    ~gcd() {
      cout << "destorying the gcd object" << endl;
    }
    int fetch(int x, int y) {
      if(x == 0) {
         return y;
      }else if(y == 0) {
         return x;
      }else {
        return fetch(y, x % y);
      }
  }
};


int main() {
  gcd* g = new gcd;
  cout << "gcd of 20 & 30 is " << g -> fetch(112, 42) << endl << endl;

  delete g;
}
