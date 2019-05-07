#include "apc.h"

int right_left(tree_t **p_parent)
{
    tree_t *new = malloc(sizeof(tree_t));
    if(new == NULL)
	perror("lr_p_left : ");
    new->data = (*p_parent)->right->data;
    new->color = RED;
    (*p_parent)->right->right = new;
    (*p_parent)->right->data = (*p_parent)->right->left->data;
    free((*p_parent)->right->left);
    (*p_parent)->right->left = NULL;

    tree_t *new_2 = malloc(sizeof(tree_t));
    if(new_2 == NULL)
	perror("lr_pp_right :");
    new_2->data = (*p_parent)->data;
    new_2->color = RED;
    (*p_parent)->left = new_2;
    (*p_parent)->data = (*p_parent)->right->data;
    (*p_parent)->right->data =(*p_parent)->right->right->data;
    free((*p_parent)->right->right);
    (*p_parent)->right->right = NULL;
}
