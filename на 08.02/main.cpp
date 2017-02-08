#include <iostream>

using namespace std;

struct node{
  int data;
  node* next;
};

class list{
  node* head;
public:
  list( int a ){
    head = new node;
    head->data = a;
    head->next = NULL;
  }
  ~list(){
    while (head != NULL)
    {
      node* temp = head;
      head = head->next;
      delete temp;
    }
  }


  void push_head( int a ){
    node* temp = new node;
    temp->next = head;
    temp->data = a;
    head = temp;
  }
  void push_back( int a ){
    node* temp = new node;
    if (head == NULL){/*
    temp->next = head;
    temp->data = a;
    head = temp;*/
    push_head(a);
    return;
    }
    temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    node* t = new node;
    temp->next = t;
    t->data = a;
    t->next = NULL;
  }


  int size(){/*размер текущего*/
    int a = 1;
    node* temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
      a++;
    }
    return a;
  }


  int del( int i ){
    node* temp = head;
    if (i == 1)
    {
      head = head->next;
      delete temp;
      return 1;
    }
    for (int j = 1; j < i - 1; j++)
    {
      temp = temp->next;
      if (temp == NULL)
        return 0;
    }
    node* t = temp->next;
    temp->next = temp->next->next;
    delete t;
    return 1;
  }


  int find( int a ){/*поиск элемента*/
    node* temp = head;
    int i = 1;
    while (a != temp->data && temp->next != NULL)
    {
      temp = temp->next;
      i++;
    }
    if (a == temp->data)
      return i;
    return -1;
    }
};

int main()
{
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  list L(a);
  L.push_back(b);
  L.push_head(b);
  cout<<L.size()<<endl;
  cout<<L.del(c)<<endl;
  cout<<L.find(d)<<endl;
  return 0;
}


