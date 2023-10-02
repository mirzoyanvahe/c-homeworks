#include <stdio.h>

struct Student {
    char* name;
    int mark;
};

char* getBestStudent(struct Student students[], int numStudents) {
    int highestMark = -1;
    char* BestStudentName = NULL;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].mark > highestMark) {
            highestMark = students[i].mark;
            BestStudentName = students[i].name;
        }
    }

    return BestStudentName;
}

int main() {
//example
    struct Student students[] = {
        {"Arman", 75},
        {"Mikayel", 95},
        {"Vahe", 50},
        {"Ani", 60},
        {"Hasmik", 70},
        {"Viktorya", 55},
        {"Albert", 90},
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    char* BestStudentName = getBestStudent(students, numStudents);

    if (BestStudentName != NULL)
        printf("The Best Student is: %s\n", BestStudentName);
    else
        printf("No students in the array.\n");

    return 0;
}
