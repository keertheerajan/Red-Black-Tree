/*******************************************************************************************************************************************************************
*Title			: Insertion
*Description		: This function performs inserting the new data into the given Red Black tree.
*Prototype		: int insert(tree_t **root, data_t item);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – New data to be inserted into the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int insert(tree_t **root, data_t item)
{
    tree_t *new = malloc(sizeof(tree_t));//creating new link and updating data
    if(new == NULL)
    {
	perror("new_malloc : ");
	return FAILURE;
    }
    new->data = item;
    new->left = new->right = NULL;
    new->color = RED;//creating child with red colour

    if(*root == NULL)//if tree is empty inserting and comming out
    {
	*root = new;
	new->color = BLACK;//as it is root changing it black
	return SUCCESS;
    }
    tree_t *temp = *root,*parent=NULL,*p_parent;//inserting new link and balancing tree is procedded
    while(temp)
    {
	p_parent = parent;
	parent = temp;
	if(new->data < temp->data)
	    temp = temp->left;
	else if(new->data > temp->data)
	    temp = temp->right;
	else
	{
	    puts("number are equal::duplicate is present");
	    return FAILURE;
	}
	//p_parent = parent;
    }
    if(new->data < parent->data)
	parent->left = new;
    else
	parent->right = new;

    print_tree(*root);
    puts("");
    /*balancing part*/
    if(parent->color == BLACK)
	;
    else
    {
	if((p_parent->right == NULL||p_parent->right->color == BLACK) || (p_parent->left == NULL||p_parent->left->color == BLACK))//siblind absent or black
	{
	    printf("rotating\n");
	    if(p_parent->right == NULL || p_parent->right->color == BLACK)//l*-side
	    {
		if(p_parent->left->right == NULL || p_parent->left->right->color == BLACK)//ll
		    left_left(&p_parent);
		else//lr
		    left_right(&p_parent);
	    }
	    else//r* - side
	    {
		if(p_parent->right->left == NULL || p_parent->right->left->color == BLACK)
		    right_right(&p_parent);
		else
		    right_left(&p_parent);
	    }
	}
	else//for siblings red
	{
	    puts("recoloring");
	    if(p_parent== (*root))
	    {
		p_parent->right->color = p_parent->left->color = BLACK;
	    }
	    else
	    {
		p_parent->right->color = p_parent->left->color = BLACK;
	    }
	}

    }
    print_tree(*root);
    puts("");
}

