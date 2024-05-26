#include <stdio.h>

void bubble(int tam, int *vetor){

    int flag=1;

    while(flag==1){
        flag =0;
        for(int i=0; i<tam; i++){
            if(vetor[i]> vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                flag = 1;
        }
    }
}
}

int main(){

    int vetor[]= {7,2,9,4,1,3};
    bubble(6, vetor);


    for(int i= 0 ; i<6; i++){
        printf("%i", vetor[i]);
    }
    return 0;
}