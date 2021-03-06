//�� �����, ��������� �� �� � ���� �������� ?:, �� ����� ����� ����� �� ������������

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
  int key;
  unsigned char height;
  Node* left;
  Node* right;
  Node( int key ){
	this->key = key;
	left = right = NULL;
	height = 1;
  }
};

class Tree{
private:
	Node *head;

	unsigned char getHeight( Node* node ){
		return node ? node->height : 0;
	}

	int bfactor( Node* node ){ // ������(������� �����)
		return getHeight(node->right) - getHeight(node->left);
	}

	void fixHeight( Node* node ){
		unsigned char hl = getHeight(node->left);
		unsigned char hr = getHeight(node->right);
		node->height = (hl > hr ? hl : hr) + 1;
	}

	Node* rotateRight( Node* node ){ //��������
		Node* tmp = node->left;
		node->left = tmp->right;
		tmp->right = node;
		fixHeight(node);
		fixHeight(tmp);
		return tmp;
	}

	Node* rotateLeft( Node* node ){
		Node* tmp = node->right;
		node->right = tmp->left;
		tmp->left = node;
		fixHeight(node);
		fixHeight(tmp);
		return tmp;
	}

	Node* balance( Node* node ){
	  fixHeight(node);
      if (bfactor(node) == 2){
		if (bfactor(node->right) < 0)
          node->right = rotateRight(node->right);
        return rotateLeft(node);
      };
      if (bfactor(node) == -2){
		if (bfactor(node->left) > 0)
		  node->left = rotateLeft(node->left);
        return rotateRight(node);
      };
      return node;
	}

	Node* findMin( Node* node ){// ����� ���� � ����������� ������
		return node->left ? findMin(node->left) : node;
	}

	Node* removeMin( Node* node ){ // �������� ���� � ����������� ������
	  if (node->left == 0)
		return node->right;
	  node->left = removeMin(node->left);
      return balance(node);
	};

	Node* remove( Node* head, int key ){ //key - ��������,������� ���������
	  if (!head)
		return NULL;
      if (key < head->key)
		head->left = remove(head->left, key);
	  else if (key > head->key)
		head->right = remove(head->right, key);
	  else
      {
		Node* l = head->left;
		Node* r = head->right;
		delete head;
		if (!r)
          return l;
        Node* min = findMin(r);
		min->right = removeMin(r);
		min->left = l;
        return balance(min);
      };
	  return balance(head);
	};

	Node* insert( Node* head, int key ){
		if (!head)
			return new Node(key);
		if (key < head->key)
			head->left = insert(head->left, key);
		else
			head->right = insert(head->right, key);
		return balance(head);
	};

	void remove( Tree* tree, int key ){
		remove(tree->head, key);
	};
	void clearTree(Node* node)
	{
		if (node != NULL)
		{
			clearTree(node->left);
			clearTree(node->right);
			free(node);
			node = NULL;
		};
	};
	bool dfs( Node* node, int key )
	{
		if (node == NULL)
			return false;
		if (node->key == key)
			return true;
		if (dfs(node->left, key))
			return true;
		if (dfs(node->right, key))
			return true;
		return false;
	};

public:

	Tree( int key ){
		head = new Node(key);
	};
    Tree( Node* node ){
		head = node;
	};
	~Tree()
	{
		clearTree(head);
	};

	void insert( Tree* tree, int key ){
		insert(tree->head, key);
	};

	bool search( Tree* tree, int key ){
		return dfs(tree->head, key);
	};
};


