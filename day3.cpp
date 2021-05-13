// Problem Link:  https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void serialize(Node *root, FILE *fp) {
    if(!root) {
        fprintf(fp, "%d", -1);
        return;
    }

    fprintf(fp, "%d", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deserialize(Node *root, FILE *fp) {
    int val;

    if(!fscanf(fp, "%d", &val) || val ==-1) return;

    root = new Node(val);
    deserialize(root->left, fp);
    deserialize(root->right, fp);
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}


int main() {
    struct Node *root        = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);


    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);
 
    // Let us deserialize the storeed tree into root1
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deserialize(root1, fp);
 
    printf("Inorder Traversal of the tree constructed from file:\n");
    inorder(root1);

    
    return 0;
}
