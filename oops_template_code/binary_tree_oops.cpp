#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
public:
	Node *left, *right;
	T value;

	Node(T value)  {
		this->value = value;
		left = right = NULL;
	}

	Node() {
		left = right = NULL;
	}
};

template <typename T>
class BinaryTree {
private:
	Node<T>* root;
public:

	BinaryTree(T val) {
		root = new Node<T>(val);
	}

	BinaryTree() {
		root = NULL;
	}

	void insert(T val) {
		if(root == NULL) {
			root = new Node<T>(val);
			return;
		}
		Node<T>* temp = this->root;
		queue<Node<T>*> q;
		q.push(temp);
		while(!q.empty()) {
			Node<T>* front = q.front();
			q.pop();
			if(front->left == NULL) {
				front->left = new Node<T>(val);
				break;
			}
			else if(front->right == NULL) {
				front->right = new Node<T>(val);
				break;
			}
			q.push(front->left);
			q.push(front->right);
		}
	}

	void bfs() {
		if(root == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		Node<T>* temp = this->root;
		queue<Node<T>*> q;
		q.push(temp);
		while(!q.empty()) {
			Node<T>* front = q.front();
			cout << front->value << " ";
			q.pop();
			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
		cout << endl;
	}

	void dfs() {
		if(root == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		stack<Node<T>*> s;
		Node<T>* temp = root;
		while(true) {
			while(temp != NULL) {
				s.push(temp);
				temp = temp->left;
			}
			if(temp == NULL && !s.empty()) {
				temp = s.top();
				s.pop();
				cout << temp->value << " ";
				temp = temp->right;
			}
			else {
				break;
			}
		}
		cout << endl;
	}
};

int main() {
	BinaryTree<string> tree;
	tree.insert("akshay");
	tree.insert("omg");
	tree.insert("hello");
	tree.insert("okok");
	tree.dfs();
	tree.insert("hey");
	tree.dfs();	
}