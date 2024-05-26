#include <stdio.h>

void troca(int *posicao1, int *posicao2){
    int temp = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = temp;
}


// pode ser vetor[] ou *vetor

void bubble(int vetor[], int tam){

    for(int n = tam-1; n > 0 ; n--){
        for(int i=0; i < n; i++ ){
            if(vetor[i] > vetor[i+1]){
                troca(&vetor[i], &vetor[i+1]);  // & para enviar o endereço para modificação do vetor na ordenação, caso contrario enviara o valor do vetor[i].     Na funcao troca, altera o valor com *
            }
        }
    }
}
int main(){
    int vetor[] = {9,5,3,1,7,4};
    int tam = sizeof(vetor) / sizeof(vetor[0]);   // 24 bytes (int tem o tamanho de 4 bytes, como tem 6 elementos = 24 bytes) dividido por  4 bytes (tamanho do int) = descobre quantos bytes, ou quantos endereços estam reservados para o vetor, que no caso seria 6

    bubble(vetor, tam);

    printf("Vetor Ordernado: \n");
    for(int i=0; i < tam;i++){

            printf("%d ", vetor[i]);

    }
}






