// 12S23023 - Lenni Febriyani  
// 12S23031 - Matthew Pangihutan  
 
#include <stdio.h> 
#include <string.h>  
#include <stdlib.h>  
#include "./libs/dorm.h" 
#include "./libs/student.h" 
 
#define MAX_STUDENTS 100
#define MAX_DORMS 100

typedef struct {
    char id[10];
    char name[50];
    int year;
    char gender[10];
    char dorm_name[50];
    char dorm[50];
} Student;

typedef struct { 
    char name[50];
    char gender[10]; 
    int capacity; 
    int current;
    int resident_count;
    Student* students[100];
} Dorm;

Student students[100];
int student_count = 0;

Dorm* dorms = NULL;
int dorm_count = 0; 

void add_student(char* id, char* name, int year, char* gender) {
    strcpy(students[student_count].id, id);
    strcpy(students[student_count].name, name);
    students[student_count].year = year;
    strcpy(students[student_count].gender, gender);
    student_count++;
}

void add_dorm(char* name, int capacity, char* gender) { 
    dorms = realloc(dorms, (dorm_count + 1) * sizeof(Dorm));
    strcpy(dorms[dorm_count].name, name);
    dorms[dorm_count].capacity = capacity;
    strcpy(dorms[dorm_count].gender, gender);
    dorm_count++;
} 
  
void print_all_students() {
    for (int i = 0; i < student_count; i++) {
        printf("%s|%s|%d|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender);
    }
}

void print_all_dorms() { 
    for (int i = 0; i < dorm_count; i++) { 
        printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, dorms[i].gender); 
    }
}

int main() {
    char student[100];
    while (fgets(student, sizeof(student), stdin)) {
        if (strcmp(student, "---\n") == 0) {
            break;
        }
        char* token = strtok(student, "#\n");
        if (strcmp(token, "student-add") == 0) {
            char* id = strtok(NULL, "#\n");
            char* name = strtok(NULL, "#\n");
            int year = atoi(strtok(NULL, "#\n"));
            char* gender = strtok(NULL, "#\n");
            add_student(id, name, year, gender);
        } else if (strcmp(token, "student-print-all") == 0) {
            print_all_students();
        }
    }

    char dorm[100];
    while (fgets(dorm, sizeof(dorm), stdin)) { 
        if (strcmp(dorm, "---\n") == 0) { 
            break; 
        } 
        char* token = strtok(dorm, "#\n");
        if (strcmp(token, "dorm-add") == 0) { 
            char* name = strtok(NULL, "#\n");
            int capacity = atoi(strtok(NULL, "#\n"));
            char* gender = strtok(NULL, "#\n");
            add_dorm(name, capacity, gender);
        } else if (strcmp(token, "dorm-print-all") == 0) { 
            print_all_dorms();
        }
    } 
    free(dorms); 

    return 0; 
} 