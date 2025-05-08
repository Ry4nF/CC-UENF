#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

// Funções do TAD Ponto
Ponto* criar_ponto(float x, float y);

Ponto* calcular_ponto_medio(Ponto* p1, Ponto* p2);

void destruir_ponto(Ponto* p);

void obter_coordenadas(Ponto* p, float *x, float *y);

void definir_coordenadas(Ponto* p, float x, float y);

float calcular_distancia(Ponto* p1, Ponto* p2);

#endif
