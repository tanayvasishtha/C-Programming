// In addition to 4.1, perform following operations using function on the single linked list:
// i. search an element in the list
// ii. sort the list in ascending order
// iii. reverse the list

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
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "Position out of bounds.\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

void CountNodes(struct node *head)
{
    int count = 0;
    struct node *p = head;
    while (p)
    {
        count++;
        p = p->next;
    }
    printf("Number of nodes: %d", count);
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

int searchElement(struct node *head, int key)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
            return 1; // Element found
        current = current->next;
    }
    return 0; // Element not found
}

// Function to sort the list in ascending order
struct node *sortList(struct node *head)
{
    struct node *current = head, *index = NULL;
    int temp;

    while (current != NULL)
    {
        index = current->next;

        while (index != NULL)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    return head;
}

// Function to reverse the list
struct node *reverseList(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; // Update the head to the new beginning of the list
    return head;
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
    int choice, data, pos, key;
    printf("\nMenu:\n");
    printf("1. Insert element at specific position\n");
    printf("2. Delete element at specific position\n");
    printf("3. Count the number of nodes\n");
    printf("4. Traverse the linked list\n");
    printf("5. Search an element in the list\n");
    printf("6. Sort the list in ascending order\n");
    printf("7. Reverse the list\n");
    printf("8. Quit\n");
    while (1)
    {

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
            CountNodes(head);
            break;

        case 4:
            printList(head);
            break;

        case 5:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            if (searchElement(head, key))
                printf("Element %d found in the linked list.\n", key);
            else
                printf("Element %d not found in the linked list.\n", key);
            break;

        case 6:
            head = sortList(head);
            printf("List sorted in ascending order.\n");
            break;

        case 7:
            head = reverseList(head);
            printf("Reverse list: ");
            printList(head);
            // printf("List reversed.\n");
            break;

        case 8:
            freeList(head);
            exit(EXIT_SUCCESS);

        default:
            printf("Invalid case!\n");
        }
    }

    return 0;
}
