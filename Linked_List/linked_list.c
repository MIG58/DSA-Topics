#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *link;
} node;

node *create(node *);
void insertafter(node *);
node *insertbefore(node *);
node *delete (node *);
void disp(node *);

int main(int argc, char const *argv[])
{
    int ch;
    node *head = NULL;
    while (1)
    {
        printf("\nMenu:\nPress <1> to insert node:\nPress <2> to insert new node after another node:\nPress <3> to insert new node before another node:\nPress <4> to delete a node:\nPress <5> to display the linked list:\nPress <0> to\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            head = create(head);
            break;
        case 2:
            insertafter(head);
            break;
        case 3:
            head = insertbefore(head);
            break;
        case 4:
            head = delete (head);
            break;
        case 5:
            disp(head);
            break;
        default:
            printf("\nInvalid Input!");
            break;
        }
    }
    return 0;
}

node *create(node *head)
{
    node *temp, *pre;
    temp = (node *)malloc(sizeof(node));

    printf("\nEnter the value: ");
    scanf("%d", &(temp->data));

    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    pre = head;

    while (pre->link != NULL)
    {
        pre = pre->link;
    }

    pre->link = temp;

    return head;
}

void insertafter(node *head)
{
    int n;
    node *temp, *pre;
    printf("\nEnter the number after which you want to insert the new node: ");
    scanf("%d", &n);
    pre = head;
    while (pre != NULL && pre->data != n)
    {
        pre = pre->link;
    }
    if (pre == NULL)
    {
        printf("\nThe number %d is not present in the linked list!", n);
        return;
    }
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter the value: ");
    scanf("%d", &(temp->data));
    temp->link = pre->link;
    pre->link = temp;
}

node *insertbefore(node *head)
{
    int n;
    node *temp, *pre, *ptr;
    printf("\nEnter the number before which you want to insert the new node: ");
    scanf("%d", &n);
    if (head->data == n)
    {
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter the value: ");
        scanf("%d", &(temp->data));
        temp->link = head;
        head = temp;
        return head;
    }
    ptr = head;
    while (ptr != NULL && ptr->data != n)
    {
        pre = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("\nThe number %d is not present in the linked list!", n);
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter the value: ");
        scanf("%d", &(temp->data));
        temp->link = NULL;
        pre->link = temp;
        temp->link = ptr;
        return head;
    }
}

node *delete (node *head)
{
    int n;
    node *pre, *ptr;
    printf("\nEnter the value you want to delete from the linked list: ");
    scanf("%d", &n);
    ptr = head;
    if (head->data == n)
    {
        head = ptr->link;
        free(ptr);
        return head;
    }
    while (ptr != NULL && ptr->data != n)
    {
        pre = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("\nThe number %d is not present in the linked list!", n);
    }
    else
    {
        pre->link = ptr->link;
        free(ptr);
        return head;
    }
}

void disp(node *head)
{
    node *temp;
    if (head == NULL)
    {
        printf("\nLinked List is empty!");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}