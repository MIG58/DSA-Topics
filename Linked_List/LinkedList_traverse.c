/***/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList_traverse
{
    int val;
    struct LinkedList_traverse *next;
} lnk;

void display(lnk *);

void display(lnk *ptr) // To traverse the Linked List
{
    // printf("ptr Init = %d\n", ptr);
    printf("ptr Init = %d %p\n", ptr->val, ptr->next);
    while (ptr != NULL)
    {

        printf("%d\n", ptr->val);

        printf("ptr Before = %d %p\n", ptr->val, ptr->next);
        // printf("ptr before = %d\n", ptr);
        ptr = ptr->next; // pointing to next node
        printf("ptr after = %d %p\n", ptr->val, ptr->next);
    }
}
int main()
{
    lnk *head = NULL, *ptr, *temp;
    int p;

    while (1)
    {
        printf("Enter a number: \n(-99 to stop)");
        scanf("%d", &p);
        free(temp);

        if (p == (-99))
        {
            break;
        }
        temp = (lnk *)malloc(sizeof(lnk));

        temp->val = p;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            printf("\nHead: %d %p", head->val, head->next);
        }
        else
        {
            ptr->next = temp;
            printf("\n>Head: %d %u\n", head->val, head->next);
            printf("ptr: %d %p\n", ptr->val, ptr->next);
            printf("temp: %d %p\n", temp->val, temp->next);
        }
        ptr = temp;
        printf("\n>Head: %d %u\n", head->val, head->next);
        printf("ptr: %d %p\n", ptr->val, ptr->next);
        printf("temp: %d %p\n", temp->val, temp->next);
    }
    // display(head);

    return 0;
}