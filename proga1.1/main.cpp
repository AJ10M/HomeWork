#include <iostream>

using namespace std;

int NOD( int a, int b );

int main()
{
  int a, b;
  double NOC;
  cout << "Input A: ";
  cin >> a;
  cout << "Input B: ";
  cin >> b;
  NOC = a * b / NOD(a, b);
  cout << "NOC: " << NOC;
  return 0;
}

int NOD( int a, int b )
{
  double c = a % b;
  while (c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

