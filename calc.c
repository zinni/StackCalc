#include <stdio.h>
#include "calc.h"

void calcular_conta(Conta *conta) {
    Stack *stack = stack_cria(5);
    int resultado;
    for (int i = 0; i < conta->qtd_itens; i++) {
        ContaItem item = conta->itens[i];
        if (item.operador) {
            int val2 = pop(stack);
            int val1 = pop(stack);
            switch (item.valor) {
                case '+':
                    resultado = val1 + val2;
                    break;
                case '-':
                    resultado = val1 - val2;
                    break;
                case '*':
                    resultado = val1 * val2;
                    break;
                case '/':
                    resultado = val1 / val2;
                    break;
            }
        } else {
            resultado = item.valor;
        }
        push(stack, resultado);
    }
    printf("\nResultado: %d\n", pop(stack));
}

void teste(Conta *conta, char *entrada){
    if (strlen(entrada) > 2){
        to_sufix(conta, entrada);
        calcular_conta(conta);
    } else {
        printf("\nSaindo do programa...\n");
    }
}
