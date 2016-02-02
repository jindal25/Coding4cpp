#include <iostream>
#include <stdbool.h>

using namespace std;

class node {
public:
	int val;
	node * left;
	node * right;

	node():val(0){
	   left = NULL;
	   right = NULL;
	}
	node(int va) : val(va){
	   left = NULL;
	   right = NULL;
	}
};

class btree {
	public:
		void insert (node *root, int value);
		bool deleteNode (node *root, int value);
		bool isBalanced (node *root, int heig);
		bool isBST (node *root, int val);
		int findHeight (node *root, int *height);
		node * rt ;
	private:
		
		int height;
};

void btree::insert(node *root, int value) 
{
	cout << " inside Insert";
	if(root == NULL){
	   cout << " root si NULL" << root;
	   root = new node(value);
	   cout << " root is not NULL" << root;
	   return;
	   }

	 if(root->val < value) {
	 	if(root->right != NULL)
	 	   insert(root->right,value);
	 	 else
	 	    root->right = new node(value);
	 } else if (root->left != NULL) 
	    	  insert(root->left, value );
	    	else 
	    	  root->left = new node(value);


}

bool btree::deleteNode(node * root, int value){
	cout << " inside delete";
}

bool btree::isBalanced( node *root, int value) {}

bool btree::isBST(node *root, int val) {}

int btree::findHeight(node *root, int *height) {

    int hl=0, hr=0;

    if( root == NULL)
       return 0;

    findHeight(root->left, &hl);
    findHeight(root->right, &hr);

    *height = (hl > hr ? hl : hr) + 1;

	
}

int main()
{
    int n,ht;
    btree *bt = new btree;
    cout << " Enter the number of nodes in the tree";
    cin >> n;

    cout << " root si NULL" << bt->rt;

    for (int i =0 ;i<n; i++) {
    bt->insert(bt->rt,rand()%100);
    }

    cout << " root si NULL" << bt->rt;

    //bt->findHeight( bt->rt,&ht);



	return 0;
}
