// Write a program to represent the given sparse matrix using header single linked list and
// display it.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row, col, value;
    struct Node *next;
};

struct SparseMatrix
{
    int rows, cols, nonZeroes;
    struct Node *head;
};

void insertElement(struct SparseMatrix *matrix, int row, int col, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    if (matrix->head == NULL)
    {
        matrix->head = newNode;
    }
    else
    {
        struct Node *current = matrix->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displaySparseMatrix(struct SparseMatrix *matrix)
{
    printf("Sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", matrix->rows, matrix->cols, matrix->nonZeroes);

    struct Node *current = matrix->head;
    while (current != NULL)
    {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main()
{
    struct SparseMatrix *matrix = malloc(sizeof(struct SparseMatrix *));
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);

    matrix->head = NULL;

    int notZeroes = 0;

    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < matrix->rows; ++i)
    {
        for (int j = 0; j < matrix->cols; ++j)
        {
            int value;
            scanf("%d", &value);
            if (value != 0)
            {
                notZeroes++;
                insertElement(matrix, i, j, value);
            }
        }
    }
    matrix->nonZeroes = notZeroes;

    displaySparseMatrix(matrix);

    return 0;
}
