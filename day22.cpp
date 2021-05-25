// Problem Link: https://www.geeksforgeeks.org/word-break-problem-dp-32/

#include<iostream>
#include<vector>
using namespace std;
#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *child[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;

    for(int i=0;i<ALPHABET_SIZE;i++){
        node->child[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, string str) {
    int s = str.size();
    for(int i=0;i<s;i++) {
        int index = str[i] - 'a';
        if(!root->child[index]){
            root->child[index] = getNode();
        }

        root = root->child[index];
    }
    root->isEndOfWord = true;
}

bool search(TrieNode *root, string key, vector<string> &v) {
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();i++) {
        int index = key[i] - 'a';
        if(!pCrawl->child[index]) {
            return false;
        }

        pCrawl = pCrawl->child[index];
    }

    if(pCrawl != NULL && pCrawl->isEndOfWord){
        v.push_back(key);
        return true;
    }else {
        return false;
    }
}


bool wordBreakUtil(string str, TrieNode *root, vector<string> &v) {
    int size = str.size();

    if(size==0) return true;

    for(int i=1;i<=size;i++) {
        if(search(root, str.substr(0, i), v) && wordBreakUtil(str.substr(i, size-i), root, v)){
            return true;
        }
    }

    return false;
}
void wordBreak(string arr[], int n, string s) {
    TrieNode *root = getNode();
    for(int i=0;i<n;i++) {
        insert(root, arr[i]);
    }

    vector<string> v;

    bool isExist = wordBreakUtil(s, root, v);

    if(isExist) {
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }else {
        cout<<"Doesn't Exist."<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string str[n];
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }

    wordBreak(str, n, s);

    return 0;
}