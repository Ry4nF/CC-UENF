#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz{
    int lin;
    int col;
    float **v;
};


Matriz* mat_cria (int m, int n){
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    if (mat == NULL) return NULL;
    
    mat->lin = m;
    mat->col = n;
    mat->v = (float**) malloc(m * sizeof(float*));
    if (mat->v == NULL) {
        free(mat);
        return NULL;
    }

    for (int i=0;i<m;i++){
        mat->v[i] = (float*) malloc(n * sizeof(float));
        if (mat->v[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(mat->v[j]);
            }
            free(mat->v);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void mat_libera ( Matriz* mat){
    if(mat != NULL){
        for (int i = 0; i < mat->lin; i++){
            free(mat->v[i]);
        }
        free(mat->v);
        free(mat);
    }
    mat = NULL;
}

float mat_acessa (Matriz* mat, int i, int j){
    if (i >= 0 && i < mat->lin && j >= 0 && j < mat->col) {
        return mat->v[i][j];
    }
}

void mat_atribui (Matriz* mat, int i, int j, float v){
    if (i >= 0 && i < mat->lin && j >= 0 && j < mat->col) {
        mat->v[i][j] = v;
    }
}


int mat_linhas ( Matriz* mat){
    return mat->lin;
}

int mat_colunas (Matriz* mat){
    return mat->col;
}
