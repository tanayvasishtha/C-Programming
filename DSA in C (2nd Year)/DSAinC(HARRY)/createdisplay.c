 #include<stdio.h>
#include<stdlib.h>
//CREATION AND TRAVERSAL OF LINKEDLIST BY HARRY


struct node{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr){
    while(ptr!=0){
    printf("Element is %d\n",ptr->data);
    ptr=ptr->next;
    }
}


int main(){
    struct node * head;
    struct node* second;
    struct node* third;
    //Allocate memory for nodes in linked list
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    
    //link first and second nodes
    head->data=7;
    head->next=second;
    
    //link second and third nodes
    second->data=11;
    second->next=third;

    //Terminate the list at third node
    third->data=66;
    third->next=NULL;

    linkedlistTraversal(head);
    return 0;

}