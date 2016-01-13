#include <iostream>

using namespace std;

class node{
      public:
      int val;
      node * next;
      node():next(NULL){}
      node(int a):val(a),next(NULL){}
};

class stack {
      node * head;
      public:
      stack(){
      head = NULL;
      }
      void push(int a);
      int pop();

};

void stack::push(int a)
{
  node * tmp;
  if(head==NULL) {
     head=new node(a);
     return;
   } else {
     tmp = new node(a);
     tmp->next = head;
     head = tmp;
   }
}

int stack::pop()
{
  int temp;
  if(head == NULL)
    return -1;
  else{
    temp = head->val;
    head = head->next;
    return temp;
  }
}

int main()
{

stack s1;

s1.push(3);
s1.push(4);
s1.push(5);
s1.push(6);
s1.push(7);

cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;
cout << s1.pop()<< endl;

}




