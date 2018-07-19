#include<bits/stdc++.h>

using namespace std;

bool allNines(string s) {
	for(int i=0;i<s.length();i++) {
		if(s[i] != '9') {
			return false;
		}
	}
	return true;
}

string nextPalindrome(string s) {
	int l = s.length();
	if(allNines(s)) {
		return "1" + string(l-1 , '0') + "1";
	}
	int left = -1, right = -1;
	if(l%2) {
		left = l/2 - 1;
		right = l/2 + 1;
	}
	else {
		left = l/2 - 1;
		right = l/2;
	}
	while(left >= 0 && right < l) {
		if(s[left] == s[right]) {
			left--;
			right++;
		}
		else if(s[left] > s[right]) {
			s[right] = s[left];
			for(int j=right+1;j<l;j++) {
				s[j] = s[--left];
			}
			return s;
		}
		else {
			break;
		}
	}
	if(l%2) {
		left = l/2 - 1;
		right = l/2 + 1;
	}
	else {
		left = l/2 - 1;
		right = l/2;
	}
	int tempLeft = left;
	if(l%2) left++;
	int value = (s[left] - '0' + 1);
	int x = value%10;
	int carry = value / 10;
	s[left] = x + '0';
	left--;
	while(left >= 0 && carry) {
		int value = (s[left] - '0' + carry) ;
		s[left] = value%10 + '0';
		carry = value/10;
		left--;
	}
	left = tempLeft;
	while(right < l) {
		s[right] = s[left];
		left--;
		right++;
	}
	return s;

}

int main() {	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << nextPalindrome(s) << endl;
	}

}