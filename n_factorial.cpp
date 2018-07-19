#include<bits/stdc++.h>
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
 
// #define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define enddl '\n'
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define full(a) a.begin(),a.end()
#define mem(a,x) memset(a,x,sizeof(a))
#define PI 3.14159265

const int MAXN = 1e5+5;

const int MOD = 1e9+7;

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