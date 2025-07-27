#include <ctype.h>
#include <stdio.h>
#include "student.h"

 char g ;
void add_student(Student students[], int *count) {
    printf("Enter ID : ");
    scanf("%d", &students[*count].Id);
    
    printf("Enter name: ");
    scanf("%s", students[*count].name);

    printf("Enter age: ");
    scanf("%d", &students[*count].age);
    do {
        printf("Enter Gender M for boy / F for girl: ");
        scanf(" %c ", &students[*count].Gender);
        g = toupper( students[*count].Gender);  
    }while (g != 'M' && g != 'F');

    printf("Enter grade: ");
    scanf("%f", &students[*count].grade);

    printf("Enter class_name : ");
    scanf("%s", &students[*count].class_name);
    

    (*count)++;
}

void print_students(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d\n", i + 1);
        printf("ID: %d\n", students[i].Id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Gender: %c\n", students[i].Gender);
        printf("Class: %s\n", students[i].class_name);
        printf("Grade: %.2f\n", students[i].grade);
    }
}
