#include <iostream>
using namespace std;

void outer_points();

int main()
{
  outer_points();
  return 0;
}

void outer_points()
{
  int n, m;
  cin>>n>>m;
  int a[n], b[n], k[m], prov[m];
  for (int i = 0; i < n; i++)
    cin>>a[i]>>b[i];
  for (int i = 0; i < m; i++)
  {
    cin>>k[i];
    prov[i]=n;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if ((k[i] <= b[j]) && (k[i] >= a[j]))
        prov[i] -= 1;
  for (int i = 0; i < m; i++)
    cout<<prov[i]<<' ';
}

