#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main() {
    List lista;
    initList(&lista);

    FILE* file = fopen("estudantes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int id;
    float cr;
    while (fscanf(file, "%d %f", &id, &cr) == 2) {
        Student* s = createStudent(id, cr);
        inserirFim(&lista, s);
    }

    fclose(file);

    printf("Lista de Estudantes:\n");
    printList(&lista);

    freeList(&lista);
    return 0;
}
