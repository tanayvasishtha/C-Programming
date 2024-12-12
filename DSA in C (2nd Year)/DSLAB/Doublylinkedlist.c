#include <stdio.h>
#include <stdlib.h>
//structure 
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
//declaration of function
void PrintNode(struct node *head)
{
    struct node *ptr = head;
    while (ptr)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    int n;
    printf("Enter total number of elements: ");
    scanf("%d", &n);

    printf("Enter element: ");
    scanf("%d", &p->data);
    p->next = NULL;
    p->prev = NULL;

    for (int i = 1; i < n; i++)
    {
        struct node *q = (struct node *)malloc(sizeof(struct node));
        printf("Enter element: ");
        scanf("%d", &q->data);
        q->next = NULL;
        q->prev = p;

        p->next = q;
        p = p->next;
    }

    PrintNode(head);  //calling a function

    return 0;
}