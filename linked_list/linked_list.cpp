#include<iostream>

using namespace std;

struct node{
    node* next;
    int value;
    node() {
        next = NULL;
    }

    node(int val) {
        next = NULL;
        value = val;
    }
};

node* insert(node* head, int value) {
    node* newNode = new node(value);
    newNode->next = head;
    return newNode;
}

void delete_node(node* &head, int value) {
    if(head->value == value) {
        head = head->next;
        return;
    }
    node* temp = head;
    while(head->next && head->next->value != value) {
        head = head->next;
    }
    if(head->next && head->next->value == value) {
        head->next = head->next->next;
    }
    head = temp;
}

void print(node* head) {
    while(head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    node* head = new node(20);
    head = insert(head, 50);
    head = insert(head, 20);
    head = insert(head, 100);
    for(int i=1;i<=10;i++) {
        head = insert(head, i);
    }
    print(head);
    delete_node(head, 10);
    print(head);
    delete_node(head, 5);
    print(head);
    delete_node(head, 20);
    print(head);
    delete_node(head, 20);
    print(head);
    delete_node(head, 50);
    print(head);
    delete_node(head, 100);
    print(head);
}