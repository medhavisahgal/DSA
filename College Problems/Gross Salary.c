#include <stdio.h>
struct Employee
{
    int emp_id;
    char name[100];
    char designation[100];
    float basic_salary;
    float hra_percent;
    float da_percent;
};
float calculateGrossSalary(struct Employee emp)
{
    return emp.basic_salary + (emp.basic_salary * emp.hra_percent / 100) + (emp.basic_salary * emp.da_percent / 100);
}
int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of Employee %d:\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA (in percentage): ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA (in percentage): ");
        scanf("%f", &employees[i].da_percent);
    }
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp-id: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA: %.2f\n", employees[i].hra_percent);
        printf("DA: %.2f\n", employees[i].da_percent);
        printf("Gross Salary: %.2f\n", calculateGrossSalary(employees[i]));
    }
    return 0;
}
