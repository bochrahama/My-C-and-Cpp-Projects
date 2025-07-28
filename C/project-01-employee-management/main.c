#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
    Student students[100];
   int count= read_students(students);
     int choice;

    do {
        printf("\n1. Add student\n2. View students\n3. Sort students\n4. Save sorted\n5. Passed students\n6. Save by Gender\n0. Exit\nChoice: ");

        scanf("%d", &choice);

       switch (choice) {
    case 1:
        add_student(students, &count);
        break;
    case 2:
        print_students(students, count);
        break;
    case 3:
        sorted_students(students, count);
        break;
    case 4:
        save_sorted_students(students, count);
        break;
    case 5:
        passed_students(students, count);
        break;
    case 6:
        save_by_Gender(students, count);
        break;
    case 0:
        printf("Goodbye!\n");
        break;
    default:
        printf("Invalid choice.\n");
}

} while (choice != 0);
    
    
    return 0;
}

