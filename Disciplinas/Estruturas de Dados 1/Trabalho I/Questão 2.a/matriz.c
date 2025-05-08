#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz{
    int lin;
    int col;
    float *v;
};


Matriz* mat_cria (int m, int n){
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    if (mat == NULL) {
        return NULL;
    }
    mat->lin = m;
    mat->col = n;
    mat->v = (float*) malloc(m * n * sizeof(float));
    if (mat->v == NULL) {
        free(mat);
        return NULL;
    }
    return mat;
}

void mat_libera ( Matriz* mat){
    free(mat);
}

float mat_acessa (Matriz* mat, int i, int j){
    return mat->v[i * mat->col + j];
}

void mat_atribui (Matriz* mat, int i, int j, float v){
    mat->v[i *mat->col + j] = v;
}

int mat_linhas ( Matriz* mat){
    return mat->lin;
}

int mat_colunas (Matriz* mat){
    return mat->col;
}
