#include <stdio.h>
#include "student.h"

void add_student(Student students[], int *count) {
    printf("Enter name: ");
    scanf("%s", students[*count].name);

    printf("Enter age: ");
    scanf("%d", &students[*count].age);

    printf("Enter grade: ");
    scanf("%f", &students[*count].grade);

    (*count)++;
}

void print_students(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
    }
}
