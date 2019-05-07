/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

int main()
{
	/* Declare the pointers */
	tree_t *root = NULL;
	data_t data;
	data_t minimum;
	data_t maximum;
	data_t operation;

	system("clear");
	do
	{
		printf("1. Insert\t2. Delete\n3. Search\t4. Print\n5. Find Maximum\t6. Find Minimum\n7. Exit\n");

                scanf("%d",&operation);
		switch (operation)
		{
			case 1:
				printf("Enter the data to be inserted into the RB Tree: ");
				scanf("%d", &data);
				insert(&root, data);
				printf("root : %d\n",root->data);
				break;
			case 2:
				printf("Enter the data to be deleted from the RB Tree: ");
				scanf("%d", &data);
				root = delete(root, data);
				//print_tree(root);
				break;
                        case 3:
				printf("Enter the data to search in the RB Tree: ");
				scanf("%d", &data);
				if(!search(root,data))
				    puts("data_found");
				else
				    puts("data_not_found");
				break;
			case 4:
				if(root==NULL)
				    puts("list_empty");
				else
				{   
    				    printf("root : %d\n",root->data);
    				    print_tree(root);
				}
    				    break;
			case 5:
				find_maximum(&root,&maximum);
				printf("Maximum data: %d\n", maximum);
				print_tree(root);
				puts("");
				break;
                        case 6:
				minimum=find_minimum(&root);
				printf("Minimum data: %d\n", minimum);
				print_tree(root);
				puts("");
				break;			
			case 7:
				exit(0);
		}
	}while (1);

	return 0;
}
