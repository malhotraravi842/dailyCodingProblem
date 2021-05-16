// Problem Link: https://www.geeksforgeeks.org/auto-complete-feature-using-trie/

#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNode(void) {
    TrieNode *node = new TrieNode;
    node->isEndOfWord = false;

    for(int i=0;i<ALPHABET_SIZE;i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, string key) {
    TrieNode *pCrawl = root;
    for(int i=0;i<key.size();i++) {
        int index = key[i] - 'a';
        if(!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool isLastNode(struct TrieNode* root) { 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return 0; 
    return 1; 
}

void findPatternUtil(TrieNode *root, string str) {
    if(root->isEndOfWord) {
        cout<<str<<" ";
    }

    if(isLastNode(root)) {
        return;
    }

    for(int i=0;i<ALPHABET_SIZE;i++) {
        if(root->children[i]) {
            findPatternUtil(root->children[i], str + (char)(97+i));
        }
    }
}

void findPattern(TrieNode *root, const string query) {
    TrieNode *pCrawl = root;

    for(int i=0;i<query.length();i++) {
        int index = query[i] - 'a';
        if(!pCrawl->children[index]) {
            return;
        }

        pCrawl = pCrawl->children[index];
    }

    bool isWord = (pCrawl->isEndOfWord == true); 

    bool isLast = isLastNode(pCrawl); 
 
    if (isWord && isLast) 
    { 
        cout<<query<<" "; 
        return; 
    }

    if (!isLast) { 
        string prefix = query; 
        findPatternUtil(pCrawl, prefix);
    }
}

int main() {
    string query;
    cin>>query;
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    TrieNode *root = getNode();

    for(int i=0;i<n;i++) {
        insert(root, arr[i]);
    }

    findPattern(root, query);

    return 0;
}