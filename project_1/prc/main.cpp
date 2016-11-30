#include <iostream>

using namespace std;

int main()
{
  int n;
  double x, p, a[n];
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>p;
    a[i] = p;

  cin>>x;
//ret f()


  if (x < a[n/2])
    for (int i1 = 0; i1 < n/2; i1++)
      if (x == a[i1]) cout<<"ok";
  else if (x == a[n/2]) cout<<"ok";
  else
    for (int i2 = 0; i2 > n/2; i2++)
      if (x == a[i2]) cout<<"ok";


  return 0;
}

/*f(*a, x, m, n)
if if
return f(a, x, n/2, n)*/
