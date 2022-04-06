#include "pilha.h"
#include "calc.h"

int main()
{
    Pilha *p1 = init(5);
    empurra(p1, 10);
    empurra(p1, 20);
    empurra(p1, 30);
    empurra(p1, 40);
    empurra(p1, 50);
    printf("Tamanho: %d\n", p1->tam);
    empurra(p1, 60);
    printf("Tamanho: %d\n", p1->tam);
    while(p1->top != -1){
        printf("%d\n", popa(p1));
    }
    printf("Vazia? (1) True e (0) False: ");
    printf("%d\n", vazia(p1));
    printf("40 * 2 = %d\n",calcula(40,2, '*'));
    printf("30 + 4 * 5 = %d\n",avaliar("30+4*5"));
    printf("(6+4)*(7-2) = %d\n",avaliar("(6+4)*(7-2)"));

    return 0;
}
