#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calc.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    Conta *conta = conta_cria(20);
    char entrada[20];
    while(strlen(entrada) != 0 ){
        printf("\nDigite uma express�o:");
        gets(entrada);
        to_sufix(conta, entrada);
        calcular_conta(conta);
    }
    return 1;
}
