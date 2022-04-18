#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conversor.h"

//Checa se o caracter da operação é um operador
int e_operador(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return 1;
    }
    return 0;
}

Conta* conta_cria(int tamanho) {
    Conta *conta = (Conta*) malloc(sizeof(Conta));
    ContaItem *itens = malloc(sizeof(ContaItem) * tamanho);
    if(itens == NULL) {
        printf("Erro tentando alocar memoria");
        return NULL;
    }
    conta->itens = itens;
    conta->tamanho = tamanho;
    conta->qtd_itens = 0;
    return conta;
}

//Realoca tamanho da Conta se necessário e adiciona itens a ela
void conta_adiciona(Conta* conta, ContaItem item) {
    if(conta->qtd_itens == conta->tamanho) {
        int novo_tamanho = conta->tamanho * 2;
        ContaItem *itens = (ContaItem *)realloc(conta->itens, sizeof(ContaItem) * novo_tamanho);
        if(itens == NULL) {
            printf("Erro tentando realocar memoria");
            return;
        }
        conta->itens = itens;
        conta->tamanho = novo_tamanho;
    }
    conta->itens[conta->qtd_itens] = item;
    conta->qtd_itens = conta->qtd_itens + 1;
}

//Tabela de precendencia de operadores
int valor_precedencia(char operador) {
    switch(operador) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '(':
            return 3;
        case ')':
            return 3;
        default:
            return 0;
        }
}

void adiciona_operador(Conta *conta, int operador) {
    ContaItem item;
    item.operador = 1;
    item.valor = operador;
    conta_adiciona(conta, item);
}

void adiciona_valor(Conta *conta, int *valor) {
    ContaItem item;
    item.operador = 0;
    item.valor = *valor;
    conta_adiciona(conta, item);
    *valor = 0;
}

//Faz a conferencia dos parenteses e o tratamento de procendencia dos operadores logicos
void trata_operador(Conta *conta, Stack *operadores, char operador, int *valor) {
    if (*valor) {
        adiciona_valor(conta, valor);
    }
    if (operador == '(' || peek(operadores) == -1) {
        push(operadores, operador);
        return;
    }
    if (operador == ')') {
        while (peek(operadores) != '(')
        {
            adiciona_operador(conta, pop(operadores));
        }
        pop(operadores); // retirando '('
        return;
    }
    int operador_anterior = peek(operadores);
    if (operador_anterior != '(' && valor_precedencia(operador_anterior) >= valor_precedencia(operador)) {
        adiciona_operador(conta, pop(operadores));
    }
    push(operadores, operador);
}

//Faz a conversão do infix pro postfix.
void to_sufix(Conta *conta, char *infix_str) {
    int valor = 0;
    int length = strlen(infix_str);
    Stack *operadores = stack_cria(10);

    for (int i = 0; i < length; i++) {
        char atual = infix_str[i];

        if (isdigit(atual)) {
            valor = valor * 10 + (int)(atual - '0');
        }

        if(e_operador(atual)) {
            trata_operador(conta, operadores, atual, &valor);
        }

        if(i==(length-1)) {
            if(valor) {
                adiciona_valor(conta, &valor);
            }
            while(peek(operadores) != -1) {
                adiciona_operador(conta, pop(operadores));
            }
        }
    }
}

// Material de apoio que usei pra tirar as notações
// https://panda.ime.usp.br/panda/static/pythonds_pt/02-EDBasicos/InfixPrefixandPostfixExpressions.html
