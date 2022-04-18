#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"


Stack* stack_cria(int tamanho) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    int *valores = (int *)malloc(sizeof(int) * tamanho);
    if (valores == NULL) {
        printf("Erro tentando alocar espaço");
        return NULL;
    }
    free(stack->valores);
    stack->qtd = 0;
    stack->valores = valores;
    stack->tamanho = tamanho;
    return stack;
}

void stack_imprime(Stack *stack) {
    printf("[");
    for (int i = 0; i < stack->qtd;i++){
        if(i != 0) {
            printf(" ");
        }
        int valor = stack->valores[i];
        printf("%d", valor);
    }
    printf("]\n");
}

void push(Stack *stack, int valor) {
    if(stack->tamanho == stack->qtd) {
        int novo_tamanho = stack->tamanho * 2;
        int *valores = (int *)realloc(stack->valores, sizeof(int) * novo_tamanho);
        if(valores == NULL) {
            printf("Erro tentando alocar mais espaço");
            return;
        }
        stack->valores = valores;
        stack->tamanho = novo_tamanho;
    }
    stack->valores[stack->qtd] = valor;
    stack->qtd++;
}

int pop(Stack *stack) {
    if(stack->qtd == 0) {
        return -1;
    }
    stack->qtd -= 1;
    return stack->valores[stack->qtd];
}

int peek(Stack *stack) {
    if(stack->qtd == 0) {
        return -1;
    }
    return stack->valores[stack->qtd - 1];
}
