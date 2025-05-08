#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limparString(char* destino, const char* origem) {
    int j = 0;
    for (int i = 0; origem[i] != '\0'; i++) {
        if (isalpha(origem[i])) {
            destino[j++] = tolower(origem[i]);
        }
    }
    destino[j] = '\0';
}

int ehPalindromoRecursivo(const char* str, int inicio, int fim) {
    if (inicio >= fim) {
        return 1; 
    }
    if (str[inicio] != str[fim]) {
        return 0; 
    }
    return ehPalindromoRecursivo(str, inicio + 1, fim - 1);
}

int ehPalindromo(const char* frase) {
    char limpa[256];
    limparString(limpa, frase);
    int tamanho = strlen(limpa);
    return ehPalindromoRecursivo(limpa, 0, tamanho - 1);
}


int main() {

    const char* frases[] = {
        "A base do teto desaba",
        "A cara rajada da jararaca",
        "Acuda cadela da Leda caduca",
        "A dama admirou o rim da amada",
        "A droga do dote e todo da gorda",
        "o rato roeu a roupa do rei de roma",
        "o peito do pe de pedro e preto",
        "A mala nada na lama",
    };

    int n = sizeof(frases) / sizeof(frases[0]);
    for (int i = 0; i < n; i++) {
        printf("\"%s\" -> %s\n", frases[i], ehPalindromo(frases[i]) ? "Palíndromo" : "Não é palíndromo");
    }

    return 0;
}
