/***************************************
 Given a singly linked list, swap the list items in pairs (reconnect the pointers, not simply swap the values). For example:
 
 Before: A->B->C->D
 After: B->A->D->C
 ****************************************/

#include <iostream>

using namespace std;

class node {
public:
       int val;
       node * next;
       node() {}
       node(int a) : val(a) ,next(NULL){
       }
};

class list : public node {
public:
    node * head;
    void insert(int v);
    void swap2(node *n);
    void printlist();
};

void list::insert(int v) {
    node *tmp = head;
    
    if (tmp==NULL) {
        tmp = new node(v);
        head = tmp;
        return;
    }
    
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new node(v);
}

void list::swap2(node *n) {
 int temp;
 if(n==NULL || n->next == NULL) {
 return;
 }
 
 temp = n->val;
 n->val=n->next->val;
 n->next->val=temp;
 
 if(n->next->next != NULL && n->next->next->next != NULL)
    swap2(n->next->next);
 }

void list::printlist() {
    node *tmp = head;
    if( tmp == NULL)
        return ;
    
    while(tmp->next != NULL) {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
    cout << tmp->val << endl;
}



int main() {
    
    list *l = new list();
    
    l->insert(1);
    l->insert(2);
    l->insert(3);
    l->insert(4);
     l->insert(5);
     l->insert(6);
     l->insert(7);
     l->insert(8);
    
    l->printlist();
    printf( "*************************");
    l->swap2(l->head);
    
    l->printlist();
    
    
    
    
    
}