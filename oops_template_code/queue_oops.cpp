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
class Queue{
public:
    Node<T>* front;
    Node<T>* back;

    Queue() {
        front = back = NULL;
    }

    Queue(T val) {
        front = back = Node<T>(val);
    }

    void add(T val) {
        Node<T>* newNode = Node<T>::getNode(val);
        if(front == back && back == NULL) {
            front = back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }

    T remove() {
        if(front == back) {
            T t = front->value;
            front = back = NULL;
            return t;
        }
        T t = front->value;
        front = front->next;
        return t;
    }
};

int main() {
    Queue<int> s;
    s.add(100);
    cout << s.remove() << endl;
    s.add(200);
    cout << s.remove() << endl;
    cout << s.remove() << endl;
    s.add(500);
    s.add(800);
    cout << s.remove() << endl;
    s.add(10);
    cout << s.remove() << endl;
}