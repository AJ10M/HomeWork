
#include <iostream>

using namespace std;

struct node{
  string data;
  int n;//number
  node* next;
};

class Dict{
  node* head;
public:
  Dict( string a, int b ){
  head = new node;
  head->data = a;
  head->n = b;
  head->next = NULL;
  };

  void push( string a, int b ){
    node* temp = new node;
    temp->next = head;
    temp->data = a;
    temp->n = b;
    head = temp;
  };

  string pop( int b ){
    node* temp = head;
    string a;
    if (temp->next == NULL){
      if(b == temp->n){
        a = temp->data;
        delete temp;
        return a;
      }
      else
        return 0;
    };
    while (temp->next->next != NULL ){
      if (temp->n == b){
        a = temp->data;
        break;
      }
      else
        temp = temp->next;
    };
    if (temp->n == b)
      a = temp->data;
    if (temp->next->n == b)
      a = temp->next->data;
    if(a != temp->data && a != temp->next->data)
      return "no element";
    node* temp1 = temp->next;
    temp = temp->next;
    delete temp1;
    return a;
  };


  ~Dict(){
    while (head != NULL){
    node* temp = head;
    head = head -> next;
    delete temp;
    };
  };
};

int main(){
  int a, b;
  string x = "don't worry";
  string y = "be happy";
  cin>>a>>b;
  Dict obj(x, a);
  obj.push(y, b);
  cout<<obj.pop(a)<<endl;
  cout<<obj.pop(b);
  return 0;
}
