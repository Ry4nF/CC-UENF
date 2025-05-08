#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

typedef struct {
    Ponto* centro;
    float raio;
} Circulo;

// Funções do TAD Circulo
Circulo* criar_circulo(Ponto* pm, float raio);

void destruir_circulo(Circulo* c);

void obter_centro(Circulo* c, float *x, float *y);

void definir_centro(Circulo* c, float x, float y);

void definir_raio(Circulo* c, float raio);

float obter_raio(Circulo* c);

float calcular_area(Circulo* c);

float calcular_perimetro(Circulo* c);

int verificar_ponto_dentro(Circulo* c, Ponto* p);

#endif
