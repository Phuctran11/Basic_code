#include<bits/stdc++.h>
using namespace std;

int n, m, M[20][1000000];
int sum = 0;

void preProcess(){
  for(int i = 1; (1 << i) <= n; i++){
    for(int j = 0; j + (1 << i) - 1 < n; j++){
      if(M[i-1][j] < M[i-1][j+(1 << (i-1))]){
        M[i][j] = M[i-1][j];
      }
      else{
        M[i][j] = M[i-1][j+(1 << (i-1))];
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> M[0][i];
  }
  preProcess();
  cin >> m;
  while(m--){
    int i, j, k;
    cin >> i >> j;
    k = (int)log2(j-i+1);
    if(M[k][i] < M[k][j - (1 << k) + 1]){
      sum += M[k][i];
    }
    else sum += M[k][j - (1 << k) + 1];
  }
  cout << sum;
}
