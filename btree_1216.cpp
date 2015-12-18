#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class node {
 
 public:
  int val;
  node * left;
  node * right;
  node(int a): val(a){}
  node(){}
};

class btree {
 public:
  node * root;
  void insertNode( node * n , int a);
  void deleteNode(int a);
  bool isBalanced ();
  void findHeight(node *n, int* height) ;
  void printLevel(int level, node *n);
  int isBalanced(node *n);
};

int btree::isBalanced(node *n) {
  if( n == NULL)
     return 0;
  int lh=0, rh=0;
  
  if(n->left != NULL) {
    lh=isBalanced(n->left);
    if( lh == -1) return -1;
  }
  
  if(n->right != NULL){
    rh=isBalanced(n->right);
    if(rh==-1) return -1;
  }

  if(abs(lh-rh) >1)
     return -1;
  
  return (max(lh,rh) + 1);
 

}

void btree::findHeight(node *n, int* height) {
   if(n==NULL)
      return;

  int lh=0, lr=0;     

   if(n->left != NULL)
     findHeight(n->left,&lh);
   if(n->right !=NULL)
     findHeight(n->right,&lr);

   *height = (lr>lh? lr:lh) + 1;
}


void btree::insertNode( node *n, int a) {

   cout << " inserting " << a << endl; 
    if(n == NULL) {
      n = new node(a);
      root = n;
      return;
   }
   
    if( n->val < a )
      if(n->left != NULL)
        insertNode(n->left,a);
      else
        n->left = new node(a);
    else if(n->val > a)
      if(n->right != NULL)
        insertNode(n->right,a);
      else
        n->right = new node(a);
}

void btree::printLevel(int level, node *n) {
    if( n==NULL)
      return;

    if(level == 0)
      cout << n->val << ",";
    else {
      level--;
      if(n->left!=NULL)
        printLevel(level,n->left);
      if(n->right!=NULL)
        printLevel(level,n->right);
    }
       
}

int main() {

   btree *bt = new btree;
   int ht=0; 
 
   //for (int j =0;j<30;j++)
     //bt->insertNode(bt->root,rand()%100);

   bt->insertNode(bt->root,5);
   bt->insertNode(bt->root,6);
   bt->insertNode(bt->root,4);
   
   bt->findHeight(bt->root,&ht);

   cout<< "height is " << ht <<endl;
  
   for( int i= (ht-1);i>=0;i--) {
      bt->printLevel(i, bt->root);
      cout << endl;
  }
   
  cout << " Balanced Btree "<< bt->isBalanced(bt->root) << endl;
}       
