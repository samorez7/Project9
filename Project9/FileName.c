#include <stdio.h>
#include <string.h>

// Define a structure for student
typedef struct {
    char name[50];    // Student name
    int year;         // Year of birth
    int course;       // Current course
    float avgGrade;   // Average grade
} Student;

// Function to print the list of students
void printStudents(Student students[], int n) {
    printf("%-20s %-15s %-10s %-10s\n", "Name", "Year of Birth", "Course", "Average Grade");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-15d %-10d %-10.2f\n", students[i].name, students[i].year, students[i].course, students[i].avgGrade);
    }
    printf("\n");
}

// Comparison functions for sorting
int compareByNameAsc(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int compareByNameDesc(const void* a, const void* b) {
    return strcmp(((Student*)b)->name, ((Student*)a)->name);
}

int compareByYearAsc(const void* a, const void* b) {
    return ((Student*)a)->year - ((Student*)b)->year;
}

int compareByYearDesc(const void* a, const void* b) {
    return ((Student*)b)->year - ((Student*)a)->year;
}

int compareByCourseAsc(const void* a, const void* b) {
    return ((Student*)a)->course - ((Student*)b)->course;
}

int compareByCourseDesc(const void* a, const void* b) {
    return ((Student*)b)->course - ((Student*)a)->course;
}

int compareByAvgGradeAsc(const void* a, const void* b) {
    if (((Student*)a)->avgGrade < ((Student*)b)->avgGrade) return -1;
    if (((Student*)a)->avgGrade > ((Student*)b)->avgGrade) return 1;
    return 0;
}

int compareByAvgGradeDesc(const void* a, const void* b) {
    if (((Student*)a)->avgGrade < ((Student*)b)->avgGrade) return 1;
    if (((Student*)a)->avgGrade > ((Student*)b)->avgGrade) return -1;
    return 0;
}

int main() {
    // Create a list of students
    Student students[] = {
        {"John Smith", 2001, 3, 85.2},
        {"Alice Johnson", 2002, 2, 90.5},
        {"Bob Brown", 2000, 4, 78.3},
        {"Emily Davis", 2003, 1, 92.4}
    };
    int n = sizeof(students) / sizeof(students[0]);

    // Print initial list of students
    printf("Initial list of students:\n");
    printStudents(students, n);

    // Sort and print by name
    printf("Sorted by name (ascending):\n");
    qsort(students, n, sizeof(Student), compareByNameAsc);
    printStudents(students, n);

    printf("Sorted by name (descending):\n");
    qsort(students, n, sizeof(Student), compareByNameDesc);
    printStudents(students, n);

    // Sort and print by year of birth
    printf("Sorted by year of birth (ascending):\n");
    qsort(students, n, sizeof(Student), compareByYearAsc);
    printStudents(students, n);

    printf("Sorted by year of birth (descending):\n");
    qsort(students, n, sizeof(Student), compareByYearDesc);
    printStudents(students, n);

    // Sort and print by course
    printf("Sorted by course (ascending):\n");
    qsort(students, n, sizeof(Student), compareByCourseAsc);
    printStudents(students, n);

    printf("Sorted by course (descending):\n");
    qsort(students, n, sizeof(Student), compareByCourseDesc);
    printStudents(students, n);

    // Sort and print by average grade
    printf("Sorted by average grade (ascending):\n");
    qsort(students, n, sizeof(Student), compareByAvgGradeAsc);
    printStudents(students, n);

    printf("Sorted by average grade (descending):\n");
    qsort(students, n, sizeof(Student), compareByAvgGradeDesc);
    printStudents(students, n);

    return 0;
}