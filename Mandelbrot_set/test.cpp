#include<iostream>

using namespace std;

int main() {
  int M[1005][1005];
  int n = 1000;
  for(int i = 0;i<n;i++) {
    for(int j = 0; j<n;j++) {
      M[j][i] = i*j;
    }
  }
}