#include <iostream>

using namespace std;

class vector{
  int* mas;
  int size;//ск элем сейчас
  int cap;//ск €чеек выделилось
public:
  vector( int a ){
    mas = new int[a];
    size = a;
    cap = 0;
  };
  ~vector(){
    delete mas;
  };

  void push( int a ){
    if (size <= cap){
      append(size*2);
      size *= 2;
    }
    mas[cap] = a;
    cap++;
  };

  int new_size(){
    return cap;
  };

  void append( int n ){
    int* mas1 = new int[n];
    for (int i = 0; i < n; i++)
      mas1[i] = mas[i];
    mas = mas1;
  };

  int find( int a ){
    int i = 0;
    while (a != mas[i] && mas[i + 1] != '\0')
      i++;
    if (a == mas[i])
      return i;
    return -1;
  };
};

int main(){
  int i;
  cin>>i;
  vector obj(i);
  obj.push(i);
  obj.push(i + 1);
  obj.push(i + 2);
  cout<<obj.new_size()<<endl;
  cout<<obj.find(i + 1)<<endl;
  return 0;
}
