#include <stdio.h>
#include <stdlib.h>



void troca(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}



void selecao(int *array, int tamanho){

    int posicaoMenor;

    for(int slot=0;slot < tamanho-1; slot++){
        posicaoMenor = slot;
        for(int posicao = slot+1; posicao < tamanho; posicao++){
            if(array[posicao] < array[posicaoMenor]){
                posicaoMenor = posicao;
            }
        }
        troca(&array[slot], &array[posicaoMenor]);
    }   

}


int main(){

    int size = 6;
    int *array = malloc(size * sizeof(int)); 

    for(int aux = 0; aux< size; aux++){
        scanf("%i", &array[aux]);
    }

    selecao(array, size);
    
    for(int i= 0; i < size; i++){
        printf("%i ", array[i]);
    }


}