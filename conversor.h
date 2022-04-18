#include "pilha.h"

typedef struct contaItem {
    int valor;
    int operador;
} ContaItem;

typedef struct Conta {
    ContaItem *itens;
    int tamanho;
    int qtd_itens;
} Conta;

// Cria uma conta
Conta *conta_cria(int tamanho);

// Converte uma string de conta infix para sufix
void to_sufix(Conta *conta, char *infix_str);
