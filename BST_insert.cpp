/*********************************************************************************************************************
     **
     **  Created a Binary Tree using level order and sorted manner
     **  Input in the format of integer array
     **  Display in Inorder, Preorder and Postorder manner
     **  Tree is printed in 2dimensional from top to bottom in left to right way
     
     **  Written By:    Akash Vishwas Londhe
     **
*********************************************************************************************************************/

#include<bits/stdc++.h>
#define count 10

using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE* insertInLevelOrder( int arr[], NODE *root, int i, int n )
{
	
	if(i<n)
	{
		root=(NODE *)malloc(sizeof(NODE));
		
		root->data=arr[i];
		
		root->left=insertInLevelOrder( arr, root->left, 2*i+1,  n);
		
        root->right=insertInLevelOrder( arr, root->left, 2*i+2,  n);
		
	}
	return root;
	
}

void insert(int data, NODE* root)
{
	
	NODE *t=(NODE *)malloc(sizeof(NODE));
	t->data=data;
	
	if(root==NULL)
		root=t;
	else
	{
		NODE *p=root;
		while(root)
		{
			p=root;
			if( t->data < root->data)
				root=root->left;
			else
				root=root->right;
		}
		if(t->data < p->data)
			p->left = t;
		else
			p->right = t ;
	}
	
}

void printTree(NODE *root, int space)
{
	
	if(root==NULL)
		return;
	
	space = space+count;
	
	printTree(root->right, space);
	
	for(int i=count;i<=space;i++)
		printf(" ");
	printf("%d\n\n",root->data);
	
	printTree(root->left, space);
	
}

void inorder(NODE *root)
{
	
	if(root->left)
		inorder(root->left);
		
	printf(" %d ",root->data);
	
	if(root->right)
		inorder(root->right);
	
}

void preorder(NODE *root)
{
	
	printf(" %d ",root->data);
	
	if(root->left)
		preorder(root->left);	
	
	if(root->right)
		preorder(root->right);
		
}

void postorder(NODE *root)
{
	
	if(root->left)
		postorder(root->left);
			
	if(root->right)
		postorder(root->right);
		
	printf(" %d ",root->data);
		
}

int main()
{
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
     // To insert nodes in level order 
	NODE* root=insertInLevelOrder( arr,root,0,n);
	
	//inorder display
	printf("Inorder : ");
	inorder(root);
	
	//preorder display
	printf("\nPreorder : ");
	preorder(root);
	
	//postorder display
	printf("\nPostorder : ");
	postorder(root);
	
	//print tree in 2dimensional
	printf("\nTree ( Leveled ) :\n ");
	printTree(root,0);
	
	printf("\n\n\n\n\n");
	
	
	// To insert nodes in sorted order
	int arr1[] = { 7, 5, 4, 3, 2, 12, 43, 15, 16, 1 }; 
	n = sizeof(arr1)/sizeof(arr1[0]); 
    
	NODE *sorted_root=(NODE *)malloc(sizeof(NODE));
    sorted_root->data=7; 
	for(int i=1;i<n;i++)
	{   printf("%d",arr1[i]);
	    insert(arr1[i],sorted_root);
	}
		
	//inorder display
	printf("Inorder : ");
	inorder(sorted_root);
	
	//preorder display
	printf("\nPreorder : ");
	preorder(sorted_root);
	
	//postorder display
	printf("\nPostorder : ");
	postorder(sorted_root);
	 
	//print tree in 2dimensional
	printf("\nTree ( sorted ) :\n ");
	printTree(sorted_root,0);
	
	getchar();
	return 0;
	
}
