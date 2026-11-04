#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// Structure to hold student details
typedef struct {
    int roll_no;
    char name[50];
    float marks[3]; // Assuming 3 subjects for calculation
    float total;
    float percentage;
} Student;

// Global variables to keep track of students
Student students[MAX_STUDENTS];
int student_count = 0;

// Function Prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateMarks();
void calculateResults();
void findHighestMarks();
void displayTotalCount();

int main() {
    int choice;

    do {
        printf("\n=========================================\n");
        printf("   COLLEGE STUDENT MANAGEMENT SYSTEM\n");
        printf("=========================================\n");
        printf("1. Add Student Details\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Marks\n");
        printf("5. Calculate Total and Percentage\n");
        printf("6. Find Student with Highest Marks\n");
        printf("7. Display Total Number of Students\n");
        printf("8. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: calculateResults(); break;
            case 6: findHighestMarks(); break;
            case 7: displayTotalCount(); break;
            case 8: printf("\nExiting the system. Goodbye!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// 1. Function to add student details
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nError: Student database is full!\n");
        return;
    }

    Student new_student;

    printf("\nEnter Roll Number: ");
    scanf("%d", &new_student.roll_no);

    // Check if roll number already exists
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == new_student.roll_no) {
            printf("\nError: A student with this roll number already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf("%s", new_student.name); 

    printf("Enter marks for 3 subjects:\n");
    for (int i = 0; i < 3; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &new_student.marks[i]);
    }

    // Calculate total and percentage upon entry
    new_student.total = 0;
    for (int i = 0; i < 3; i++) {
        new_student.total += new_student.marks[i];
    }
    new_student.percentage = (new_student.total / 300.0) * 100; 

    // Add to array
    students[student_count] = new_student;
    student_count++;

    printf("\nStudent added successfully!\n");
}

// 2. Function to display all students
void displayStudents() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s %-10s %-10s\n", "Roll No", "Name", "Sub 1", "Sub 2", "Sub 3", "Percentage");
    printf("--------------------------------------------------------------------------\n");
    
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-20s %-10.2f %-10.2f %-10.2f %-10.2f%%\n", 
            students[i].roll_no, 
            students[i].name, 
            students[i].marks[0], 
            students[i].marks[1], 
            students[i].marks[2], 
            students[i].percentage);
    }
}

// 3. Function to search student by roll number
void searchStudent() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    int search_roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == search_roll) {
            printf("\n--- Student Found ---\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            printf("Total: %.2f\n", students[i].total);
            printf("Percentage: %.2f%%\n", students[i].percentage);
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", search_roll);
}

// 4. Function to update student marks
void updateMarks() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    int search_roll;
    printf("\nEnter Roll Number to update marks: ");
    scanf("%d", &search_roll);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == search_roll) {
            printf("\nEnter new marks for 3 subjects for %s:\n", students[i].name);
            for (int j = 0; j < 3; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }
            
            // Recalculate totals
            students[i].total = 0;
            for (int j = 0; j < 3; j++) {
                students[i].total += students[i].marks[j];
            }
            students[i].percentage = (students[i].total / 300.0) * 100;

            printf("\nMarks updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", search_roll);
}

// 5. Function to calculate total and percentage for all students
void calculateResults() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            students[i].total += students[i].marks[j];
        }
        students[i].percentage = (students[i].total / 300.0) * 100;
    }
    printf("\nTotal and Percentage calculated for all students successfully.\n");
}

// 6. Function to find student with highest marks
void findHighestMarks() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    int highest_index = 0;
    
    for (int i = 1; i < student_count; i++) {
        if (students[i].total > students[highest_index].total) {
            highest_index = i;
        }
    }

    printf("\n--- Student with Highest Marks ---\n");
    printf("Roll No: %d\n", students[highest_index].roll_no);
    printf("Name: %s\n", students[highest_index].name);
    printf("Total Marks: %.2f\n", students[highest_index].total);
    printf("Percentage: %.2f%%\n", students[highest_index].percentage);
}

// 7. Function to display total number of students
void displayTotalCount() {
    printf("\nTotal number of students in the system: %d\n", student_count);
}