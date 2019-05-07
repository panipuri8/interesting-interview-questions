struct trie{
    trie* children[27];
    bool win;
    bool canLose;
};

trie* getNode() {
    trie* newNode = new trie;
    for(int i=0;i<27;i++) newNode->children[i] = NULL;
    newNode->win = false;   
    newNode->canLose = false;
    return newNode;
}

trie* root;

void insert(string s) {
    trie* temp = root;
    for(int i=0;i<s.length();i++) {
        if(temp->children[s[i] - 'a'] == NULL) {
            temp->children[s[i] - 'a'] = getNode();
        }
        temp = temp->children[s[i] - 'a'];
    }
}

bool search(string s) {
    trie* temp = root;
    for(int i=0;i<s.length();i++) {
        if(temp->children[s[i] - 'a'] == NULL) {
            return false;
        }
        temp = temp->children[s[i] - 'a'];
    }
    return true;
}

int main() {
    root = getNode();
}