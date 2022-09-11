#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../common.h"

using namespace std;

void findPermutations(string curr, map<char, int> m, vector<string> &res, int length) {
   int curr_length = curr.length();
   if(curr_length == length) {
      res.push_back(curr);
      return;
   }

   for (map<char, int>::iterator i = m.begin(); i != m.end(); i++) {
      if (i->second != 0) {
          char c = i -> first;
          string f = curr + c;
          i->second--;
          findPermutations(f, m, res, length);
          i->second++; 
      }
   }
}


int main() {

   string str = "abbc";
   string curr = "";
   map<char, int> m;
   int n = str.length();
  // stroring the count of charactors of string in map
  for (int i =0; i < n; i++) {
    if(m.find(str[i]) != m.end()) {
       m.find(str[i])->second++;
    }else {
      m.insert(make_pair(str[i], 1));
    }
  }

  vector<string> res;
  findPermutations(curr, m, res, n);
  print(res);

  return 0;
}