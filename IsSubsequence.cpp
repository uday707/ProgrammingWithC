// Recursive C++ program to check
// if a string is subsequence of 
// another string
#include <cstring>
#include <iostream>

using namespace std;

bool isSubsequence(char str1[], char str2[], int m, int n) {
   if(m == 0)
     return true;
   
   if(n == 0) 
     return false;

    // if last two charactor if string are matching
    // then return 
    if(str1[m -1] == str2[n -1]) 
       return isSubsequence(str1, str2, m -1, n -1);

    // strings are not matched, then moving to match next charactor in
    // next main string
    return isSubsequence(str1, str2, m, n -1);
}

int main() {
  char str1[] = "gksrek";
  char str2[] = "geeksforgeeks";
  int m = strlen(str1);
  int n = strlen(str2);

  cout << "str1 is subsequence of str2: " << (isSubsequence(str1, str2, m, n) ? "Yes" : "No") << endl;
  return 0;
}