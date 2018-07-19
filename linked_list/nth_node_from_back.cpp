#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
};

node* add_to_head(node* head, int data) {
	node* newHead = new node;
	newHead->data = data;
	newHead->next = head;
	return newHead;
}

void print(node* head) {
	cout << "linked list is " ; 
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void print_nth_from_last(node* head, int n) {
	node* fast = head; node* slow = head;
	int i = 1;
	while(fast && i<n) {
		i++;
		fast = fast->next;
	}
	if(fast == NULL) {
		cout << "[n-" << n-1 << "]th element is not valid indexing for this linked list " << endl;
		return;
	}
	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	cout << "[n-" << n-1 << "]th element is " << slow->data << endl;
}

int main() {
	node* root = add_to_head(NULL, 10);
	for(int i=1;i<=9;i++) {
		root = add_to_head(root, i);
	}
	print(root);
	for(int i=1;i<=15;i++) {
		print_nth_from_last(root, i);
	}
}