/*
 *	Thomas Nguyen
 *	Wednesday 2:15 - 3:00
 *	
 *	Tree.c is an abstract file that contains code that takes standard
 *	input to create a binary tree. It is implemented using a structure
 *	that has a pointer to the left child, right child, and parent.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

/*
 *	A structure that has a pointer to the left child, right child
 *	and parent. It also contains the data of the number inputted.
*/
struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};

/*
 *	A helper function that figures out whether the child is 
 *	on the left or the right then sets it to NULL.
 *	
 *	Run Time: O(1)
*/
static void detach (struct tree *child)
{
	struct tree *tp;
	tp = child -> parent;
	if (tp != NULL)
	{
		if (tp -> right == child)
			tp -> right = NULL;
		else
			tp -> left = NULL;
	}
}

/*
 *	A function that initializes a tree when passed an integer, a
 *	pointer to the left child, and a pointer to the right child.
 *	It uses some of the helper functions that are created in this
 *	code.
 *
 *	Run Time: O(1)
*/
struct tree *createTree (int data, struct tree *left, struct tree *right)
{
	struct tree *root;
	root = malloc(sizeof(struct tree));
	assert (root != NULL);
	detach (root);
	root -> data = data;
	if (root -> left != NULL)
	{
		detach (root -> left);
	}
	setLeft (root, left);
	if (root -> right != NULL)
	{
		detach (root -> right);
	}
	setRight (root, right);
	return (root);
}

/*
 *	A function that recursively calls itself to traverse through
 *	tree and frees the nodes.
 *
 *	Run Time: O(h)
*/
void destroyTree (struct tree *root)
{
	if (root == NULL)
		return;
	destroyTree (root -> left);
	destroyTree (root -> right);
	free (root);
}

/*
 *	Function for the client to retrieve data from the node
 *
 *	Run Time: O(1)
*/
int getData (struct tree *root)
{
	assert (root != NULL);
	return(root -> data); 
}

/*
 *	Function for the client to retrieve the left child pointer
 *
 *	Run Time: O(1)
*/
struct tree *getLeft (struct tree *root)
{
	assert (root != NULL);
	return (root -> left);
}

/*
 *	Function for the client to retrieve the right child pointer
 *
 *	Run Time: O(1)
*/
struct tree *getRight (struct tree *root)
{
	assert (root != NULL);
	return (root -> right);
}

/*
 *	Function for the client to retrieve the parent pointer
 *
 *	Run Time: O(1)
*/
struct tree *getParent (struct tree *root)
{
	assert (root != NULL);
	return (root -> parent);
}

/*
 *	This function updates the left subtree by first clearing
 *	any connecting pointers to the left node and then
 *	connecting the left node with the root
 *
 *	Run Time: O(1)
*/
void setLeft (struct tree *root, struct tree *left)
{
	if (left == NULL)
	{
		root -> left = NULL;
		return;
	}
	if (left -> parent != NULL)
	{
		detach (left);
	}
	root -> left = left;
	left -> parent = root;
	return;
}

/*
 *	This function updates the right subtree by first clearing
 *	any connecting pointers to the right node and then 
 *	connecting the right node with the root
 *
 *	Run Time: O(1)
*/
void setRight (struct tree *root, struct tree *right)
{
	if (right == NULL)
	{
		root -> right = NULL;
		return;
	}
	if (right -> parent != NULL)
	{
		detach (right);
	}
	root -> right = right;
	right -> parent = root;
	return;
}
