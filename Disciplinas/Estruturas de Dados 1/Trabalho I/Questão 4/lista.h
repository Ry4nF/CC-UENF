#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int id;
    float cr;
} Student;

typedef struct Node {
    Student* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void initList(List* list);

Student* createStudent(int id, float cr);

void inserirFim(List* list, Student* student);

int compare(float a, float b);

void printList(List* list);

void freeList(List* list);

#endif
