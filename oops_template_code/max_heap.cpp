#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MaxHeap{
private:
	static const int MAXN = 1e3+5;
	T val[MAXN];
	int count;
public:

	MaxHeap() {
		count = 0;
	}

	int parent(int node) {
		return node/2;
	}

	int leftChild(int node) {
		return 2*node;
	}

	int rightChild(int node) {
		return 2*node + 1;
	}

	void push(T value) {
		if(count == 0) {
			count++;
			val[count] = value;
			return;
		}
		count++;
		val[count] = value;
		int curNode = count;
		while(curNode > 1 && val[parent(curNode)] < val[curNode]) {
			swap(val[parent(curNode)], val[curNode]);
			curNode = parent(curNode);
		}
	}

	T pop() {
		if(count == 0) {
			cout << "Heap is empty" << endl;
			return (T)NULL;
		}
		if(count == 1) {
			return val[count--];
		}
		T topValue = val[1];
		val[1] = val[count--];
		int curNode = 1;
		while(leftChild(curNode) <= count) {
			if(rightChild(curNode) <= count) {
				if(val[leftChild(curNode)] <= val[curNode] && val[rightChild(curNode)] <= val[curNode]) {
					break;
				}
				else if(val[leftChild(curNode)] > val[rightChild(curNode)]) {
					swap(val[leftChild(curNode)], val[curNode]);
					curNode = leftChild(curNode);
				}
				else {
					swap(val[rightChild(curNode)], val[curNode]);
					curNode = rightChild(curNode);
				}
			}
			else {
				if(val[leftChild(curNode)] <= val[curNode]) {
					break;
				}
				else {
					swap(val[leftChild(curNode)], val[curNode]);
					curNode = leftChild(curNode);
				}
			}
		}
		return topValue;
	}

	int size() {
		return count;
	}

	bool empty() {
		return (count == 0);
	}
};

int main() {
	MaxHeap<int> heap;
	heap.push(100);
	heap.push(200);
	heap.push(300);
	heap.push(130);
	heap.pop();
	heap.push(120);
	heap.push(200);
	heap.push(700);
	while(!heap.empty()) {
		cout << heap.pop() << endl;
	}
	cout << endl;
	heap.push(100);
	heap.push(102);
	heap.push(100);
	heap.push(700);
	heap.push(1000);
	heap.push(18);
	while(!heap.empty()) {
		cout << heap.pop() << endl;
	}
}