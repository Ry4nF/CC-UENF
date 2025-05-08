#include "circulo.h"
#include "ponto.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circulo* criar_circulo(Ponto* pm, float raio) {
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    if (c != NULL) {
        c->centro = criar_ponto(pm->x, pm->y); // Inicializa o centro do círculo
        if (c->centro == NULL) { // Verifica se a alocação do centro falhou
            free(c);
            return NULL;
        }
        c->raio = raio / 2;
    }
    return c;
}

void destruir_circulo(Circulo* c) {
    if (c != NULL) {
        destruir_ponto(c->centro);
        free(c);
    }
}

float calcular_area(Circulo* c) {
    return c ? M_PI * c->raio * c->raio : -1.0;
}

float calcular_perimetro(Circulo* c) {
    return c ? 2 * M_PI * c->raio : -1.0;
}

int verificar_ponto_dentro(Circulo* c, Ponto* p) {
    if (c != NULL && p != NULL) {
        float distancia = calcular_distancia(c->centro, p);
        return distancia <= c->raio;
    }
    return 0;
}
