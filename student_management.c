#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    int id;
    char name[100];
    double cgpa;
    char gender[10];
    struct Student *next; //pointer to next student in linked list
} Student;

Student *head = NULL; //this pointer points to the head of the linked list

void add_student(int id, char *name, double cgpa, char *gender){
    Student *student = malloc(sizeof(Student)); //dynamically allocate memory for each student
    //malloc failure check
    if(!student){
        printf("Memory allocation failed.\n");
        return;
    }
    Student *check = head; //pointer to check if the ID is already in class, to avoid duplicates
    while(check){
        if(check -> id == id){
            printf("ID %d is already present in class.\n", id);
            free(student);
            return;
        }
        check = check -> next;
    }
    student -> id = id;
    strcpy(student -> name, name);
    if(cgpa > 4.0 || cgpa < 0.0){
        printf("Invalid CGPA.\n");
        free(student);
        return;
    }
    student -> cgpa = cgpa;
    strcpy(student -> gender, gender);
    //standard algorithm to insert new node in a linked list
    student -> next = head;
    head = student;
    printf("Student %s has been added to class.\n", name);
}

//function to update or change student details
void update_student(int id){
    char update_name[100];
    char update_gender[10];
    double update_cgpa;
    char temp[50];
    Student *update = head;
    while(update){
        if(update -> id == id){
            printf("Update Student Name:\n");
            fgets(update_name, sizeof(update_name), stdin);
            update_name[strcspn(update_name, "\n")] = '\0';
            strcpy(update -> name, update_name);
            
            printf("Update Student Gender:\n");
            fgets(update_gender, sizeof(update_gender), stdin);
            update_gender[strcspn(update_gender, "\n")] = '\0';
            strcpy(update -> gender, update_gender);
            
            printf("Update Student CGPA:\n");
            fgets(temp, sizeof(temp), stdin);
            update_cgpa = atof(temp);
            if(update_cgpa > 4.0 || update_cgpa < 0.0){
            printf("Invalid CGPA.\n");
            return;
            }
            update -> cgpa = update_cgpa;
            
            printf("Student information updated successfully.\n");
            return;
        }
        update = update -> next;
    }
    printf("Student with ID %d not found.\n", id);
    
}

void delete_student(int id){
    Student *previous = NULL; //this points to previous node in the linked list
    Student *current = head; //this will point to the student info to be deleted
    //loop to find the student info to be deleted
    while((current) && current -> id != id){
        previous = current;
        current  = current -> next;
    }
    if(!current){
        printf("Student id not found.\n");
        return;
    }
    //if statement in the case previous is not NULL, meaning the node to be deleted is not the first one 
    if(previous){
        previous -> next = current -> next; 
    }
    // if previous is NULL, i.e the node to be deleted is the first one
    else{
        head = current -> next;
    }
    free(current); //free memory allocated for the student info to be deleted, basically deleting the student info
    printf("Student information with ID %d deleted.\n", id);
    
}

void search_student(int id){
    Student *find = head;
    while(find){
        if (find -> id == id){
            printf("ID: %d\nName: %s\nCGPA: %f\nGender: %s\n", find -> id, find -> name, find -> cgpa, find -> gender);
            return;
        }
        find = find -> next;
    }
    printf("Student not found.\n");
}

//displays info of all the students in the class
void display_all(){
    printf("\n+-------+-------------------------------+-----------+-------+\n");
    printf("| ID    | Name                          | Gender    | CGPA  |\n");
    printf("+---------------------------------------+-----------+-------+\n");
    Student *current = head;
    while(current){
        printf("| %-6d| %-30s| %-10s| %-6.2f|\n", current -> id, current -> name, current -> gender, current -> cgpa);
        current = current -> next;
    }
    printf("+-------+-------------------------------+-----------+-------+\n");
}

int main(){
    char choice;
    int id;
    char name[100];
    char gender[10];
    double cgpa;
    printf("Welcome to the Student Management System for this Class. Please select an option from the menu below:\n");
    while(1){
    printf("A: Add a new student\nB: Update student information\nC: Delete student information\nD: Search student\nE: Display all students in class\nF: Exit\n");
    scanf(" %c", &choice);
    if(choice=='F'){
        printf("Exiting Student Management System.\n");
        break;
    }
    else if(choice=='A'){
        getchar();
        printf("Please enter student's name:\n");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Please enter student's gender: type 'male' for males or 'female' for females:\n");
        fgets(gender, sizeof(gender), stdin);
        gender[strcspn(gender, "\n")] = '\0';
        printf("Please enter the student ID:\n");
        scanf("%d", &id);
        printf("Please enter the student's CGPA:\n");
        scanf("%lf", &cgpa);
        getchar();
        add_student(id, name, cgpa, gender);
    }
    else if(choice=='B'){
        printf("Please enter the student ID:\n");
        scanf("%d", &id);
        getchar();
        update_student(id);
    }
    else if(choice=='C'){
        printf("Please enter the student ID:\n");
        scanf("%d", &id);
        delete_student(id);
    }
    else if(choice=='D'){
        printf("Please enter the student ID:\n");
        scanf("%d", &id);
        search_student(id);
    }
    else if(choice=='E'){
        display_all();
    }
    else{
        printf("Invalid choice.\n");
    }
    }
    
    return 0;
}

