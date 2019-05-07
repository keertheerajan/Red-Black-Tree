#include "apc.h"

int left_right(tree_t **p_parent)
{
    tree_t *new = malloc(sizeof(tree_t));
    if(new == NULL)
	perror("lr_p_left : ");
    new->data = (*p_parent)->left->data;
    new->color = RED;
    (*p_parent)->left->left = new;
    (*p_parent)->left->data = (*p_parent)->left->right->data;
    free((*p_parent)->left->right);
    (*p_parent)->left->right = NULL;

    puts("left_rotate_parent");
    tree_t *new_2 = malloc(sizeof(tree_t));
    if(new_2 == NULL)
	perror("lr_pp_right :");
    new_2->data = (*p_parent)->data;
    new_2->color = RED;
    (*p_parent)->right = new_2;
    (*p_parent)->data = (*p_parent)->left->data;
    (*p_parent)->left->data =(*p_parent)->left->left->data;
    free((*p_parent)->left->left);
    (*p_parent)->left->left = NULL;
}
