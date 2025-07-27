#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
    Student students[100];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add student\n2. View students\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(students, &count);
                break;
            case 2:
                print_students(students, count);
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

