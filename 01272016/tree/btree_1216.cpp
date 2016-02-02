#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class node {
 
 public:
  int val;
  node * left;
  node * right;
  node(int a): val(a),left(NULL), right(NULL){}
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
  node * btree::minNode(node *n);
};

node * btree::minNode(node *n)
{
  while (n->left != NULL)
      n = n->left;
  return n
}

/*int btree::isBalanced(node *n) {
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
 

}*/

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
   
    if( n->val > a )
      if(n->left != NULL)
        insertNode(n->left,a);
      else
        n->left = new node(a);
    else if(n->val < a)
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

void btree::printLevelreversed(int level, node *n) {
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

node commonParent( node * n1, node *n2){

 node *tn1, *tn2;
 int count1=0,count2=0;

 tn1=n1;
 tn2=n2;

  if( n1 == n2)
    return n1->parent;

  while(n1->parent != NULL)
  {
    n1=n1->parent;
    count1++;
  }

  while(n2->parent != NULL)
  {
    n2=n2->parent;
    count2++;
  }

  if (count1 == count2){
    /* the nodes are on the same level*/
    n1=tn1;
    n2=tn2;
    while(n1->parent != NULL || n2->parent != NULL) {
      if (n1->parent == n2->parent)
        return n1->parent;
     else {
        n1=n1->parent;
        n2=n2->parent;
      }
     }
  } 
   else if( count1 > count2) {
    diff = count1 - count2;
    while(diff) {
      n1=n1->parent;
      diff--;
    }
    while(n1->parent != NULL || n2->parent != NULL) {
      if (n1->parent == n2->parent)
        return n1->parent;
     else {
        n1=n1->parent;
        n2=n2->parent;
      }
    }
      else if ( count2 > count21) {
        diff = count2 - count1;
    while(diff) {
      n2=n2->parent;
      diff--;
    }
    while(n1->parent != NULL || n2->parent != NULL) {
      if (n1->parent == n2->parent)
        return n1->parent;
     else {
        n1=n1->parent;
        n2=n2->parent;
      }
    }

      }


  }
}
/* Returns true if binary tree with root as root is height-balanced */
int btree::isBalanced(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   findHeight(root->left,&lh);
   findHeight(root->right,&rh);
 
   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
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
