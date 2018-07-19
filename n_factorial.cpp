#include<bits/stdc++.h>

using namespace std;

int res[500];

int multiply(int res[], int x, int size) {
	int carry = 0;
	for(int i=0;i<size;i++) {
		int hmm = res[i] * x + carry;
		res[i] = hmm%10;
		carry = hmm/10; 
	}
	int hmm = size;
	while(carry) {
		res[hmm] = carry%10;
		carry/=10;
		hmm++;
	}
	return hmm;
}

void factorial(int n) {
	res[0] = 1;
	int size = 1;	
	for(int i=2;i<=n;i++) {
		size = multiply(res, i, size);
	}
	for(int i=size-1;i>=0;--i) {
		cout << res[i];
	}
	cout << endl;
}

int main() {
	while(true) {
		int n;
		cin >> n;
		factorial(n);
	}
}