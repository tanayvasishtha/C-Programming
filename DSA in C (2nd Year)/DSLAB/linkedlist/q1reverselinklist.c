// reverse the linkedlist and print after the reversal
#include <stdio.h>
#include <stdlib.h>

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
    p->next = NULL;
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
    struct node *next;
    struct node *current;
    struct node *prev;
    prev = NULL;
    next = NULL;
    current = head;
    while (current != NULL)
   {
    
   }
    while (prev != NULL)
    {
        printf("the given link list is %d\n", prev->data);
        prev = prev->next;
    }
    return 0;
}
