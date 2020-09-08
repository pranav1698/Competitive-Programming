#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  bool isWord;
  string text;
  unordered_map<char, TrieNode*> children;
};

struct TrieNode* newNode() {
  struct TrieNode* temp = new TrieNode;
  temp->text = "";
  temp->isWord = false;
  for(char i='a'; i<='z'; i++){
    temp->children[i] = NULL;
  }
  return temp;
}

void printStrings(struct TrieNode* pCrawl) {
  if(pCrawl == NULL) return;
  if(pCrawl->isWord) cout << pCrawl->text << endl;

  struct TrieNode* aCrawl = pCrawl;
  for(int i='a'; i<='z'; i++) {
    if(aCrawl->children[i] != NULL) printStrings(aCrawl->children[i]);
  }
}

bool autoComplete(struct TrieNode* root, string key) {
  struct TrieNode* pCrawl = root;

  for(int i=0; i<key.length(); i++) {
    char curr = key[i];
    if(pCrawl->children[curr] == NULL) false;

    pCrawl = pCrawl->children[curr];
  }

  printStrings(pCrawl);
  return true;
}

bool search(struct TrieNode* root, string key) {
  struct TrieNode* pCrawl = root;

  for(int i=0; i<key.length(); i++) {
    char curr = key[i];
    if(pCrawl->children[curr] == NULL) return false;

    pCrawl = pCrawl->children[curr];
  }

  return (pCrawl!=NULL and pCrawl->isWord);
}

void insertWord(struct TrieNode* root, string word) {
  struct TrieNode* pCrawl = root;
  string w="";
  for(int i=0; i<word.length(); i++) {
    char curr = word[i];
    w += curr;
    if(pCrawl->children[curr] == NULL) {
      pCrawl->children[curr] = newNode();
      pCrawl->children[curr]->text = w;
    }

    pCrawl = pCrawl->children[curr];
  }

  pCrawl->isWord=true;
}

int main() {
  vector<string> words;
  words = {"eat", "ear", "east", "ate", "a", "at"};

  struct TrieNode* root = newNode();
  for(int i=0; i<words.size(); i++) insertWord(root, words[i]);

  cout << search(root, "easter") << endl;

  autoComplete(root, "ea");
}
