#include <iostream>
#include <cstring>

using namespace std;

void search(const char pat[], const char str[]) {
  int M = strlen(pat);
  int N = strlen(str);

  // searching for string to the pattern length
  for(int i =0; i < N - M; i++) {
      
      int j =0;
      while(j < M) {
        if (pat[j] != str[i + j])
           break;
        j++;   
      }

      if(j == M)
        cout << "Pattern is found at location = " << i << endl;
  }
}

int main() {
  char txt[] = "AABAACAADAABAAABAA";
  char pat[] = "AABA";
  search(pat, txt);
  return 0;
}