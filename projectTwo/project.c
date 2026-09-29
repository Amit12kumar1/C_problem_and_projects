/*
2. Project: Advanced Employee Management System
 Project Overview
 The Employee Management System is a console-based application designed to
 handle various operations related to employee records. The project uses file
 handling in C to store employee data permanently. It provides features like adding
 employees, searching for employees by multiple criteria, updating records,
 generating reports, and managing salaries.
 This project focuses on applying concepts like modular programming, data
 structures, and file handling in a real-world application.
 System Features
 1. AddEmployee:
 ○ AddanewemployeewithID, name, department, designation, salary,
 and contact details.
 2. View All Employees:
 ○ Display all employee records in a tabular format.
 3. Search Employees:
 ○ Searchemployees by ID, name, or department.
 4. Update Employee Details:
 ○ Modifyemployee information like designation, salary, or contact
 details.
 5. Delete Employee:
 ○ Removeanemployeerecord permanently using their ID.
 6. Salary Management:
 ○ Viewandupdateemployee salary details.
 7. Generate Reports:
 ○ Generate a summary report of employees by department or salary
 range.
 8. Sort Employees:
 ○ Sortemployee records by name, ID, or salary.
 9. Exit Program:
 ○ Safely close the application.

Menu Options
 The program will present the following menu to the user:
 1. AddEmployee
 2. View All Employees
 3. Search Employee by ID/Name/Department
 4. Update Employee Details
 5. Delete Employee
 6. Manage Employee Salaries
 7. Generate Reports (e.g., Department-wise or Salary-wise)
 8. Sort Employees (e.g., by Name, ID, Salary)
 9. Exit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_DEPT_LEN 50
#define MAX_DESIG_LEN 50
#define MAX_CONTACT_LEN 20
#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char department[MAX_DEPT_LEN];
    char designation[MAX_DESIG_LEN];
    double salary;
    char contact[MAX_CONTACT_LEN];
} Employee;

// Function prototypes
void addEmployee();
void viewAllEmployees();
void searchEmployee();
void updateEmployeeDetails();
void deleteEmployee();
void manageSalaries();
void generateReports();
void sortEmployees();
void displayMenu();

// Helper function to search for an employee by ID
Employee getEmployeeByID(int id);

// Helper function to search for an employee by name
Employee getEmployeeByName(const char* name);

// Helper function to search for an employee by department
Employee getEmployeeByDepartment(const char* department);

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployeeDetails();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                manageSalaries();
                break;
            case 7:
                generateReports();
                break;
            case 8:
                sortEmployees();
                break;
            case 9:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n----- Employee Management System -----\n");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Search Employee by ID/Name/Department\n");
    printf("4. Update Employee Details\n");
    printf("5. Delete Employee\n");
    printf("6. Manage Employee Salaries\n");
    printf("7. Generate Reports\n");
    printf("8. Sort Employees\n");
    printf("9. Exit\n");
    printf("------------------------------------\n");
}

void addEmployee() {
    Employee employee;
    FILE *file = fopen(FILE_NAME, "ab");  // Open file in append binary mode

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &employee.id);
    getchar();  // To consume the newline character left by scanf

    printf("Enter Employee Name: ");
    fgets(employee.name, MAX_NAME_LEN, stdin);
    employee.name[strcspn(employee.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Department: ");
    fgets(employee.department, MAX_DEPT_LEN, stdin);
    employee.department[strcspn(employee.department, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(employee.designation, MAX_DESIG_LEN, stdin);
    employee.designation[strcspn(employee.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%lf", &employee.salary);
    getchar();

    printf("Enter Contact: ");
    fgets(employee.contact, MAX_CONTACT_LEN, stdin);
    employee.contact[strcspn(employee.contact, "\n")] = '\0';

    fwrite(&employee, sizeof(Employee), 1, file);  // Write employee record to the file
    fclose(file);
    printf("Employee added successfully.\n");
}

void viewAllEmployees() {
    Employee employee;
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("No employee records found!\n");
        return;
    }

    printf("\nID\tName\t\tDepartment\tDesignation\tSalary\tContact\n");
    printf("---------------------------------------------------------------\n");

    while (fread(&employee, sizeof(Employee), 1, file)) {
        printf("%d\t%s\t%s\t%s\t%.2f\t%s\n", employee.id, employee.name, employee.department, employee.designation, employee.salary, employee.contact);
    }

    fclose(file);
}

void searchEmployee() {
    int choice;
    printf("\nSearch Employee by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Department\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    getchar(); // To consume newline character

    Employee employee;
    switch (choice) {
        case 1:
            printf("Enter Employee ID: ");
            int id;
            scanf("%d", &id);
            employee = getEmployeeByID(id);
            if (employee.id != 0) {
                printf("Employee found: \n");
                printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\nContact: %s\n", employee.id, employee.name, employee.department, employee.designation, employee.salary, employee.contact);
            } else {
                printf("Employee not found.\n");
            }
            break;
        case 2:
            printf("Enter Employee Name: ");
            char name[MAX_NAME_LEN];
            fgets(name, MAX_NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0';
            employee = getEmployeeByName(name);
            if (employee.id != 0) {
                printf("Employee found: \n");
                printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\nContact: %s\n", employee.id, employee.name, employee.department, employee.designation, employee.salary, employee.contact);
            } else {
                printf("Employee not found.\n");
            }
            break;
        case 3:
            printf("Enter Employee Department: ");
            char department[MAX_DEPT_LEN];
            fgets(department, MAX_DEPT_LEN, stdin);
            department[strcspn(department, "\n")] = '\0';
            employee = getEmployeeByDepartment(department);
            if (employee.id != 0) {
                printf("Employee found: \n");
                printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\nContact: %s\n", employee.id, employee.name, employee.department, employee.designation, employee.salary, employee.contact);
            } else {
                printf("Employee not found.\n");
            }
            break;
        default:
            printf("Invalid choice\n");
    }
}

void updateEmployeeDetails() {
    int id;
    Employee employee;
    FILE *file = fopen(FILE_NAME, "rb+"); // Open file in read-write binary mode

    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    employee = getEmployeeByID(id);
    if (employee.id != 0) {
        printf("Enter new Designation: ");
        getchar();  // To consume newline character
        fgets(employee.designation, MAX_DESIG_LEN, stdin);
        employee.designation[strcspn(employee.designation, "\n")] = '\0';

        printf("Enter new Salary: ");
        scanf("%lf", &employee.salary);
        getchar();

        printf("Enter new Contact: ");
        fgets(employee.contact, MAX_CONTACT_LEN, stdin);
        employee.contact[strcspn(employee.contact, "\n")] = '\0';

        fseek(file, (employee.id - 1) * sizeof(Employee), SEEK_SET);  // Move file pointer to correct position
        fwrite(&employee, sizeof(Employee), 1, file);
        printf("Employee details updated successfully.\n");
    } else {
        printf("Employee not found.\n");
    }

    fclose(file);
}

void deleteEmployee() {
    int id;
    Employee employee;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&employee, sizeof(Employee), 1, file)) {
        if (employee.id == id) {
            found = 1;
        } else {
            fwrite(&employee, sizeof(Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);  // Remove the original file
        rename("temp.dat", FILE_NAME);  // Rename the temp file to original file name
        printf("Employee record deleted successfully.\n");
    } else {
        printf("Employee not found.\n");
        remove("temp.dat"); // Clean up temporary file if no deletion occurred
    }
}

void manageSalaries() {
    int id;
    Employee employee;
    FILE *file = fopen(FILE_NAME, "rb+");

    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Employee ID to manage salary: ");
    scanf("%d", &id);

    employee = getEmployeeByID(id);
    if (employee.id != 0) {
        printf("Enter new Salary: ");
        scanf("%lf", &employee.salary);

        fseek(file, (employee.id - 1) * sizeof(Employee), SEEK_SET);
        fwrite(&employee, sizeof(Employee), 1, file);
        printf("Salary updated successfully.\n");
    } else {
        printf("Employee not found.\n");
    }

    fclose(file);
}

void generateReports() {
    // Generate report based on department or salary range.
    // This function can be extended to create detailed reports
    printf("Generate reports functionality is under construction.\n");
}

void sortEmployees() {
    // Implement sorting functionality here
    printf("Sorting functionality is under construction.\n");
}

// Helper function implementations

Employee getEmployeeByID(int id) {
    FILE *file = fopen(FILE_NAME, "rb");
    Employee employee = {0};

    if (file == NULL) {
        printf("Error opening file!\n");
        return employee;
    }
    while (fread(&employee, sizeof(Employee), 1, file)) {
        if (employee.id == id) {
            fclose(file);
            return employee;
        }
    }
    fclose(file);
    return employee;
}

Employee getEmployeeByName(const char* name) {
    FILE *file = fopen(FILE_NAME, "rb");
    Employee employee = {0};

    if (file == NULL) {
        printf("Error opening file!\n");
        return employee;
    }

    while (fread(&employee, sizeof(Employee), 1, file)) {
        if (strcmp(employee.name, name) == 0) {
            fclose(file);
            return employee;
        }
    }

    fclose(file);
    return employee;
}

Employee getEmployeeByDepartment(const char* department) {
    FILE *file = fopen(FILE_NAME, "rb");
    Employee employee = {0};

    if (file == NULL) {
        printf("Error opening file!\n");
        return employee;
    }

    while (fread(&employee, sizeof(Employee), 1, file)) {
        if (strcmp(employee.department, department) == 0) {
            fclose(file);
            return employee;
        }
    }

    fclose(file);
    return employee;
}
