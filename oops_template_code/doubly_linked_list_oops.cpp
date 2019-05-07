#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node{
public:
	Node *left, *right;
	T value;

	Node() {
		left = right = NULL;
	}

	Node(T val) {
		left = right = NULL;
		value = val;
	}
};

template <class T>
class DoublyLinkedList{
	Node<T>* head;

public:
	DoublyLinkedList() {
		head = NULL;
	}

	DoublyLinkedList(T val) {
		head = new Node<T>(val);
	}

	void push_front(T val) {
		Node<T>* newNode = new Node<T>(val);
		if(head == NULL) {
			head = newNode;
			return;
		}
		head->left = newNode;
		newNode->right = head;
		head = newNode;
	}

	void push_back(T val) {
		Node<T>* newNode = new Node<T>(val);
		if(head == NULL) {
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		while(temp->right != NULL) {
			temp = temp->right;
		}
		temp->right = newNode;
		newNode->left = temp;
	}

	void remove(T value) {
		if(head->value == value) {
			if(head->right != NULL)	
				head->right->left = NULL;
			head = head->right;
			return;
		}
		Node<T>* temp = head;
		while(temp && temp->value != value) {
			temp = temp->right;
		}
		if(temp == NULL) {
			cout << "Specified value " << value << " does not exist in list" << endl;
			return;
		}
		if(temp->left != NULL) {
			temp->left->right = temp->right;
		}
		if(temp->right != NULL) {
			temp->right->left = temp->left;
		}
	}

	void print() {
		Node<T>* temp = this->head;
		while(temp) {
			if(temp->right != NULL)
				cout << temp->value << "->";
			else 
				cout << temp->value;
			temp = temp->right;
		}
		cout << endl;
	}

	void reverse();
};

template <typename T>
void DoublyLinkedList<T>::reverse() {
	if(this->head == NULL || this->head->right == NULL) {
		return;
	}
	Node<T>* cur = this->head;
	Node<T>* prev = (Node<T>*) NULL;
	while(cur != NULL) {
		Node<T>* next = cur->right;
		cur->right = prev;
		cur->left = next;
		prev = cur;
		cur = next;
	}
	head = prev;
}

int main() {
	DoublyLinkedList<int> l = DoublyLinkedList<int>();
	l.push_back(100);
	for(int i=2;i<=8;i++) {
		l.push_back(i);
	}
	l.push_front(10);
	l.print();
	l.reverse();
	l.print();
	l.remove(5);
	l.print();
	l.reverse();
	l.print();
}