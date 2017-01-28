#include <iostream>


/*НЕ ДОДЕЛАНО ПОКА ЧТО*/

using namespace std;

class String {
  char mas[100];
public:
  String();
  ~String();
  void Concat( string s );
  int Find( string s );
};

String::String()
{
  cout<< "Инициализировано";
}

String::~String()
{
  cout<< "Разрушено";
}

void Concat( string s )
{
  string tmp = mas;
  int i = 0, SizeT = mas.size;//размер строки
  mas = malloc (SizeT + s.size() - 1);
  while( i < SizeT - 1 )
    mas[i] = tmp[i++];
  while( i < SizeT + s.size - 1 )
    mas[i] = s[i++ - SizeT];
}

int find( string s )
{
  int i = 0, k = 0;
  while( mas[i] != 0 )
  {
    if (mas[i] == s[k])
      i++, k++;
    else
      i++, k = 0;
    if (s[k] == 0)
      return i - k;
  }
  return -1;
}












int main()
{

    return 0;
}
