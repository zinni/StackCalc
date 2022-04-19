#include "calc.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    Conta *conta = conta_cria(20);
    char entrada[20];
    do {
        printf("\nDigite uma expressão:");
        fgets(entrada, sizeof entrada, stdin);
        teste(conta, entrada);
    } while(strlen(entrada) > 1 );
    return 1;
}
