/* 1.3 Write a program to create a structure to store the information of n number of Employees.
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary,
hra%, da%. Display the information of employees with gross salary. Use array of structure.*/
#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[100];
    char designation[100];
    double basic_salary;
    double hra_percentage;
    double da_percentage;
};

int main()
{
    int n;

    printf("Enter no. of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; ++i)
    {
        printf("Enter employee %d information:\n", i + 1);

        // Clear the newline character from the previous input
        while (getchar() != '\n')
            ;

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strlen(employees[i].name) - 1] = '\0'; // Remove newline

        printf("Designation: ");
        fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
        employees[i].designation[strlen(employees[i].designation) - 1] = '\0'; // Remove newline

        printf("Basic Salary: ");
        scanf("%lf", &employees[i].basic_salary);

        printf("HRA %%: ");
        scanf("%lf", &employees[i].hra_percentage);

        printf("DA %%: ");
        scanf("%lf", &employees[i].da_percentage);

        printf("\n");
    }

    printf("Employee Information:\n");

    for (int i = 0; i < n; ++i)
    {
        double hra = employees[i].basic_salary * (employees[i].hra_percentage / 100);
        double da = employees[i].basic_salary * (employees[i].da_percentage / 100);
        double gross_salary = employees[i].basic_salary + hra + da;

        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2lf\n", employees[i].basic_salary);
        printf("HRA %%: %.2lf%%\n", employees[i].hra_percentage);
        printf("DA %%: %.2lf%%\n", employees[i].da_percentage);
        printf("Gross Salary: %.2lf\n", gross_salary);

        printf("\n");
    }

    return 0;
}
