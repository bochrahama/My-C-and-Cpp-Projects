#ifndef STUDENT_H
#define STUDENT_H


typedef struct {
    int Id; 
    char name[50];
    int age;
    char Gender ;
    char class_name[50];
    float grade ;
} Student;

void add_student(Student students[], int *count);
void print_students(Student students[], int count);

#endif
