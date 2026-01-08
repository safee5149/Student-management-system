Overview:
This project is a simple classroom student management system written in C. It supports basic CRUD (Create, Read, Update, Delete) operations and demonstrates fundamental concepts of systems programming in C.
Features:
•	Add new students with validation
•	Update current student information
•	Delete students using their ID
•	Search for a student using the ID
•	Display all the students in the classroom in a formatted table
•	Menu driven command line interface
•	Dynamic memory allocation using malloc and free.

Data Structure:
Each student is represented using a C struct and stored in a singly linked list.
typedef struct Student{
    int id;
    char name[100];
    double cgpa;
    char gender[10];
    struct Student *next; //pointer to next student in linked list
} Student;

Technologies used:
•	Language: C
•	Concepts:
o	Structs
o	Pointers
o	Linked Lists
o	Dynamic Memory Allocation
o	Input Validation
o	Command Line Interface
Menu Options: 
When the program runs, the user is presented with the following menu:
Welcome to the Student Management System for this Class. Please select an option from the menu below:
A: Add a new student
B: Update student information
C: Delete student information
D: Search student
E: Display all students in class
F: Exit

Input validation:
The program uses basic input validation for data integrity. It:
•	Prevents duplication of student IDs
•	Ensures CGPA is withing a valid range (0.0-4.0)
•	Checks for malloc failure
•	Handles invalid menu inputs

How to compile and run:
Compile:
gcc student_management.c -o student management
Run:
For Windows:
student_management 
For Linux/macOS:
./student_management

Possible Improvements:
•	File handling
•	Sorting students by CGPA
•	Statistical analysis


Author:
Developed this project as a learning project to practise C programming and data structures with a real-world application.

This project was created to:
•	Improve understanding of linked lists in C
•	Practise programming skills and memory allocation
•	As an academic project to add on my resume
