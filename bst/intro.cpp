#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node *makenode(int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->key=num;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* insert(struct node *ref, int data)
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

struct node* search(struct node *ref, int data)
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
	struct node *root=NULL;
	struct node *searched=NULL;
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    search(root,60);
	return 0;
}