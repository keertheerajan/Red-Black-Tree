#include"apc.h"
void print_tree(tree_t *node)
{
    if (node)
    {
	print_tree(node->left);

	/* START BOLD */
	printf("\033[1m");
	(node->color == RED) ?printf("%s%d  ","\x1B[31m", node->data) : printf("%s%d  ","\x1B[0m", node->data);

	/* Recursive function call */
	print_tree(node->right);
    }
    printf("%s", "\x1B[0m");
    /* END BOLD */
    printf("\033[22m");
    return;
}

