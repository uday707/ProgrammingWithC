#include <iostream>
#include <vector>
#include <string>
#include "../common.h"

using namespace std;

void findPermutations(string s, string curr, vector<string> &res) {
     int n = s.size();
     if(!n) {
      res.push_back(curr);
      return;
     }

     for (int i =0; i < n; i++) {
        string first = curr + s.substr(i, 1);
        string rem = s.substr(0, i) + s.substr(i+1, n -i -1);
        findPermutations(rem, first, res);
     }
       
}

int main() {
   string s = "abcd";
   string curr = "";
   vector<string> res;
   findPermutations(s, curr, res);
   print(res);
   return 0;
}