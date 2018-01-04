#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

node *makenode(int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->key=num;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node* insert(struct node *ref, int data)
{
	if (ref==NULL)
		return makenode(data);

	if (data<ref->key)
		ref->left=insert(ref->left,data);
	else if (data>ref->key)
		ref->right=insert(ref->right,data);
}

void inorder(struct node *ref)
{
	if (ref!=NULL)
	{
		inorder(ref->left);
        printf("%d \n", ref->key);
        inorder(ref->right);
	}
}

void preorder(struct node *ref)
{
	if (ref==NULL)
		return;
    printf("%d \n", ref->key);
	preorder(ref->left);
    preorder(ref->right);
}

void postorder(struct node *ref)
{
	if (ref==NULL)
		return;
	postorder(ref->left);
    postorder(ref->right);
    printf("%d \n", ref->key);
}

node* search(struct node *ref, int data)
{
	if (ref!=NULL)
	{
		if (data<ref->key)
			search(ref->left,data);
		else if (data>ref->key)
			search(ref->right,data);
		else if (data==ref->key)
			printf("found the node with entry %d\n",ref->key );

	}
}


int main()
{
	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	 node *root=NULL;
	// struct node *searched=NULL;
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    // search(root,60);
    cout<<endl;
    // cout<<root->left->left->key;
    preorder(root);

    cout<<endl;
    cout<<endl;

	postorder(root);
	return 0;
}