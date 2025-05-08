#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Student* createStudent(int id, float cr) {
    Student* s = (Student*) malloc(sizeof(Student));
    if (s == NULL) {
        printf("Erro ao alocar memória para estudante.\n");
        exit(1);
    }
    s->id = id;
    s->cr = cr;
    return s;
}

void initList(List* list) {
    list->head = NULL;
}

void insertirFim(List* list, Student* student) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    newNode->data = student;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int compare(float a, float b) {
    if (a < b) return -1;
    if (a == b) return 0;
    return 1;
}

void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("ID: %d | CR: %.2f\n", current->data->id, current->data->cr);
        current = current->next;
    }
}

void freeList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
}
