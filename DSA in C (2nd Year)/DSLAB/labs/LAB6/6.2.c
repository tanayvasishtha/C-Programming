#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (!p)
    {
        printf("MEMORY ALLOCATION FAILED!\n");
        return;
    }
    p->data = val;
    p->next = head;
    head = p;
}

void pop()
{
    if (!head)
    {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *rem = head;
    printf("Popped value: %d\n", head->data);
    head = head->next;
    free(rem);
}

int isEmpty()
{
    return head == NULL;
}

void print()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = head;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\nMain Menu \n1. Push\n2. Pop\n3. IsEmpty\n4. Traverse\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

        case 4:
            print();
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
