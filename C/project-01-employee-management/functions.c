#include <ctype.h>
#include <stdio.h>
#include "student.h"

 char g ;

//creat a File and openet
FILE* open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
    }
    return file;
}
//read file information 
int read_students(Student students[]) {
    FILE *file = open_file("students.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %s %d %c %f %s", 
                  &students[count].Id, 
                  students[count].name, 
                  &students[count].age, 
                  &students[count].Gender, 
                  &students[count].grade, 
                  students[count].class_name) == 6) {
        count++;
    }
 // To know the real number of students 
    fclose(file) ;
    return count;
}


 void add_student(Student students[], int *count) {
    printf("Enter ID : ");
    scanf("%d", &students[*count].Id);
    
    printf("Enter name: ");
    scanf("%s", students[*count].name);

    printf("Enter age: ");
    scanf("%d", &students[*count].age);
    do {
        printf("Enter Gender M for boy / F for girl: ");
        scanf("%c", &students[*count].Gender);
        g = toupper( students[*count].Gender);  
    }while (g != 'M' && g != 'F');

    printf("Enter grade: ");
    scanf("%f", &students[*count].grade);

    printf("Enter class_name : ");
    scanf("%s", &students[*count].class_name);
    

    (*count)++;

    FILE *file = open_file("students.txt", "a");
    if (file != NULL) 
    {
        fprintf(file, "%d %s %d %c %.2f %s\n",
                students[*count - 1].Id,
                students[*count - 1].name,
                students[*count - 1].age,
                students[*count - 1].Gender,
                students[*count - 1].grade,
                students[*count - 1].class_name);
        fclose(file);
    }

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

//sort students containing the same studentd sorted 

void sorted_students (Student students[], int cont)
{
    for (int i = 0; i < cont-1 ; i++ )
    {
        for(int j = 0 ; j < cont - i - 1 ; j++ )
        {
            if (students[j].grade < students[j + 1].grade)  
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }

         }
    }

}

//Save them in a file

void save_sorted_students (Student students[], int count )
{
    sorted_students (students , count );

    FILE *file = open_file("sorted_students.txt", "w");
    if (file == NULL) {
        printf("Failed to create sorted students file\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %c %.2f %s\n", 
                students[i].Id,
                students[i].name,
                students[i].age,
                students[i].Gender,
                students[i].grade,
                students[i].class_name);
    }
    fclose(file);
    printf("Students saved to sorted_students.txt successfully\n");
} 

void passed_students (Student students[], int count)
{
  FILE *file = open_file("passed_student.txt " , "w" ) ;
      if (file == NULL) 
      {
         printf("Failed to create sorted students file\n");
          return;
      }
            
     for (int i = 0 ; i < count ; i++ ) 
        {
         if(students[i].grade > 10 )
            {
              fprintf (file ," %d %s %d %c %.2f %s\n", 
                 students[i].Id,
                 students[i].name,
                 students[i].age,
                 students[i].Gender,
                 students[i].grade,
                 students[i].class_name);
             }
    
         }
    fclose(file);
    printf("Students saved passed_students.txt successfully \n ");
}

void save_by_Gender (Student students[], int count )
 {
    FILE *boys_file = open_file("boys.txt", "w");
        if (boys_file == NULL)
       {
             printf("Failed to create boys file\n");
            return;
       }


    FILE *girls_file = open_file("girls.txt", "w");
         if (girls_file == NULL)
        {
            printf("Failed to create girls file\n"); 
            fclose(boys_file); 
            return;
        }

     for (int i = 0 ; i <count ; i++ )
     {
         if (toupper(students[i].Gender) == 'M')
         {
                    fprintf (boys_file , " %d %s %d %c %.2f %s\n", 
                    students[i].Id,
                    students[i].name,
                    students[i].age,
                    students[i].Gender,
                    students[i].grade,
                    students[i].class_name);
          }  
         else if (toupper(students[i].Gender) == 'F')
                  {
     
                     fprintf(girls_file, "%d %s %d %c %.2f %s\n", 
                        students[i].Id,
                        students[i].name,
                        students[i].age,
                        students[i].Gender,
                        students[i].grade,
                        students[i].class_name);
                  }
    }


        fclose(boys_file);
        fclose(girls_file);



         
 }           
 