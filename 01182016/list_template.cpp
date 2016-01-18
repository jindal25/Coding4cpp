

#include<iostream>
using namespace std;
template<typename T>
struct Node{
    T data;
    Node* next;
    Node(T d, Node* n=NULL): data(d), next(n){}
};


template<typename T>
class myqueue{
    private:
        Node<T> * first;
        Node<T> * last;
    public:
        myqueue(): first(NULL), last(NULL){}
        void push(T da){
            if(first==NULL) {
                first=new Node<T>(da);
                last=first;
            }
            else {

                last->next=new Node<T>(da);
                last=last->next;

                }
        }   
        void pop(){
          if(last!=NULL){
            Node<T> * temp=first;
            first=first->next;
            delete temp;
          }
        }
        void front(){
           if(first!=NULL) cout<< first->data;
        }
        bool isempty(){
            return last==NULL;
        }
};

int main(){
    myqueue<int> q;
    q.push(1);
    q.push(2);
    q.front();
    /*
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front();
    */

}