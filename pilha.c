#include "pilha.h"

//Inicialização dinamica da Pilha
Pilha* init(int tam){
    Pilha *ph = (Pilha*)malloc(sizeof(Pilha));
    if(ph == NULL){
        printf("erro de memoria");
        exit(1);
    }
    ph->data = (int*)malloc(sizeof(int) * tam);
    if(ph->data == NULL){
        printf("erro de memoria");
        exit(1);
    }
    ph->top = -1;
    ph->tam = tam;
    return ph;
}

void empurra(Pilha *ph, int valor){
    if (ph->top == ph->tam - 1){
        //Se cheio, dobra o tamanho do stack
        int* temp = (int*)malloc(sizeof(int) * ph->tam * 2);
            if (temp == NULL){
                printf("erro de memoria");
                return;
            }
            for(int i = 0; i <= ph->top; i++){
                temp[i] = ph->data[i];
            }
            free(ph->data);
            ph->data = temp;
            ph->tam *= 2;
        }
    ph->data[++ph->top] = valor;
}

int popa(Pilha *ph){
    if(ph->top == -1){
        return -1;
    }
    else{
        return ph->data[ph->top--];
    }
}

int olha(Pilha *ph){
    if(ph->top == -1){
        return -1;
    }
    else{
        return ph->data[ph->top];
    }
}

int vazia(Pilha *ph){
    return (ph->top == -1);
}
