#ifndef STUDENT_H
#define STUDENT_H


typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void add_student(Student students[], int *count);
void print_students(Student students[], int count);

#endif
