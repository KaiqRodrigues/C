#include <stdio.h>
#include <stdlib.h>




void troca(int *pos1, int *pos2){
    int aux = *pos1;
    *pos1 = *pos2;
    *pos2 = aux;
}


void selection(int *vetor, int size){
    int posicaoMaior;
    
    for(int slot = size-1; slot > 0; slot--){
        posicaoMaior = 0;
        for(int position = 0; position < slot+1; position++){
            if(vetor[position] > vetor[posicaoMaior]){
                posicaoMaior = position;
            }
        }
        troca(&vetor[slot], &vetor[posicaoMaior]);
    }

}

int main(){
    int size = 7;
    int *array = malloc(size * sizeof(int)); 
    
    for(int aux = 0; aux< size; aux++){
        scanf("%i", &array[aux]);
    }


    selection(array, size);
    for(int i= 0; i < size; i++){
        printf("%i", array[i]);
    }

}