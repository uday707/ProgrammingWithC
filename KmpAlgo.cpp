#include <iostream>
#include "common.h"
#include <cstring>

using namespace std;
void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt) {
  int M = strlen(pat);
  int N = strlen(txt);
  
  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  int lps[M];
  computeLPSArray(pat, M, lps);

   int i = 0; // index for text
   int j = 0; // index for pattern
   while((N -i) >= (M -j)) {
      if(pat[j] == txt[i]) {
        j++;
        i++;
      }

      if(j == M) {
        cout << "pattern is found at " << i - j << endl;
        //setting the value of j with lps array
        j = lps[j -1];
      }
      // mismatch after j matches
      else if( i < N && pat[j] != txt[i]) {
          // don't match lps[0...lps[j-1]] characters,
          // they will match anyway
          if (j != 0) 
              j = lps[j -1];
          else
              i = i + 1;
      }


   }
}

void computeLPSArray(char* pat, int M, int* lps) {
   // length of previous longest prefix & suffix
   int len = 0;

   lps[0] = 0; // lps[0] is always zero
   int i = 1;
   while (i < M) {
     if (pat[i] == pat[len]) {
        len++;
        lps[i] = len;
        i++;
     } else { // pat[i] != pat[len]
        // this is tricky, consider the example.
        // AAACAAAA and i = 7, this idea is similiar
        // search step.
        if(len != 0) {
           len = lps[len -1];
           // also node that we don't increment i here.
           // and value of len decrement again and again
           // for given value of i (doesn't change).
        }else { 
           // if len == 0
           lps[i] = 0;
           i++;
        }
     }
   }
}

int main() {
  char txt[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABAB";
  cout << "text = " << txt << " | pattern = " << pat << endl;
  KMPSearch(pat, txt);
  cout << endl << endl;
  return 0;
}