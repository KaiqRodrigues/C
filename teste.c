#include <stdio.h>
#include <stdlib.h>


int* recebeNumeros(int tamanho){

    int *array = malloc(tamanho * sizeof(int));

    printf("Digite os numeros a inserir no vetor: ");
    for(int cont=0; cont<tamanho; cont++){
        scanf("%i", &array[cont]);
        printf("Digite mais um numero: ");
    }
    printf("O vetor que voce digitou: ");
    for(int cont= 0; cont<tamanho; cont++){
        printf("%i", array[cont]);
    }

    return array; //retorna o endereço do array
}




int main(){

    int tam;
    int vetor[] = {};

    printf("Informe o tamanho do vetor a ser criado: \n");
    scanf("%i", &tam);

    *vetor = recebeNumeros(tam);
    for(int cont= 0; cont<tam; cont++){
        printf("%i", vetor[cont]);
    }

}