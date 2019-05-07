#include "apc.h"

int left_left(tree_t **p_parent)
{
    tree_t *new = malloc(sizeof(tree_t));
    if(new == NULL)
	perror("ll_malloc :");
    new->data = (*p_parent)->data;
    new->color = RED;
    (*p_parent)->right = new;
    (*p_parent)->data = (*p_parent)->left->data;
    (*p_parent)->left->data = (*p_parent)->left->left->data;
    free((*p_parent)->left->left);
    (*p_parent)->left->left = NULL;
    return SUCCESS;
}
