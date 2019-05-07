#include<bits/stdc++.h>
using namespace std;

template<typename T>
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

    static Node* getNode(T val) {
        Node<T>* newNode = new Node;
        newNode->next = NULL;
        newNode->value = val;
        return newNode;
    }
};

template <typename T>
class Stack{
public:
    Node<T>* top;

    Stack() {
        top = NULL;
    }

    Stack(T val) {
        top = Node<T>(val);
    }

    void push(T val) {
        Node<T>* newNode = Node<T>::getNode(val);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if(top == NULL) {
            return NULL;
        }
        Node<T>* t = top;
        top = top->next;
        return t->value;
    }
};

int main() {
    Stack<int> s;
    s.push(100);
    s.push(200);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(500);
    s.push(800);
    cout << s.pop() << endl;
    s.push(10);
    cout << s.pop() << endl;
}