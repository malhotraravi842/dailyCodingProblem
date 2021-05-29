#include<iostream>
using namespace std;

struct LinkedList {
    int data;
    LinkedList *next;
    LinkedList(int data) {
        this->data = data;
        next = NULL;
    }
};

void insert(LinkedList *root, int data) {
    if(!root){
        root = new LinkedList(data);
    }

    while(root->next) {
        root = root->next;
    }

    root->next = new LinkedList(data);
}

int findKthNode(LinkedList *root, int k) {
    LinkedList *temp = root;
    while(k) {
        temp = temp->next;
        k--;
    }

    while(temp != NULL) {
        temp = temp->next;
        root = root->next;
    }

    return root->data;
}

int main() {
    LinkedList *root = new LinkedList(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 9);

    cout<<findKthNode(root, 8);

    return 0;
}