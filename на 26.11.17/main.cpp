#include <iostream>
using namespace std;

int* A;
int* B;
int** C;
int timer = 0, n, m;
int* fup;
int* tin;
int* used;


int Rb(int a, int b){
  for(int i = 0; i < n; i++)
    if((A[i]==a&&B[i]==b)||(A[i]==b&&B[i]==a)) return i;
}

void dfs1 (int v, int p = -1){
  int** C;
  used[v] = 1;
  tin[v] = fup[v] = timer++;
  for (int i = 0; i < m; i++)
    if(C[v][i]){
      int t0 = i;
      if(t0 == p) continue;
      if(used[t0]) fup[v] = min(fup[v], tin[t0]);
      else{
        dfs1(t0, v);
        fup[v] = min(fup[v], fup[t0]);
        if(fup[t0] > tin[v]) cout « Rb(v, t0) « " ";
      }
    }
}

void matrix1(){
  C = new int*[m];
  for(int i = 0; i < m; i++)
    C[i] = new int[m];
  for(int j = 0; j < m; j++)
    for(int k = 0; k < n; k++){
      if(A[k] == l) C[l][B[k]] = 1;
      if(B[k] == l) C[l][A[k]] = 1;
    }
}

int main(){
  cin » n » m;//n-ðåáåð, m-âåðøèí;
  A = new int[n];
  B = new int[n];
  for(int i = 0; i < n; i++)
    cin » A[i] » B[i];
  tin = new int[m];
  fup = new int[m];
  used = new int[m];
  matrix1();
  dfs1(0);
  return 0;
}

