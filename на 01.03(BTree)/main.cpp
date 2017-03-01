#include <iostream>
#include <queue>

using namespace std;

struct node{
  int data;
  node* left = NULL;
  node* right = NULL;
};

class BT{
  node* root;
public:
  BT( int a ){
    root = new node;
    root->data = a;
    root->left = NULL;
    root->right = NULL;
  };

  node* get(){
    return root;
  }

  void push( int a, node* n ){
    if (n == NULL){
      node* tmp = new node;
      tmp->data = a;
      tmp->left = NULL;
      tmp->right = NULL;
      n = tmp;
      return;
    }
    if (n->left == NULL){
      node* tmp = new node;
      tmp->data = a;
      tmp->left = NULL;
      tmp->right = NULL;
      n->left = tmp;
      return;
    }
    if (n->right == NULL){
      node* tmp = new node;
      tmp->data = a;
      tmp->left = NULL;
      tmp->right = NULL;
      n->right = tmp;
      return;
    }
    if (n->right->right != NULL)
      push(a, n->left);
    else
      push(a, n->right);
    return;
  };

  int pop(){
    if (root == NULL)
      return 0;
    node* tmp = root;
    int a;
    if (tmp->right == NULL){
      if (tmp->left == NULL){
        a = tmp->data;
        delete tmp;
        root = NULL;
        return a;
      }
      a = tmp->left->data;
      delete tmp->left;
      root->left = NULL;
      return a;
    }
    while (tmp->left->right != NULL)
      tmp = tmp->left;
    if (tmp->left->left != NULL){
      a = tmp->left->left->data;
      delete tmp->left->left;
      tmp->left->left = NULL;
      return a;
    }
    if(tmp->right->right != NULL){
      a = tmp->right->right->data;
      delete tmp->right->right;
      tmp->right->right = NULL;
      return a;
    }
    if (tmp->right->left != NULL){
      a = tmp->right->left->data;
      delete tmp->right->left;
      tmp->right->left = NULL;
      return a;
    }
    if (tmp->right != NULL){
      a = tmp->right->data;
      delete tmp->right;
      tmp->right = NULL;
      return a;
    }
    a = tmp->left->data;
    delete tmp->left;
    tmp->left = NULL;
    return a;
  };

  bool DFS( int data, node* n ){
    if(n == NULL)
      return false;
    if (n->data == data)
      return true;
    if (DFS(data, n->left))
      return true;
    if (DFS(data, n->right))
      return true;
    return false;
   };

  bool BFS( int data ){
    queue <node*> A;
    A.push(root);
    while(!A.empty()){
      node* tmp = A.front();//метод очереди
      A.pop();
      if (tmp->data == data)
        return 1;
      if (tmp->left != NULL)
        A.push(tmp->left);
      if (tmp->right != NULL)
        A.push(tmp->right);
    }
    return false;
  };

  void delT(node* n){
    if (n == NULL)
      return;
    delT(n->left);
    delT(n->right);
    delete n;
  };
  ~BT(){
    delT(root);
  };
};

int main(){
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  BT obj(a);
  obj.push(b, obj.get());
  obj.push(c, obj.get());
  obj.push(d, obj.get());
  cout<<obj.DFS(d, obj.get())<<endl;
  cout<<obj.BFS(c)<<endl;
  cout<<obj.pop()<<endl;
  cout<<obj.pop()<<endl;
  cout<<obj.pop()<<endl;
  cout<<obj.pop()<<endl;
  return 0;
}
