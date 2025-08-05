#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining structure
typedef struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
} Student;

Student *head=NULL;

// create a new student node
Student* createStudent(int id, char *name, float marks){
    Student *newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// add student to linked list (tail)
void addStudent(int id, char *name, float marks){
    Student *newStudent = createStudent(id,name,marks);

    if (head == NULL){
        head = newStudent;
    } else {
        Student *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newStudent;  // fixed
    }
}

// display all students
void displayStudents(){
    Student *temp = head;
    if(!temp){
        printf("No Student Records Found !!! \n");
        return;
    }

    printf("\n Student Records : \n");
    while(temp != NULL){
        printf("ID : %d, Name : %s, Marks : %.2f\n", temp->id,temp->name,temp->marks);
        temp = temp->next;
    }
}

// save to binary file
void saveToFile(){
    FILE *fp = fopen("student.dat","wb");
    if(!fp){
        printf("Error while opening the file for writing \n");
        return;
    }

    Student *temp = head;
    while(temp != NULL){
        fwrite(temp, sizeof(Student) - sizeof(Student*),1,fp);
        temp = temp->next;
    }
    fclose(fp);
    printf("Data Saved to File Successfully ! \n");
}

// load binary file into linked list
void loadFromFile(){
    FILE *fp = fopen("student.dat","rb");
    if(!fp) return;

    Student temp;
    while(fread(&temp , sizeof(Student) - sizeof(Student*),1,fp)){
        addStudent(temp.id, temp.name, temp.marks);
    }

    fclose(fp);
    printf("Data loaded successfully from File ! \n");
}

// main
int main(){
    loadFromFile();

    int choice;
    do{
        printf("\n1. Add Student \n2. Display Students\n3. Save and Exit \n Enter Choice :");
        scanf("%d", &choice);

        if (choice == 1) {
            int id; char name[50]; float marks;
            printf("Enter ID: "); scanf("%d", &id);
            printf("Enter Name: "); scanf("%s", name);
            printf("Enter Marks: "); scanf("%f", &marks);
            addStudent(id, name, marks);
        } 
        else if (choice == 2) {
            displayStudents();
        } 
        else if (choice == 3) {
            saveToFile();
        }
    } while (choice != 3);

    // free memory
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
