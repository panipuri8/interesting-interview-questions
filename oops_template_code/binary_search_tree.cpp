#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
	Node *left, *right;
	T data;
	Node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}
	
	Node(Node* left, T data, Node* right) {
		this->left = left;
		this->right = right;	
		this->data = data;	
	}
};

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;

	void inOrderUtility(Node<T>* cur) {
		if(cur != NULL) {
			inOrderUtility(cur->left);
			cout << cur->data << " ";
			inOrderUtility(cur->right);
		}
	}
	
public:
	BinarySearchTree() {
		root = NULL;	
	}
		
	BinarySearchTree(int data) {
		root = new Node<T>(data);
	}

	void insert(int data) {
		if(root == NULL) {
			root = new Node<T>(data);
			return;
		}
		Node<T>* temp = root;
		while(temp != NULL) {
			if(temp->data > data) {
				if(temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = new Node<T>(data);
					return;
				}
			}
			else {
				if(temp->right != NULL) {
					temp = temp->right;
				}
				else {
					temp->right = new Node<T>(data);
					return;
				}
			}
		}
	}
	
	void inOrder() {
		cout << "The inorder traversal is: ";
		inOrderUtility(root);
		cout << endl;
	}

	//todo delete operation
};


int main() {
	BinarySearchTree<int> tree;
	tree.insert(100);
	tree.insert(20);
	tree.insert(129);
	tree.insert(102);
	tree.insert(101);
	tree.insert(99);
	tree.insert(103);
	tree.insert(1);
	tree.inOrder();
}



