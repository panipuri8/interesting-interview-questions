#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	static const int MAX_CHILDREN = 26;
	Node* children[MAX_CHILDREN];
	int children_count[MAX_CHILDREN];
	bool endOfWord;

	Node() {
		for(int i=0;i<MAX_CHILDREN;i++) children[i] = NULL, children_count[i] = 0;
		endOfWord = false;
	}
};

class Trie{
private:
	Node* root;
public:

	Trie() {
		root = new Node;
	}

	void insert(string s) {
		Node* temp = root;
		for(int i=0;i<s.length();i++) {
			if(temp->children[s[i] - 'a'] == NULL) {
				temp->children[s[i] - 'a'] = new Node();
			}
			temp->children_count[s[i] - 'a']++;
			temp = temp->children[s[i] - 'a'];
		}
		temp->endOfWord = true;
	}

	bool search(string s) {
		Node* temp = root;
		for(int i=0;i<s.length();i++) {
			if(temp->children_count[s[i] - 'a'] == 0) {
				return false;
			}
			temp = temp->children[s[i] - 'a'];
		}
		return (temp->endOfWord == true);
	}

	void remove(string s){
		Node* temp = root;
		for(int i=0;i<s.length();i++) {
			temp->children_count[s[i] - 'a']--;
			if(temp->children_count[s[i] - 'a'] == 0) {
				delete temp->children[s[i] - 'a'];
				return;
			}
			temp = temp->children[s[i] - 'a'];
		}
		if(temp && temp->endOfWord) {
			temp->endOfWord = false;
		}
	}
};

int main() {
	Trie trie;
	trie.insert("akshay");
	trie.insert("aks");
	trie.insert("a");
	cout << trie.search("aks") << endl;
	cout << trie.search("akshay") << endl;
	trie.remove("aks");
	cout << trie.search("aks") << endl;
	cout << trie.search("akshay") << endl;
	trie.remove("akshay");
	cout << trie.search("a") << endl;
	cout << trie.search("akshay") << endl;
	trie.insert("akshay");
	cout << trie.search("aks") << endl;
	cout << trie.search("akshay") << endl;
	trie.insert("hello");
	cout << trie.search("hello") << endl;
}