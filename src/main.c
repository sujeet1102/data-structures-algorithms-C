#include "main.h"

int main(void)
{
	//Create functions and structures for each of the tasks 
	//in respective header files and call them here
    // struct Node *head = (struct Node*)malloc(sizeof(struct Node)*(4));
    int arr[5] = {3,5,6,9,10};
    // Node *first = NULL;
    // create_LL_array(arr, 5, &first);
    // display_LL(first);
    // printf("\n");
    // display_LL_recursive(first);
    // printf("\n");
    // printf("%d", count_LL(first));
    // printf("\n");
    // printf("%d", sum_elements_LL(first));
    // printf("\n");
    // printf("%d", max_element_LL(first));
    // printf("\n");
    // printf("%d", min_element_LL(first));
    // printf("\n");
    // printf("%d", get_LL(first, linear_search_LL(first, 9)));
    // printf("\n");
    Node *head = NULL;
    
    // insert_LL(&head, 0, 1);
    // insert_LL(&head, 1, 1);
    // insert_LL(&head, 2, 2);
    // insert_LL(&head, 3, 3);
    // insert_LL(&head, 4, 3);
    // insert_LL(&head, 5, 7);
    // insert_LL(&head, 6, 8);
    // insert_LL(&head, 7, 8);
    
    // display_LL(head);
    // printf("\n");
    // insert_sorted_LL(&head, 5);
    // insert_sorted_LL(&head, -1);
    // insert_sorted_LL(&head, 4);
    // printf("Deleted element: %d", delete_LL(&head, 3));
    // printf("%d", check_sorted_LL(head));
    // delete_duplicate_LL(&head);
    // reverse_LL(&head);
    // display_LL(head);
    // printf("- Reversed links\n");
    // reverse_recusrion_LL(&head, NULL, head);
    // display_LL(head);
    // printf("- Reversed links via recursion\n");
    // reverse_elements_LL(head);
    // display_LL(head);
    // printf("- Displaying reverse\n");
    
    // int arr1[5] = {3,5,6,9,10};
    // int arr2[5] = {1,2,4,7,9};
    // Node *first = NULL;
    // Node *second = NULL;
    // create_LL_array(arr1, 5, &first);
    // create_LL_array(arr2, 5, &second);
    // printf("First: ");
    // display_LL(first);
    // printf("\n");
    // printf("Second: ");
    // display_LL(second);
    // printf("\n");
    // printf("Merged List: ");
    // Node *third = NULL;
    // merge_sorted_LL(&first, &second, &third);
    // display_LL(third);
    
    // create_circular_LL_array(arr, 5, &head);
    // display_circular_LL(head);
    insert_circular_LL(&head, 0, -666);
    insert_circular_LL(&head, 1, 12);
    insert_circular_LL(&head, 2, 133);
    // insert_circular_LL(&head, -2, 0);
    // printf("\n");
    // display_circular_LL(head);

	printf("\n\n");
	return 0;
}