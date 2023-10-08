/*
    @author sadman_sakib
    date : 09 - 10- 2023
    
    Linked List -> Create, Insert Begin, Insert End, Insert Middle;
                -> Delete Begin, Delete End, Delete Middle, Search val, Update;

    Sobgula function implement kora ache, just proyojon bujhe use korte hbe
*/


#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
} *head;


void create(int n) {
    head = new node;

    int x; cin >> x;
    struct node* newNode = new node;
    newNode->data = x;
    newNode->next = nullptr;

    head = newNode;

    struct node* temp  = head;

    for(int i = 0; i < n - 1; i++) {
        cin >> x;
        struct node* newNode2 = new node;
        newNode2->data = x;
        newNode2->next = nullptr;

        temp->next = newNode2;
        temp = temp->next;
    }
}

void insertBegen(int val) {
    struct node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    struct node* local = head;
    newNode->next = head;
    head = newNode;
}

void insertAt(int pos, int val) {
    struct node* temp = new node;
    temp = head;

    struct node* addnode = new node;
    addnode->data = val;
    addnode->next = nullptr;

    for(int i = 0; i < pos - 1; i++) {  temp = temp -> next; }

    addnode->next = temp -> next;
    temp->next = addnode;
}

void insertEnd(int val) {
    struct node* temp = new node;
    temp = head;

    while(temp -> next != nullptr) {    temp = temp -> next;    }

    struct node* addnode = new node;
    addnode->data = val;
    addnode->next = nullptr;

    temp->next = addnode;

    
}

void deleteBeg() {
    struct node* cur = new node;
    cur = head->next;
    free(head);
    head = cur;
}

void deleteAt(int pos) {

    struct node* temp = head;
    struct node* prev = head;

    for(int i = 0; i < pos - 1; i++) {
        prev = temp;
        temp = temp->next;
    }

    struct node* save = temp -> next;

    free(prev->next);

    prev->next = save;
}


void deleteEnd() {
    struct node* temp = new node;
    struct node* prv = new node;
    temp = head;

    while(temp -> next != nullptr) {
        prv = temp;    
        temp = temp -> next;    
    }

    free(prv->next);
    prv->next = nullptr;
}

void searchList(int val) {
    struct node* temp = head;
    int idx = -1, cnt = 1;
    while(temp != nullptr) {
        if(temp->data == val) {
            idx = cnt; break;
        }
        temp = temp->next;
        cnt++;
    }
    if(idx == -1) cout << val << " not found" << endl;
    else cout << val << " found at " << idx << endl;
}

void update(int pos, int val) {
    struct node* temp = head;
    for(int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    temp->data = val;
}

void printList(struct node* temp) {
     while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    int n; cin >> n;

    create(n);

    update(3, 111111);

    searchList(323);

    printList(head);

    return 0;
}
