// Complete Linked List Coded in Lab 25/8/2022

#include <stdio.h>
#include <stdlib.h>

typedef struct LinearLinkedList
{
    int val;
    struct LinearLinkedList *next;
} lnk;

lnk *create(lnk *, int); // Function Declaration
lnk *Insertbegin(lnk *, int);

lnk *Insertbefore(lnk *, int, int);
void Insertafter(lnk *, int, int);

void display(lnk *);
lnk *del(lnk *, int);
// ----------------------------------------------------------------

lnk *Insertbefore(lnk *h, int n, int ab)
{
    lnk *temp, *ptr, *pre;
    pre = ptr = h;

    if (h->val == ab)
    {
        h = Insertbegin(h, n);
    }
    else
    {
        temp = (lnk *)malloc(sizeof(lnk)); // creating Node

        temp->val = n;
        temp->next = NULL;
        while (ptr->val != ab && ptr != NULL)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        temp->next = pre->next;
        pre->next = temp;
    }
    return h;
}
void Insertafter(lnk *h, int n, int ab)
{
    lnk *temp, *ptr;
    ptr = h;

    while (ptr->val != ab && ptr != NULL)
    {
        ptr = ptr->next;
    } // Traverse Through

    temp = (lnk *)malloc(sizeof(lnk));

    temp->val = n; // Error: Misplace of n with ab
    temp->next = ptr->next;
    ptr->next = temp;
}

lnk *Insertbegin(lnk *h, int n)
{
    lnk *temp;
    temp = (lnk *)malloc(sizeof(lnk));
    temp->val = n;
    temp->next = h;
    h = temp;

    return h;
}
lnk *create(lnk *h, int n) // 1. To create a Node
{
    lnk *ptr, *temp;

    temp = (lnk *)malloc(sizeof(lnk));

    temp->val = n;
    temp->next = NULL; // Default Initalization

    if (h == NULL)
    {
        h = temp;
    }
    else
    {
        ptr = h;
        while (ptr->next != NULL) // Traverse through
        {
            ptr = ptr->next;
        }
        ptr->next = temp; // insert node at last
    }
    return h;
}
void display(lnk *h) // 6. To Display the Linked List
{
    lnk *ptr;

    ptr = h;
    printf("\nValues are: ");
    if (h != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\nNothing To Display..!!");
    }
    printf("\n");
}
lnk *del(lnk *h, int v)
{
    lnk *pre, *ptr;
    ptr = h;
    if (h->val != v)
    {
        while (ptr->val != v && ptr != NULL)
        {
            pre = ptr;       // pre = n
            ptr = ptr->next; // ptr = n+1
        }                    // Traverse

        if (ptr != NULL)
        {
            pre->next = ptr->next;
        }
        else
        {
            printf("\nvalue not found");
        }
    }
    else
    {
        h = h->next;
    }
    free(ptr);
    return h;
}
int main()
{
    lnk *head = NULL;
    int sw, n1, ab;

    while (1)
    {

        printf("\n1. To Create a node\n");      // Done
        printf("2. To Insert at begining\n");   // Done
        printf("3. To Insert before a node\n"); // Done
        printf("4. To Insert after a node\n");  // Done
        printf("5. To delete a node\n");        // Done (Dry Run Left)
        printf("6. To Display\n");              // Done
        printf("7. To Exit\n");                 // Done
        printf("Enter ur choice: ");
        scanf("%d", &sw);

        switch (sw)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n1);
            head = create(head, n1);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &n1);
            head = Insertbegin(head, n1);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n1);
            printf("Enter value before: ");
            scanf("%d", &ab);
            head = Insertbefore(head, n1, ab); // Function Call missing
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%d", &n1);
            printf("Enter value after: ");
            scanf("%d", &ab);
            Insertafter(head, n1, ab);
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%d", &n1);
            head = del(head, n1);
            break;
        case 6:
            display(head);
            break;
        case 7:
            printf("\nProgram Terminated\n");
            exit(0);
        default:
            printf("\nInvalid Choice..!!");
        }
    }
    return 0;
}
