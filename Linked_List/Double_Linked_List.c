#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkedList
{
    struct DoubleLinkedList *prev;
    int val;
    struct DoubleLinkedList *next;
} dl;

dl *head, *tail;

void create(int n)
{
    dl *temp, *ptr;

    temp = (dl *)malloc(sizeof(dl));

    temp->val = n;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp; // Both head and tail will point to newNode
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        (ptr->next)->prev = ptr;
        ptr = ptr->next; //
        tail = ptr;
    }

    // return head;
}
void display() // Display Normal  OK
{
    dl *ptr;

    ptr = head;
    printf("\nValues are: ");
    if (head != NULL)
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

void displayR() // Display Reverse
{
    dl *ptr;

    // printf("Tail: %d",tail->val);
    ptr = tail;
    printf("\nReverse values are: ");
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->prev;
        }
    }
    else
    {
        printf("\nNothing To Display..!!");
    }
    printf("\n");
}
void main()
{
    dl *head = NULL, *tail = NULL;

    int sw, n1, ab;

    while (1)
    {

        printf("\n1. To Create a node\n"); // Done
        printf("2. To Display Normal\n");  // Done
        printf("3. To Display Reverse\n"); // Done
        printf("4. To Exit\n");            // Done
        printf("Enter ur choice: ");
        scanf("%d", &sw);

        switch (sw)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n1);
            create(n1);
            break;

        case 2:
            display(); // OK
            break;
        case 3:
            displayR();
            break;
        case 4:
            printf("\nProgram Terminated\n");
            exit(0);
        default:
            printf("\nInvalid Choice..!!");
        }
    }
}
