#include <iostream>
#include <stdlib.h>

using namespace std;

int n = 6;
void build_ziggurat( int (&mas)[n][n], int n );

int main()
{
  int mas[n][n];
  build_ziggurat(mas, n);
}

void build_ziggurat( int (&mas)[n][n], int n )
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      mas[i][j] = rand()%10;
      cout << matrix[i][j]<< " ";
    }
    cout << "\n";
}











/*
���������, ����������� ���������� ��������� ������ ���������, ��� �������� � �������.
Input:

6  - ������ �������

Output:

1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1
*/
