// Problem Link: https://iq.opengenus.org/xor-linked-list/
// Problem Link: https://www.techiedelight.com/xor-linked-list-overview-implementation-c-cpp/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *both;
};

struct Node* XOR(struct Node *x, struct Node* y) {
    return (struct Node*)((uintptr_t)(x)^(uintptr_t)(y));
}

void push(Node **root, int data) {
    struct Node *newNode = new Node();
    newNode->data = data;

    newNode->both = XOR(*root, NULL); 
    if(*root) {
        (*root)->both = XOR(newNode, XOR((*root)->both, NULL));
    }

    *root = newNode;
}

void append(Node **root, int data) {
    Node *new_node = new Node();
    new_node->data = data;

    if(!*root) {
        new_node->both = XOR(NULL, NULL);
        *root = new_node;
        return;
    }

    Node *curr = *root;
    Node *prev = NULL;
    Node *next;

    while(curr) {
        next = XOR(prev, curr->both);
        prev = curr;
        curr = next;
    }

    new_node->both = XOR(prev, NULL);
    prev->both = XOR(new_node, XOR(prev->both, NULL));
}

void del(Node *root, int key) {
    struct Node* prev = NULL;
    struct Node* next;
    while(root->data != key) {
        next = XOR(prev, root->both);
        prev = root;
        root = next;
    }
    next = XOR(root->both, prev);
    prev->both = XOR(XOR(prev->both, root), next);
    next->both = XOR(XOR(next->both, root), prev);
}

void traverse(struct Node *root) {
    struct Node* curr = root;
    struct Node* prev = NULL;
    struct Node* next;

    while(curr) {
        cout<<(curr->data)<<"->";
        next = XOR(prev, curr->both);
        prev = curr;
        curr = next;
    }

    cout<<"NULL"<<endl;
}

int main() {

    struct Node *root = NULL;
    append(&root, 1);
    append(&root, 2);
    append(&root, 3);
    del(root, 2);
    append(&root, 4);
    append(&root, 5);

    traverse(root);

    return 0;
}