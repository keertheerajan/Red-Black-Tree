/*******************************************************************************************************************************************************************
*Title			: Deletion
*Description		: This function performs deleting of the given data from the given Red Black tree.
*Prototype		: int delete(tree_t **root, data_t item); 
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – Data to be deleted from the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

tree_t *delete(tree_t *root, data_t data)
{
    tree_t *temp;//=NULL;

    if(root == NULL)
    {
	puts("list_empty");
	return root;
    }

    if(data < root->data)
    {
	root->left = delete(root->left,data);
    }
    else if(data > root->data)
    {
	root->right = delete(root->right,data);
    }
    else
    {
	if(root->left==NULL && root->right==NULL)
	{
	    temp = NULL;
	    free(root);
	    return temp;
	}

	if(root->left==NULL && root->right!=NULL)
	{
	    temp = root->right;
	    free(root);
	    return temp;
	}
	else if(root->right==NULL && root->left!=NULL)
	{
	    temp = root->left;
	    free(root);
	    return temp;
	}
	else
	{
	    int min;
	    min = find_minimum(&root->right);
	    //printf("min : %d\n",min);
	    root->data = min;
	    root->right = delete(root->right,min);
	}
    }
    return root;
}
