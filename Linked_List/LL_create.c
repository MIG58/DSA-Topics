#include <stdio.h> // Program to create Linked List of 3 Nodes and Traverse
#include <stdlib.h>

typedef struct List
{
    int val;
    struct List *next;
} lnk;

void LinkedList_Traversal(lnk *ptr) // Function to traverse the Linked List
{
    while (ptr != NULL)
    {

        printf("[%d|%s]-->", ptr->val, ptr->next);
        ptr = ptr->next;
    }
}
int main()
{
    lnk *head, *middle, *tail;

    head = (lnk *)malloc(sizeof(lnk)); // Dynamically 3 Nodes/Blocks are created
    middle = (lnk *)malloc(sizeof(lnk));
    tail = (lnk *)malloc(sizeof(lnk));

    head->val = 1;       // assigning data to 1st node [1st Node] = 1
    head->next = middle; // Linking the [1st node]--->[2nd node]

    middle->val = 2;     // assigning data to 2nd node [2nd Node] = 2
    middle->next = tail; // Linking the [2nd node]--->[3rd node]

    tail->val = 3;     // assigning data to 3rd node [3rd Node] = 3
    tail->next = NULL; // Linking the [3rd node]--->[NULL]

    LinkedList_Traversal(head);
}