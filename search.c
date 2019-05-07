#include "apc.h"

int search(tree_t *root,data_t data)
{
    if(root == NULL)
    {
	printf("list empty\n");
	return FAILURE;
    }

    tree_t *temp = root;
    while(temp)
    {
	if(data < temp->data)
	    temp = temp->left;
	else if(data > temp->data)
	    temp = temp->right;
	else
	    return SUCCESS;
    }
    return FAILURE;
}

