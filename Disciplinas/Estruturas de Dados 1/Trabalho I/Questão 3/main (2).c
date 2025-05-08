#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void cria_vetor(int array1[]) {
    static int primeiro_vetor[100000];  // Vetor estático para armazenar os valores
    static int primeira_chamada = 1;  // Flag para verificar a primeira chamada
    
    if (primeira_chamada) {
        for (int i = 0; i < 100000; i++) {
            primeiro_vetor[i] = rand() % 101;
        }
        primeira_chamada = 0;  // Marca que já foi chamada
    }
    
    for (int i = 0; i < 100000; i++) {
        array1[i] = primeiro_vetor[i];
    }
}   


void Mostra_vetor (int array1[]){
    for (int i = 0; i < 100000; i++){
        printf ("%i ", array1[i]);}
    printf ("\n");
}

void bolha (int *array1, int N){
int i, continua, aux, max = N;
clock_t inicio, fim;
double tempo_execucao;
inicio = clock();
unsigned long long comparacoes = 0, atribuicoes = 0;
do{
     continua = 0;
    for (i = 0; i<max-1; i++){
        comparacoes++;
        if (array1[i] > array1[i+1])
        {aux = array1[i];
        array1[i] = array1[i+1];
        array1[i+1] = aux;
        atribuicoes += 3;
        continua = i;

        }
    }
    max--;
} while (continua != 0);
fim = clock(); 
tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
printf("Tempo de execucao: %.6f segundos\n", tempo_execucao); 
printf("Comparacoes: %llu\n", comparacoes);
printf("Atribuicoes: %llu\n", atribuicoes);
}

void selection(int *array1, int N){
int i, j, menor, troca; 
clock_t inicio, fim;
double tempo_execucao;
unsigned long long comparacoes = 0, atribuicoes = 0;
inicio = clock();
   for (i = 0; i < N-1; i++){
    menor = i;
    atribuicoes++;
       for (j = i+1; j < N; j++){
        comparacoes++;
           if (array1[j] < array1[menor]){
            menor = j;
            atribuicoes++;
           }
        comparacoes++;
        if (i != menor){
            troca = array1[i];
            array1[i] = array1[menor];
            array1[menor] = troca;
            atribuicoes += 3;
        }
       }
   }
   fim = clock(); 
   tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
   printf("Tempo de execucao: %.6f segundos\n", tempo_execucao); 
   printf("Comparacoes: %llu\n", comparacoes);
   printf("Atribuicoes: %llu\n", atribuicoes);
}

void insertion(int *array1, int N) {
    int i, j, atual;
    clock_t inicio, fim;
    double tempo_execucao;
    inicio = clock();
    unsigned long long comparacoes = 0, atribuicoes = 0;
    for (i = 1; i < N; i++) {        
        atual = array1[i]; 
        atribuicoes++;             
        j = i;
        atribuicoes++; 
       
        while (j > 0 && atual < array1[j - 1]) {
            comparacoes += 2;
            array1[j] = array1[j - 1]; 
            atribuicoes++;
            j--;
            atribuicoes++;
        }
        comparacoes += 2;
        array1[j] = atual;  
        atribuicoes++;          
    }
    fim = clock(); 
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao); 
    printf("Comparacoes: %llu\n", comparacoes);
    printf("Atribuicoes: %llu\n", atribuicoes);
}

int main(){
int array1[100000];

//criação do vetor e ordenação por bolha
/*printf ("Vetor de forma nao ordenada:\n");
cria_vetor(array1);
Mostra_vetor(array1);
printf ("vetor de forma ordenada por bolha:\n");
bolha (array1, 100000);
Mostra_vetor(array1);

//regenerando o vetor para o original e ordenando por selection sort
cria_vetor(array1);
printf ("vetor de forma ordenada por seleciton sort:\n");
selection (array1, 100000);
Mostra_vetor(array1);*/

//regenerando o vetor para o original e ordenando por insertion sort
cria_vetor(array1);
printf ("vetor de forma ordenada insertion sort:\n");
insertion(array1, 100000);
Mostra_vetor(array1);
return 0;
}