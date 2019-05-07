#include <iostream>

using namespace std;

template <class T>
class Node{
public:
	Node* next;
	T value;

	Node() {
		next = NULL;
	}

	Node(T val) {
		next = NULL;
		value = val;
	}
};

template <class T>
class LinkedList{
	Node<T>* head;

public:
	LinkedList() {
		head = NULL;
	}

	LinkedList(T val) {
		head = new Node<T>(val);
	}

	void insert(T val) {
		Node<T>* newNode = new Node<T>(val);
		newNode->next = head;
		head = newNode;
	}

	void remove(T value) {
		if(head->value == value) {
	        head = head->next;
	        return;
	    }
	    Node<T>* temp = head;
	    while(head->next && head->next->value != value) {
	        head = head->next;
	    }
	    if(head->next && head->next->value == value) {
	        head->next = head->next->next;
	    }
	    head = temp;
	}

	void print() {
		Node<T>* temp = this->head;
		while(temp) {
			if(temp->next != NULL)
				cout << temp->value << "->";
			else 
				cout << temp->value;
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse();
};

template <typename T>
void LinkedList<T>::reverse() {
	if(this->head == NULL || this->head->next == NULL) {
		return;
	}
	Node<T>* cur = this->head;
	Node<T>* prev = (Node<T>*) NULL;
	while(cur != NULL) {
		Node<T>* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}


int main(){
	LinkedList<int> linkedList = LinkedList<int>(15);
	linkedList.insert(10);
	linkedList.insert(12);
	linkedList.insert(30);
	linkedList.insert(13);
	linkedList.print();
	linkedList.reverse();
	linkedList.print();
	linkedList.insert(20);
	linkedList.print();
	linkedList.remove(12);
	linkedList.print();
	linkedList.reverse();
	linkedList.print();
}