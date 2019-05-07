#include<bits/stdc++.h>
using namespace std;

class BinaryIndexedTree{
private:
	static const int MAXN = 1e3+5;
	int val[MAXN];
public:
	void update(int index, int value) {
		while(index < MAXN){
			val[index]+=value;
			index+=(index&(-index));
		}
	}

	long long query(int index) {
		long long answer = 0;
		while(index > 0) {
			answer+=val[index];
			index-=(index&(-index));
		}
		return answer;
	}

	long long query(int left, int right) {
		if(left > right) {
			return 0;
		}
		return query(right) - query(left - 1);
	}
};

int main() {
	BinaryIndexedTree tree;
	tree.update(1, 100);
	tree.update(2, 10);
	tree.update(3, 5);
	tree.update(1, 8);
	cout << tree.query(3, 3) << endl;
}