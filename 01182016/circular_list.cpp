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
    void printlist();
    findCircularNode(node *n);
};

list::makeCircular(int a){
    node * tmp=head;
    node * tail; 

    if(tmp == NULL)
        return;

    while(tmp->next!=NULL)
        tmp= tmp->next;

    tail = tmp;

    tmp = head;

    while(tmp!=NULL){
        if(tmp->val == a)
            tail->next = tmp;
        tmp=tmp->next;
    }
}


}


node * list::findCircularNode(){
    node * slow = head;
    node * fast = head;

    while ( fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if( slow == fast)
            break;
    }

    if (fast == NULL || fast->next->next == NULL)
        return;

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;

}

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
    l->insert(8);
    l->insert(7);
    
    l->deleteNode(l->head);
    
    l->deleteNode(l->head->next);
    
    l->printlist();
    printf( "*************************");
    l->removeDup(l->head);
    l->printlist();
    l->swap2(l->head);
   
   
    l->printlist();
    
    
    
    
    
}