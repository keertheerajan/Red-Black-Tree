/***************************************************************************************************************************************************************
*Title		: This the header file for the Red Black Tree
****************************************************************************************************************************************************************/
#ifndef RBT_H
#define RBT_H
#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 0
#define FAILURE -1
#define RED 1
#define BLACK 0

typedef int data_t;

typedef struct node
{
	struct node *left;
	data_t data;
	struct node *right;
	int color;
}tree_t;
int insert(tree_t **root, data_t item);
int left_left(tree_t **p_parent);
int right_right(tree_t **p_parent);
int left_right(tree_t **p_parent);
int right_left(tree_t **p_parent);
void print_tree(tree_t *);
//int find_minimum(tree_t **root, data_t *min);
int find_maximum(tree_t **root, data_t *max);
int search(tree_t *root,data_t data);
tree_t *delete(tree_t *root, data_t data);
/* keep all the prototypes of the functions here */

#endif
