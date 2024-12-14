// Write a program to create a circular linked list and display the elements of the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void PrintNodes(struct node *head)
{
    if (!head)
    {
        printf("Empty list\n");
        return;
    }

    struct node *ptr = head;
    printf("Clinkedlist: %d", ptr->data);
    ptr = ptr->next;

    while (ptr != head)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int i = 1;
    printf("Enter info of node%d: ", i);
    scanf("%d", &(p->data));
    p->next = NULL;

    i++;
    while (i <= n)
    {
        struct node *q = (struct node *)malloc(sizeof(struct node));
        printf("Enter info of node%d: ", i);
        scanf("%d", &(q->data));
        q->next = NULL;
        p->next = q;
        p = p->next;
        i++;
    }
    p->next = head;

    PrintNodes(head);

    return 0;
}