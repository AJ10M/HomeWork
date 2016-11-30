#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
  int a[20];
  for (int i=0; i<20; i++)
  {
    a[i] = rand()%20;
    cout<<a[i]<<" ";
  }
  cout<<endl;
  for (int i=0; i<20; i++)
  {
    bool flag=true;
    for (int j=0; j<20; j++)
      if (i-j!=0 && a[i]==a[j])
        flag=false;
      if (flag)
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}


