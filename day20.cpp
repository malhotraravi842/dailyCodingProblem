// Problem Link: https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

#include<iostream>
using namespace std;

struct LinkedList {
    int data;
    struct LinkedList *next;

    LinkedList(int data) {
        this->data = data;
        next = NULL;
    }
};

void printLinkedList(LinkedList *root) {
    while(root) {
        cout<<(root->data)<<" ";
        root = root->next;
    }
    cout<<endl;
}

LinkedList* intersection(LinkedList *root1, LinkedList *root2) {
    int size1 = 0, size2 = 0;
    LinkedList* curr1 = root1;
    LinkedList* curr2 = root2;
    while(curr1) {
        size1++;
        curr1 = curr1->next;
    }
    while(curr2) {
        size2++;
        curr2 = curr2->next;
    }

    int k = abs(size1 - size2);

    if(size1 >= size2) {
        curr1 = root1;
        curr2 = root2;
    }else{
        curr1 = root2;
        curr2 = root1;
    }

    while(k){
        curr1 = curr1->next;
        k--;
    }

    while(curr1->data != curr2->data){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1;
}

int main () {
     LinkedList* newNode;
    LinkedList* head1 = new LinkedList(10);
    LinkedList* head2 = new LinkedList(3);
    newNode = new LinkedList(6);
    head2->next = newNode;
    newNode = new LinkedList(9);
    head2->next->next = newNode;
    newNode = new LinkedList(15);
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new LinkedList(30);
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    LinkedList* node = intersection(head1, head2);


    printLinkedList(node);

    return 0;
}