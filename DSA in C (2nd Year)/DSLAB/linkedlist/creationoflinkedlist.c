// Procedure of creation of linked list
#include <stdio.h>
#include <stdlib.h>
// structure creation
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    printf("Enter data");
    scanf("%d", &p->data);
    p-> next = NULL;
    int n = 1;
    while (n < 10)
    {
        struct node *q = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p = p->next;
        n++;
    }
    struct node *j = head;
    while (j != NULL)
    {-
        printf("the given link list is %d\n", j->data);
        j = j->next;
    }
    return 0;
}