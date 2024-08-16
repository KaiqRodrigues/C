#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char nome[100];
    struct node *next;
    struct node *prev;
}node;

typedef struct lista{
    node* init;
    node* fim;
    int size;
}lista;

node* get_and_init_node(char* nome){
    node* p = malloc(sizeof(node));
    strcpy(p->nome, nome);
    p->nome[strlen(nome)] = '\0';
    p->next = p->prev = NULL;
    return p;
}

lista* insere_head(lista* p, char* nome){
    node* aux = get_and_init_node(nome);
    if(p->init == NULL){
        p->init = p->fim = aux;
        aux->next = aux;
        aux->prev = aux;
    }
    else{
        aux->next = p->init;
        aux->prev = p->fim;
        p->init->prev = aux;
        p->fim->next = aux;
        p->init = aux;
    }
    p->size++;
    return p;
}

lista* remove_soldado(lista* p, node* no){
    node* aux = p->init;
    while(aux != no){
        aux = aux->next;
    }
    if(p->init == aux){
        p->init = p->init->next;
        p->init->prev = p->fim;
        p->fim->next = p->init;
    }
    else if(p->fim == aux){
        p->fim = p->fim->prev;
        p->fim->next = p->init;
        p->init->prev = p->fim;
    }
    else{
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }
    
    printf("\nSai: %s", aux->nome);
    p->size--;
    free(aux);
    return p;
}

void imprime(lista *p){
    if(p->init == NULL){
        printf("\nNada a imprimir, vazio\n");
    }
    else{
        node* aux = p->init;
        do{
            printf("%s ", aux->nome);
            aux = aux->next;
        }while(aux != p->init);
    }
}

lista* recebe_nomes(lista* p){
    char name[100];
    while(1){
        printf("\nDigite um nome: ");
        scanf("%s", name);
        if(strcmp(name, "END") == 0){
            break;
        }
        insere_head(p, name);
    }
    return p ;
}

node* sorteio(lista* p){
    int num;
    node* aux = p->init;
    printf("\nInsira o numero: ");
    scanf("%i", &num);
    while(p->init != p->fim){
        for(int i = 1; i < num; i++){
            aux = aux->next;
        }
        remove_soldado(p, aux);
    }
    printf("\nFoge: %s", p->init->nome);
    free(aux);
}

int main(){
    lista* p = malloc(sizeof(lista));
    p->init = NULL;
    p->fim = NULL;
    p->size = 0;
    recebe_nomes(p);
    sorteio(p);
    

}