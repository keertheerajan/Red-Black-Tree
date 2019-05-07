/*******************************************************************************************************************************************************************
*Title			: Find Minimum
*Description		: This function finds the minimum data from the given Red Black tree.
*Prototype		: int find_minimum(tree_t **root, data_t *min);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: min – Minimum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int find_minimum(tree_t **root)
{
    if(*root == NULL)
    {
	printf("tree is empty\n");
	return;
    }
    tree_t *temp = *root;
    while(temp->left != NULL)
    {
	temp = temp->left;
    }
    return temp->data;
//    return SUCCESS;
}
