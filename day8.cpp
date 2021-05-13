// Problem Link : https://www.geeksforgeeks.org/find-count-of-singly-subtrees/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void inorder(Node *root) {
    if(!root) return;

    inorder(root->left);
    cout<<(root->data)<<" ";
    inorder(root->right);
}


bool countUnival(Node *root, int &count) {
    if(!root) return true;

    bool left = countUnival(root->left, count);
    bool right = countUnival(root->right, count);

    if(!left || !right) return false;

    if(root->left && root->data != root->left->data) {
        return false;
    }
    if(root->right && root->data != root->right->data) {
        return false;
    }
    count++;
    return true;
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    // root->right->left->left = new Node(1);
    // root->right->left->right = new Node(1);

    // inorder(root);

    int count = 0;

    inorder(root);
    cout<<endl;
    countUnival(root, count);

    cout<<count<<endl;   

    return 0;

}