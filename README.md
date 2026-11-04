# Student Management System in C

A menu-driven console application for managing student records. It lets you add students, view and search records, update marks, calculate results, and find the student with the highest total marks.

## Features

- Add student records with a roll number, name, and marks in three subjects
- Prevent duplicate roll numbers
- Display all student records
- Search for a student by roll number
- Update a student's marks
- Calculate totals and percentages
- Find the student with the highest total marks
- Display the number of records currently in the system

## Requirements

- A C compiler such as GCC or Clang

## Build and run

From the repository directory, compile the program with GCC:

```sh
gcc -Wall -Wextra -std=c99 student_management.c -o student_management
```

Run it on macOS or Linux:

```sh
./student_management
```

On Windows ( using MinGW):

```sh
student_management.exe
```

## Usage

Choose an option from the menu and follow the prompts. Each student record contains a roll number, name, and marks for three subjects. The program calculates the total and percentage (out of 300).

The program stores records in memory while it is running. Records are not saved to a file, so they are cleared when you exit. The current maximum capacity is 100 students.

## Project file

- `student_management.c` — application source code

## License

No license has been specified for this project.
