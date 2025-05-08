#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"


int main(){

    srand(time(NULL));

    // Cria uma matriz 3x4
    Matriz* mat = mat_cria(3, 4);

    if (mat == NULL) {
        printf("Erro ao criar a matriz\n");
        return 1;
    }

    // Atribui valores à matriz
    for (int i = 0; i < mat_linhas(mat); i++){
        for (int j = 0; j < mat_colunas(mat); j++){
            float valor_aleatorio = (float)(rand() % 100) / 10.0; // Gera um número aleatório entre 0.0 e 9.9
            mat_atribui(mat, i, j, valor_aleatorio);
        }
    }
    
    // Imprime a matriz
    for (int i = 0; i < mat_linhas(mat); i++){
        for (int j = 0; j < mat_colunas(mat); j++){
            printf("%.2f ", mat_acessa(mat, i, j));
        }
        printf("\n");
    }

    mat_libera(mat);
    mat = NULL;

    if (mat == NULL) {
        printf("Matriz liberada com sucesso\n");
    } else {
        printf("Erro ao liberar a matriz\n");
    }

    return 0;
}