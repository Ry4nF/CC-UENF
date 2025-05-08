#include "ponto.h"
#include "circulo.h"
#include <stdio.h>

int main() {
    // Testando o TAD Ponto
    Ponto *p1 = criar_ponto(2.0, 3.0);
    Ponto *p2 = criar_ponto(5.0, 7.0);

    if (p1 == NULL || p2 == NULL) {
        printf("Erro ao criar os pontos.\n");
        destruir_ponto(p1);
        destruir_ponto(p2);
        return 1;
    }

    Ponto *pm = calcular_ponto_medio(p1, p2);
    if (pm == NULL) {
        printf("Erro ao calcular o ponto médio.\n");
        destruir_ponto(p1);
        destruir_ponto(p2);
        return 1;
    }

    float distancia = calcular_distancia(p1, p2);
    if (distancia < 0) {
        printf("Erro ao calcular a distância.\n");
        destruir_ponto(p1);
        destruir_ponto(p2);
        destruir_ponto(pm);
        return 1;
    }

    float x, y;
    obter_coordenadas(pm, &x, &y);
    printf("Ponto 1: (%.2f, %.2f)\n", p1->x, p1->y);
    printf("Ponto 2: (%.2f, %.2f)\n", p2->x, p2->y);
    printf("Ponto medio: (%.2f, %.2f)\n", x, y);
    printf("Distancia entre os pontos: %.2f\n", distancia);

    //Círculo
    Circulo *c1 = criar_circulo(pm, distancia);
    if (c1 == NULL) {
        printf("Erro ao criar o círculo.\n");
        destruir_ponto(p1);
        destruir_ponto(p2);
        destruir_ponto(pm);
        return 1;
    }

    printf("Circulo criado com centro em (%.2f, %.2f) e raio %.2f\n", pm->x, pm->y, distancia);
    printf("Area do Circulo: %.2f\n",  calcular_area(c1));
    printf("Perimetro do Circulo: %.2f\n", calcular_perimetro(c1));

    printf("Ponto 1 dentro do circulo: %s\n", verificar_ponto_dentro(c1, p1) ? "Sim" : "Nao");
    printf("Ponto 2 dentro do circulo: %s\n", verificar_ponto_dentro(c1, p2) ? "Sim" : "Nao");

    // Liberação de memória
    destruir_ponto(p1);
    destruir_ponto(p2);
    destruir_ponto(pm);
    destruir_circulo(c1);

    return 0;
}