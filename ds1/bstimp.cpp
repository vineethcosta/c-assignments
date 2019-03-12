// bstimp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node {
	node* left, *right;
	int data;
};
node *found=NULL;
node *maxn = NULL;
node *parentf = NULL;
int isl = 0;
int max = 0;
 void findinorder(node* root,int x,int isleft,node* parent)
{
	if (root == NULL)
		return;
	findinorder(root->left,x,1,root);
	if (root->data == x)
	{
		found = root;
		parentf = parent;
		if (isleft)
			isl = 1;
		else
			isl = 0;
	}

	findinorder(root->right,x,0,root);
}
 int findmax(node* root)
 {
	 if (root == NULL)
		 return;
	 findmax(root->left);
	 if (max < root->data)
	 {
		 maxn = root;
		 max = root->data;
	 }
	 findmax(root->right);
}
void inorder(node *root)
{
	if (root == NULL)
		return; 
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node* insert(node* root, int x) 
{
	node *temp;
	temp = new node();
	if (root == NULL)
	{
		
		temp->data = x;
		temp->left = temp->right = NULL;
		root = temp;
	}
	else
	{
		if (root->data > x)
		{
			root->left = insert(root->left, x);

		}
		else
		{
			root->right = insert(root->right, x);
		}
	}
	return root;
}
void deletenode(int data , node* root )
{
	node *temp = NULL;
	findinorder(root,data,0,NULL);
	if (found == NULL)
		cout << "Not found";
	else
	{
		if (isl == 1)
			parentf->left = findmax(found);
		delete(found);
		found = NULL;
	}
	return;

}
int main()
{
	node *root;
	root = NULL;
	int x,n;
	cout << "Enter no of elements to insert";
	cin >> n;
	cin >> x;
	root = insert(root, x);
	for (int i = 0; i < n-1; i++)
	{
		cin >> x;
		insert(root, x);
	}
	inorder(root);
	deletenode(2,root);
	deletenode(5,root);
	inorder(root);
	system("pause");
    return 0;
}

