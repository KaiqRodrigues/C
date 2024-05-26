#include <stdio.h>
#include <stdlib.h>

//int* retorna um ponteiro do tipo inteiro
int* receberNumeros(int tamanho)
{

    int *vetor = malloc(tamanho * sizeof(int));  //malloc retorna um ponteiro

    printf("\nInforme os número para o vetor: ");
    for(int cont = 0; cont < tamanho; cont++)
    {
        scanf("%i", &vetor[cont]);
    }


    return vetor;   //retorna o endereço do vetor criado
}

void troca(int *posicao1, int *posicao2)
{
    int aux = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = aux;
}
void bubble(int *vetor, int tam){
    for(int cont = tam-1; cont < tam; cont-- ){
        for(int i=0; i < cont; i++){
            if(vetor[i]>vetor[i+1]){

                troca(&vetor[i], &vetor[i+1]);
            }
        }
    }


}

int main(){

    int tam;
    printf("Informe o tamanho do vetor a ser criado: ");
    scanf("%i", &tam);

    int *array = receberNumeros(tam); // ponteiro recebe o endereço retornado na funcao

    printf("\nVetor Inicial: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%i", array[i]);
    }
    bubble(array, tam);

    printf("\nVetor Final: ");
    for (int i=0; i < tam; i++)
    {
    printf("%i", array[i]);
    }

}