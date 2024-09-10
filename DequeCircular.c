#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* esq;
    struct Node* dir;
}node;

typedef struct lis{
    node* init;
    node* fim;
    int size;
}lis;

node* getnode(int num){
    node* aux = malloc(sizeof(node));
    aux->data = num;
    aux->esq = aux;
    aux->dir = aux;
    return aux;
}

lis* insere_head(lis* lista, int num){
    node* new = getnode(num);
    if(lista->init == NULL){
        lista->fim = new;
    }
    else{
        new->dir = lista->init;
        lista->init->esq = new;
        lista->fim->dir = new;
    }
    lista->init = new;
    new->data = num;
    lista->size++;
    return lista;
}

lis* insere_rabo(lis* lista, int num){
    node* new = getnode(num);
    if(lista->init == NULL){
        lista->init = new;
    }
    else{
        new->esq = lista->fim;
        lista->fim->dir = new;
        lista->init->esq = new;
        new->dir = lista->init;
    }
    lista->fim = new;
    new->data = num;
    lista->size++;
    return lista;
}

lis* remove_head(lis* lista){
    node* lx = lista->init;
    if(lista->init == NULL){
        printf("Nada a remover");
    }
    else if(lista->size == 1){
        lista->init = lista->fim = NULL;
    }
    else{
        lista->init = lista->init->dir;
        lista->init->esq = lista->fim;
        lista->fim->dir = lista->init;
    }
    free(lx);
    lista->size--;
    return lista;
}

lis* remove_rabo(lis* lista){
    node* lx = lista->fim;
    if(lista->init == NULL){
        printf("Nada a remover!");
    }
    else if(lista->size == 1){
        lista->init = lista->fim = NULL;
    }
    else{
        lista->fim = lista->fim->esq;
        lista->fim->dir = lista->init;
        lista->init->esq = lista->fim;
    }
    free(lx);
    lista->size--;
    return lista;
}


void imprime(lis* p){
    if(p->init == NULL){
        printf("Nada a imprimir");
    }
    else{
        node* aux = p->init;
        printf("Tamanho atual: %i \n", p->size);
        do{
            printf("%i ", aux->data);
            aux = aux->dir;
        }while(aux != p->init); 
    }
        printf("\n");
}

int main(){
    lis* p = malloc(sizeof(lis));
    p->init = NULL;
    p->fim = NULL;
    insere_rabo(p, 1);
    insere_rabo(p, 2);
    insere_head(p, 0);
    insere_rabo(p, 4);
    imprime(p);


}
