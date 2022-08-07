#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// d is number of characters in the input alphabet
#define d 256

/*
 * pat -> patteren 
 * txt -> text
 * q -> a prime number
 */
void search(char pat[], char txt[], int q) {
   int m = strlen(pat);
   int n = strlen(txt);

   int i, j;
   int p = 0; //hash value of patten
   int t = 0; //hash value of txt
   int h = 1;

   //value of hash of pattern would be pwo(d, )
   for(i = 0; i < m -1; i++)
      h = (d * h) % q;

   // calculate the hash value of pattern and first
   // window of text
   for(i = 0; i < m; i++) {
     p = (d * p + pat[i]) % q;
     t = (d * t + txt[i]) % q;
   }

   // slide the pattern over text one by one
   for(i = 0; i <= n -m; i++) {

       //check the hash value of current pattern and 
       //current window of text. if the hash values are
       //matched then only check for charactors one by one.
       if(p == t) {
          //check for charactors one by one
          for(j = 0;j < m; j++) {
             if (pat[j] != txt[i+j]) 
                break;
          }

          if(j == m) {
            cout << "Pattern is found at index " << i << endl;
          }
       }

       // recalcuate next hash value of text: Remove leading 
       //digit, add trailing digit
       if( i < n - m) {
          t = (d *(t - txt[i]*h) + txt[i + m]) % q;

          // if the value of t comes negative, then setting with MAX16_INT
          if (t < 0)
            t = t + q;
       }
   }

}

int main() {
  char txt[] = "GEEKS FOR GEEKS";
  char pat[] = "GEEK";
  int q = INT_MAX;

  search(pat, txt, q);
  return 0;
}