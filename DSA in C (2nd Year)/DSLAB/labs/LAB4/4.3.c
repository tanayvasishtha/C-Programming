#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createPoly()
{

    int pow;
    printf("Enter the Maximum power of x:");
    scanf("%d", &pow);

    if (pow < 0)
    {
        return NULL;
    }

    struct node *Poly = malloc(sizeof(struct node *));
    printf("Enter the coefficient of degree %d:", pow--);
    scanf("%d", &Poly->data);
    Poly->next = NULL;

    struct node *curr = Poly->next;
    struct node *prev = Poly;

    for (int i = pow; i >= 0; i--)
    {
        curr = malloc(sizeof(struct node));
        printf("Enter the coefficient of degree %d:", i);
        scanf("%d", &curr->data);
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
        curr = curr->next;
    }

    return Poly;
}

int getLength(struct node *poly)
{
    int count = 0;
    while (poly)
    {
        count++;
        poly = poly->next;
    }
    return count;
}

void sumPoly(struct node *poly1, struct node *poly2)
{
    int offset = 0;

    int Length1 = getLength(poly1);
    int Length2 = getLength(poly2);
    int flag1 = 1;

    if (Length1 > Length2)
    {
        offset = Length1 - Length2;
    }
    else if (Length2 > Length1)
    {
        offset = Length2 - Length1;
        flag1 = 0;
    }

    int firstTerm = 1; // To track the first term

    while (offset)
    {
        if (flag1)
        {
            if (!firstTerm)
            {
                printf(" + ");
            }
            printf("%dx^%d", poly1->data, Length1 - 1);
            poly1 = poly1->next;
            --Length1;
        }
        else
        {
            if (!firstTerm)
            {
                printf(" + ");
            }
            printf("%dx^%d", poly2->data, Length2 - 1);
            poly2 = poly2->next;
            --Length2;
        }
        --offset;
        firstTerm = 0; // Not the first term anymore
    }

    while (poly1 && poly2)
    {
        if (!firstTerm)
        {
            printf(" + ");
        }
        printf("%dx^%d", poly1->data + poly2->data, Length1 - 1);
        poly1 = poly1->next;
        poly2 = poly2->next;
        --Length1;
        firstTerm = 0;
    }

    printf("\n");
}

// Function to print the linked list
void printPoly(struct node *head)
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

int main()
{
    printf("Polynomial-1:\n");
    struct node *Poly1 = createPoly();
    printf("Polynomial-2:\n");
    struct node *Poly2 = createPoly();
    printPoly(Poly1);
    printPoly(Poly2);
    // printList(Poly1);
    sumPoly(Poly1, Poly2);
    return 0;
}
