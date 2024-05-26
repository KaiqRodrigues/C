#include <stdio.h>
#include <stdlib.h>

void troca(int *posicao1, int *posicao2){

    int temp = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = temp;
}

void bubble(int tamanho, int *vetor){

    int flag = 1;
    int passnum = tamanho-1;

    while(passnum > 0 && flag==1){
        flag = 0;
        for(int i= 0; i<passnum; i++){
            if(vetor[i]> vetor[i+1]){
                troca(&vetor[i], &vetor[i+1]);
                flag=1;
            }
        }passnum = passnum-1;
    }
    
}

int* recebeNumeros(int tamanho){

    int *array = malloc(tamanho * sizeof(int));

    printf("Digite os numeros a inserir no vetor: \n");
    for(int cont=0; cont<tamanho; cont++){
        scanf("%i", &array[cont]);
    }
    printf("O vetor que voce digitou: ");
    for(int cont= 0; cont<tamanho; cont++){
        printf("%i", array[cont]);
    }

    return array; //retorna o endereço do array
}




int main(){

    int tam;
    int *vetor;

    printf("\nInforme o tamanho do vetor a ser criado: \n");
    scanf("%i", &tam);

    vetor = recebeNumeros(tam);
    bubble(tam, vetor);
    printf("\nVetor ordenado: ");
    for(int cont= 0; cont<tam; cont++){
        printf("%i", vetor[cont]);
    }




}