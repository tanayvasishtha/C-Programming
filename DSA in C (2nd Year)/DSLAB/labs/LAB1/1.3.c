#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

typedef struct
{
    int Empid[MAX];
    char Name[MAX];
    char Desig[MAX];
    int basic_salary;
    int hra;
    int da;
} EmpInfo;

int main()
{
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);

    EmpInfo Emp[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter employee %d information: \n", i + 1);
        scanf("%s", Emp[i].Name);
        scanf("%s", Emp[i].Desig);
        scanf("%d", &Emp[i].basic_salary);
        scanf("%d%%", &Emp[i].hra);
        scanf("%d%%", &Emp[i].da);
    }
    printf("Employee Information: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", Emp[i].Name);
        printf("Designation: %s\n", Emp[i].Desig);
        printf("Basic Salary: %d\n", Emp[i].basic_salary);
        printf("HRA %%:  %d%%\n", Emp[i].hra);
        printf("DA %%: %d%%\n", Emp[i].da);

        int grossSalary = Emp[i].basic_salary + (Emp[i].hra * Emp[i].basic_salary / 100) + (Emp[i].da * Emp[i].basic_salary / 100);
        printf("Gross Salary: %d\n", grossSalary);
        printf("\n");
    }

    return 0;
}