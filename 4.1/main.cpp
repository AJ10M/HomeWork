#include <iostream>
using namespace std;
const int m = 10;
double mas[m];

void quickSort( int a, int b );

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> mas[i];
  quickSort(0, n - 1);
  for (int j = 0; j < n; j++)
    cout << mas[j] << " ";
  return 0;
}

void quickSort( int a, int b )
{
  int x = mas[(b + a) / 2];
  int i = a;
  int j = b;
  while(i <= j)
  {
    while(mas[i] < x)
      i++;
    while(mas[j] > x)
      j--;
    if(i <= j)
    {
      swap(mas[i], mas[j]);
      i++;
      j--;
    }
  }
   if (i < b)
     quickSort(i, b);
   if (a < j)
     quickSort(a, j);
}

