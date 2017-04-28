#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){                                                             //C = (M^e) % n,  M = (C^d) % n
  int p = 3557, q = 2579, n, m = 111111, m1 = 1, m2 = 1, d = 1, e = 3;  //e и n - открытый ключ, d Ч закрытый
  n = p*q;
  while ((d*e) % ((p - 1)*(q - 1)) != 1)
    d++;
  for (int i = 0; i < e; i++){
    m1 *= m;
    m1 %= n;
  }
  for (int i = 0; i < d; i++){
    m2 *= m1;
    m2 %= n;
  }
  cout<<m2;
  return 0;
}/*
m - то что шифруетс€
m1 зашифрованное
m2 расшифрованное*/
