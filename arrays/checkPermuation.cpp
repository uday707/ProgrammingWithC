#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool arePermutation_02(const string &str1, const string &str2) {
   if (str1.length() != str2.length()) 
      return false;

  int count[256] = {0};
  for (int i =0; i< str1.length(); i++) {
      int val = str1[i];
      count[val]++; 
  }
   
  for (int i =0; i< str2.length(); i++) {
      int val = str2[i];
      count[val]--;
      if (count[val] < 0)
         return false;
  }

  return true; 
}

bool arePermutation(string &str1, string &str2) {
  if (str1.length() != str2.length())
      return false;

  // sort both strings as given
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  for (int i =0; i < str1.length(); i++)
      if (str1[i] != str2[i])
          return false;

  return true;
}

int main() {
  
  // test method using sort
  cout << "Method 1: using sort " << endl;
  string str1 = "testest";
  string str2 = "estxest";
  if (arePermutation(str1, str2))
      cout << str1 << " and " << str2 << " are permutation to each other " << endl;
  else
      cout << str1 << " and " << str2 << " aren't permutation to each other " << endl;

  str1 = "hello";
  str2 = "elloh";

  if (arePermutation(str1, str2))
      cout << str1 << " and " << str2 << " are permutation to each other " << endl;
  else
      cout << str1 << " and " << str2 << " aren't permutation to each other " << endl;
  
  // Test method 2: using Character count
  cout << "Method 2: using character count " << endl;
  str1 = "testest";
  str2 = "estxest";
  if (arePermutation_02(str1, str2))
      cout << str1 << " and " << str2 << " are permutation to each other " << endl;
  else
      cout << str1 << " and " << str2 << " aren't permutation to each other " << endl;

  str1 = "hello";
  str2 = "lleho";
  if (arePermutation_02(str1, str2))
      cout << str1 << " and " << str2 << " are permutation to each other " << endl;
  else
      cout << str1 << " and " << str2 << " aren't permutation to each other " << endl;
  
  return 0;
}