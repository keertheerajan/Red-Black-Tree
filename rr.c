#include "apc.h"

int right_right(tree_t **p_parent)
{
    tree_t *new = malloc(sizeof(tree_t));
    if(new == NULL)
	perror("rr_malloc :");
    new->data = (*p_parent)->data;
    new->color = RED;
    (*p_parent)->left = new;
    (*p_parent)->data = (*p_parent)->right->data;
    (*p_parent)->right->data = (*p_parent)->right->right->data;
    free((*p_parent)->right->right);
    (*p_parent)->right->right = NULL; 
    return SUCCESS;
}
