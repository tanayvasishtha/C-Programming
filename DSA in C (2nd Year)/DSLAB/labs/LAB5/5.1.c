// Write a program to create a double linked list and perform the following menu based
// operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position
// iii. Traverse the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *insertAtPosition(struct node *head, int val, int pos)
{
    struct node *pre;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int k = 1;
    temp->prev = NULL;
    temp->data = val;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head;
        if (head != NULL)
        {
            head->prev = temp;
        }
        head = temp;
        return head;
    }
    pre = head;
    while (k <= pos - 2 && pre->next != NULL)
    {
        pre = pre->next;
        k++;
    }
    if (k < pos - 1)
    {
        printf("Out of bounds! ");
        return head;
    }
    temp->prev = pre;
    temp->next = pre->next;

    if (pre->next != NULL)
    {
        pre->next->prev = temp;
    }
    pre->next = temp;

    return head;
}

struct node *deleteAtPosition(struct node *head, int pos)
{
    struct node *cur;
    int k = 1;
    if (pos == 1)
    {
        if (head == NULL)
        {
            printf("Empty list\n");
            return head;
        }

        struct node *p = head;
        if (p->next)
        {
            p->next->prev = NULL;
        }
        head = p->next;

        return head;
    }
    cur = head;
    while (k <= pos - 1 && cur->next != NULL)
    {
        cur = cur->next;
        k++;
    }
    if (k < pos)
    {
        printf("Out of bounds! ");
        return head;
    }
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;

    return head;
}

// Function to print the linked list
void printList(struct node *head)
{
    struct node *current = head;
    int isFirst = 1;

    while (current != NULL)
    {
        if (isFirst)
        {
            printf("%d", current->data);
            isFirst = 0; // Set isFirst to false after printing the first element
        }
        else
        {
            printf("->%d", current->data);
        }
        current = current->next;
    }

    printf("\n");
}

// Function to free memory and delete the entire linked list
void freeList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element at specific position\n");
        printf("3. Traverse the linked list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter integer: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insertAtPosition(head, data, pos);
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deleteAtPosition(head, pos);
            break;

        case 3:
            printList(head);
            break;

        case 4:
            freeList(head);
            exit(EXIT_SUCCESS);

        default:
            printf("Invalid case!\n");
        }
    }

    return 0;
}