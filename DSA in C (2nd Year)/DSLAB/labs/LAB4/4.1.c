// Write a program to create a single linked list of n nodes and perform the following menu
// based operations on it using function:
// i. Insert a node at specific position
// ii. Deletion of an element from specific position
// iii. Count nodes
// iv. Traverse the linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a new node with the given data
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position in the list
struct node *insertAtPosition(struct node *head, int data, int pos)
{
    if (pos <= 1)
    {
        struct node *newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    struct node *newNode = createNode(data);
    struct node *current = head;
    struct node *previous = NULL;
    int currentPosition = 1;

    while (current != NULL && currentPosition < pos)
    {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < pos)
    {
        fprintf(stderr, "Position out of bounds.\n");
        free(newNode);
        return head;
    }

    previous->next = newNode;
    newNode->next = current;
    return head;
}

// Function to delete a node at a specific position in the list
struct node *deleteAtPosition(struct node *head, int pos)
{
    if (head == NULL)
    {
        fprintf(stderr, "Empty list.\n");
        return head;
    }

    if (pos <= 1)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *current = head;
    struct node *previous = NULL;
    int currentPosition = 1;

    while (current != NULL && currentPosition < pos)
    {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || currentPosition < pos)
    {
        printf("Position out of bounds.\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

// Function to count the number of nodes in the linked list
int CountNodes(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Function to traverse and print the linked lis
void printList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current == head)
            printf("%d", current->data);
        else
            printf("->%d", current->data);
        current = current->next;
    }
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
        printf("\n\nMenu:\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element at specific position\n");
        printf("3. Count the number of nodes\n");
        printf("4. Traverse the linked list\n");
        printf("5. Quit\n");
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
            printf("Count: %d", CountNodes(head));
            break;

        case 4:
            printList(head);
            break;

        case 5:
            freeList(head);
            exit(EXIT_SUCCESS);

        default:
            printf("Invalid case!\n");
        }
    }

    return 0;
}
