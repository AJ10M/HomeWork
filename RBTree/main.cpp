#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct node{
  int data;
  node *left = NULL;
  node *right = NULL;
  node *p = NULL;//parent
  bool color;
};


class RBtree{
  node *root = NULL;

  void rotateLeft( node *a ) {
    node* b = a->right;
    a->right = b->left;
	if (b->left != NULL)
      b->left->p = a;
	if (b != NULL)
      b->p = a->p;
	if (a->p != NULL){
      if (a == a->p->left)
		a->p->left = b;
      else
		a->p->right = b;
    };
	if (a->p = NULL)
      root = b;
    b->left = a;
	if (a != NULL)
	  a->p = b;
  }

  void rotateRight( node *a ){
	node *b = a->left;

	a->left = b->right;
	if (b->right != NULL)
      b->right->p = a;
    if (b != NULL)
      b->p = a->p;
    if (a->p != NULL) {
      if (a == a->p->right)
		a->p->right = b;
      else
        a->p->left = b;
    };
    if (a->p = NULL)
      root = b;
	b->right = a;
    if (a != NULL)
      a->p = b;
	};


  void Insert( node *a ){
	while (a != root && a->p->color == 1) {
      if (a->p == a->p->p->left) {
        node *b = a->p->p->right;
        if (b->color == 1) {
          a->p->color = 0;
          b->color = 0;
          a->p->p->color = 1;
          a = a->p->p;
        }
        else {
		  if (a == a->p->right) {
            a = a->p;
			rotateLeft(a);
          }
       	  a->p->color = 0;
		  a->p->p->color = 1;
		  rotateRight(a->p->p);
        };
     }
	 else{
       node *b = a->p->p->left;
         if (b->color == 1){
	 	   a->p->color = 0;
           b->color = 0;
           a->p->p->color = 1;
		   a = a->p->p;
         }
         else{
           if (a == a->p->left){
			 a = a->p;
			 rotateRight(a);
           };
		   a->p->color = 0;
		   a->p->p->color = 1;
		   rotateLeft(a->p->p);
         };
     };
  };
	root->color = 0;
 };

public:

	node *insertNode( int data ) {
		node *p, *t;//текущий

		t = root;
		p = 0;
		while (t != NULL) {
			if (data == (t->data))
              return (t);
			p = t;
			t = (data < (t->data) ? t->left : t->right);
		}
		node* x = new node;
		x->data = data;
		x->p = p;
		x->left = NULL;
		x->right = NULL;
		x->color = 1;

		if (p != NULL) {
			if (data < (p->data))
				p->left = x;
			else
				p->right = x;
		}
		else
			root = x;
		Insert(x);
		return(x);
	};

	node *getRoot() {
		return root;
	};

	void print( node *tree ) {
		if (tree != NULL) {
			print(tree->left);
			cout << tree->data << endl;
			print(tree->right);
		}
	}

	void clear( node *tree ) {
		if (tree != NULL) {
			print(tree->left);
			tree = NULL;
			print(tree->right);
		}
	};

	~RBtree(){
		this->clear(root);
	};
};


int main() {
	int n;
	cin >> n;
	RBtree A;
	for (int i = 0; i < n; ++i){
      int a;
      cin >> a;
      A.insertNode(a);
	};
	A.print(A.getRoot());
	system("pause");
	return 0;
}
