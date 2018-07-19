#include<bits/stdc++.h>

using namespace std;

string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if(a.length() < b.length()) swap(a,b);
	int carry = 0;
	int i = 0;
	for(i=0;i<b.length();i++) {
		int val = a[i] - '0' + b[i] - '0' + carry;
		a[i] = val%10 + '0';
		carry = val/10;
	}
	while(carry) {
		if(i < a.length()) {
			int val = a[i] - '0' + carry;
			a[i] = val%10 + '0';
			carry = val/10;
			i++;
		}
		else {
			a+=(carry + '0');
			carry = 0;
		}
	} 
	reverse(a.begin(), a.end());
	return a;
}

string multiply(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if(a.length() < b.length()) swap(a,b);
	string ans = "0";
	for(int i=0;i<b.length();i++) {
		int digit = b[i] - '0';
		int carry = 0;
		string temp = "";
		for(int j=0;j<a.length();j++) {
			int val = (a[j] - '0') * digit + carry;
			temp+=(val%10 + '0');
			carry=val/10;
		}
		while(carry) {
			temp+=((carry%10) + '0');
			carry/=10;
		}
		reverse(temp.begin(),temp.end());
		temp+=string(i,'0');
		ans = add(ans, temp);
	}
	return ans;
}

int main() {	
	for(int i=1;i<=1e3;i++) {
		for(int j=1;j<=1e3;j++) {
			int x = i*j;
			if(to_string(x) != multiply(to_string(i), to_string(j))) {
				cout << "ERROR" << endl;
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "ALL GOOD!" << endl;

}