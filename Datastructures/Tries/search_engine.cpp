#include <bits/stdc++.h>
using namespace std;
unsigned long long int max_weight=INT_MIN;


struct TrieNode {
    bool isWord;
    string text;
    int weight;
    unordered_map<char, TrieNode*> children;
};

struct TrieNode* newNode() {
    struct TrieNode* temp= new TrieNode;
    temp->isWord=false;
    temp->text="";
    temp->weight=-1;
    for(char i='a'; i<='z'; i++) {
        temp->children[i] = NULL;
    }

    return temp;
}

int getStringPriority(struct TrieNode* root, int priority) {
    if(root == NULL) return priority;
    if(root->isWord) {
      priority = max(priority, root->weight);
    }

    struct TrieNode* aCrawl = root;
    for(char i='a'; i<='z'; i++) {
        if(aCrawl->children[i] != NULL) {
            priority = max(priority, getStringPriority(aCrawl->children[i], priority));
        }
    }

    return priority;
}

int getPriority(struct TrieNode* root, string str) {
    struct TrieNode* pCrawl= root;

    for(int i=0; i<str.length(); i++) {
        char curr = str[i];
        if(pCrawl->children[curr] == NULL) return -1;
        pCrawl = pCrawl->children[curr];
    }

    return getStringPriority(pCrawl, -1);
}



void insertWord(struct TrieNode* root, string s, int W) {
    struct TrieNode* pCrawl = root;

    string w="";
    for(int i=0; i<s.length(); i++) {
        char curr=s[i];
        w+=curr;

        if(pCrawl->children[curr] == NULL) {
        	pCrawl->children[curr]=newNode();
        	pCrawl->children[curr]->text = w;
        }

        pCrawl = pCrawl->children[curr];
    }

    pCrawl->isWord=true;
    pCrawl->weight=W;
}

int main() {
    int n,q;
    cin >> n >> q;
    string s;
    int w;

    struct TrieNode* root = newNode();
    while(n--) {
        cin >> s >> w;
        insertWord(root, s, w);
    }

    string str;
    while(q--) {
        cin >> str;
        cout << getPriority(root, str) << endl;;
    }

}
