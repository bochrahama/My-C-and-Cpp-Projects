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
FILE* open_file(const char *filename, const char *mode);
int read_students(Student students[]);
void sorted_students (Student students[], int cont);
void save_sorted_students (Student students[], int count );
void passed_students (Student students[], int count);
void save_by_Gender (Student students[], int count );

#endif
