/*       SET-1
    QUESTION1- FIND THE SECOND LARGEST IN THE SINGLY LINKEDLIST

*/

//Linkedlist is already created
#include <stdio.h>
#include <stdlib.h>
// structure creation
struct node
{
    int data;
    struct node *next;
};
//function declaration
//function definition
void findseclargest(int n,struct node* head){
 struct node*head;
 int max;
 int secmax;
 while(head->next!=NULL){
    if(head->data<head->next->data){
        max=head->next->data;
        secmax=head->data;
    }
    else if(head->data>head->next->data){
        max=head->data;
        secmax=head->next->data;
    }
    else{
        return;
    
    }
 }//loop ends

 printf("The second largest number in the linkedlist is %d",secmax);
}
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

    void findseclargest(data,head );
    return 0;
}

