#include <iostream>
using namespace std;

int* A;
int* B;
int** C;
int* used;
int* M;
int n, m;

void tK(int v){
  if(used[v]) return;
  int max = 0, k = 0;
  used[v] = 1;
  for(int i = 0; i < m; i++)
    if(C[v][i]){
      k++;
      tK(i);
      if(max < M[i]) max = M[i];
    }
    if(k == 0) M[v] = 0;
    else M[v] = max + 1;
}

void matrix(){
  C = new int*[m];
  for(int i = 0; i < m; i++)
    C[i] = new int[m];
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(A[j] == i) C[i][B[j]] = 1;
}

int main(){
  int max = -1, k, k1;
  cin>>n>>m;  //n ребер, m вершин
  A = new int[n];
  B = new int[n];
  M = new int[m];
  used = new int[m];
  for(int i = 0; i < n; i++) cin>>A[i]>>B[i];
  matrix();
  for(int i = 0; i < m; i++) tK(i);
  for(int i = 0; i < m; i++)
    if(max < M[i]){
      max = M[i];
      k = i;
    }
  cout<<k<<" ";
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
      if(M[k] - M[j] == 1 && C[k][j])
      k1 = j;
    k = k1;
    cout<<k<<" ";
  //  if(M[k] == 0) break;
  return 0;
}
