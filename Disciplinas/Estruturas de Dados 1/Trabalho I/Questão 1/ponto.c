#include "ponto.h"

Ponto* criar_ponto(float x, float y) {
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

Ponto* calcular_ponto_medio(Ponto* p1, Ponto* p2) {
    if (p1 != NULL && p2 != NULL) {
        Ponto* pm = (Ponto*)malloc(sizeof(Ponto));
        if (pm != NULL) {
            pm->x = (p1->x + p2->x) / 2;
            pm->y = (p1->y + p2->y) / 2;
        }
        return pm;
    }
    else return NULL;
}

float calcular_distancia(Ponto* p1, Ponto* p2) {
    if (p1 != NULL && p2 != NULL) {
        float dx = p2->x - p1->x;
        float dy = p2->y - p1->y;
        return sqrt(dx * dx + dy * dy);
    }
    return -1.0;
}

void destruir_ponto(Ponto* p) {
    free(p);
}

void obter_coordenadas(Ponto* p, float *x, float *y) {
    if (p != NULL) {
        *x = p->x;
        *y = p->y;
    }
}

/*void definir_coordenadas(Ponto* p, float x, float y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
}*/


