#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getCharNumber(const char &ch) {
   int a = (int) 'a';
   int z = (int) 'z';
   int A = (int) 'A';
   int Z = (int) 'Z';

   int val = (int) ch;

   if (a <= val && val <= z) 
       return val - a;

   if (A <= val  && val <= Z)
       return val  - A;

    return -1;
}

vector<int> buildCharFrequencyTable(string phrase) {
    vector<int> table (getCharNumber('z') - getCharNumber('a') + 1, 0);
    for (int i =0; i < phrase.length(); i++) {
        int val = getCharNumber(phrase[i]);
        if (val != -1)
            table[val]++;
    }
    return table;
} 

bool checkMaxOneOdd(vector<int> &table) {
  bool foundOdd = false;
  for (int i =0; i< table.size(); i++) {
       if (table[i] % 2 == 1) {
           // maximum only one odd is allowed in string if, more than
           // one odd are found then string is not palindrome, 
           // zero odd is also valid condition. 
           if (foundOdd) {
              return false;
           }
           foundOdd = true;
       }
  }
  return true;
}

bool isPalindromePermutation(const string &phrase) {
   vector<int> table = buildCharFrequencyTable(phrase);
   return checkMaxOneOdd(table);
}

int main() {

  string pali = "Rats live on no evil star";
  string isPermutation = isPalindromePermutation(pali) ? "yes" : "no";

  cout << pali << " is permutation = " << isPermutation << endl;

  return 0; 
}