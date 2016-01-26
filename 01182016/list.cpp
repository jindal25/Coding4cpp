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
    void removeDup(node *n);
    void deleteNode(node *n);
};

void list::deleteNode(node *n) {
    node *tmp = head;
    if(tmp == n) {
        tmp = tmp->next;
        head = tmp;
        return;
    }
    while(tmp->next != NULL){
        if(tmp->next == n){
            if(tmp->next->next != NULL){
                tmp->next = tmp->next->next;
                return;
            }
            else{
                tmp->next = NULL;
                return;
            }
        }
        tmp = tmp->next;
    }
    return;
}

void list::removeDup(node *n) {
    node *current = n;
    node *runner ;
    if (n == NULL) return;
    while(current != NULL)
    {
        runner = current->next;
        while (runner != NULL){
            if(runner->next == current->next)
                runner->next = runner->next->next;
            else
             runner = runner->next;
        }
        current = current->next;
    }
      
}

void list::partition(node *n, int x)
{
    node * runner = n;
    node *current = n;
    node *tmp = current;
    while( current !=NULL)
    {
        if(current->val <= x){
            swap(runner,current);
            runner = runner->next;
            current = current->next;
        }
        else
            current = current ->next;
    }
    while{tmp != NULL){
        if(tmp->val == x)
            break;
        tmp = tmp->next;
    }

    swap(runner->next,tmp);
}
/*
void list::removeDup_myversion(node *n) {
    node *current = n;
    node *rotate = n->next;
    while(current != NULL)
    {
        if (current->val == rotate->val) {
            deleteNode(rotate);
            if(current->next != NULL){
                rotate = current->next;
            }
            else
                return;
        }
        else{
            if(rotate->next == NULL){
                if( current->next != NULL){
                    current = current->next; // go to the next node as this node is not dupicate
                    rotate = current->next; // start from next node
                }else
                    return ;//we have reached to the end of te list
            }
            else
                rotate = rotate->next;
        }
    }
}
*/
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