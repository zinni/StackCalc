#include "calc.h"
#include "pilha.h"

//Verifica se o caracter � um digito
bool ehDigito(char c){
    return (c >= '0' && c <= '9');
}

//Verifica se o caracter eh um operador
bool ehOp(char c){
    return (c == '-' || c == '+' || c == '*' || c == '/' || c == '(' || c == ')');
}

//Determina precedencia do operador
int verPrecedencia (char c){
    switch(c){
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '(': return 3;
    case ')': return 3;
    default: return -1;
    }
}

//Faz a continha
int calcula(int val1, int val2, char op){
    if (op == '+') return val1 + val2;
    if (op == '-') return val1 - val2;
    if (op == '*') return val1 * val2;
    return val1 / val2;
}

int avaliar(char *s){
    Pilha* vals = init(40);
    Pilha* ops = init(40);

    int val = 0;
    int pos = 0;

    while (pos < strlen(s)){
        char spot = s[pos];
        if (ehDigito(spot)){
            val = (val * 10) + (int)(spot - '0');
        }
        else if (ehOp(spot)){
            if (spot == '('){
                empurra(ops, spot);
                val = 0;
            }
            if (vazia(vals)){
                empurra(vals, val);
                empurra(ops, spot);
                val = 0;
            }
            else if (spot == ')'){
                empurra(vals, val);
                while (olha(ops) != '('){
                    spot = popa(ops);
                    val = popa(vals);
                    int prev = popa(vals);
                    val = calcula(prev, val, spot);
                    empurra(vals, val);
                }
                popa(ops);
                popa(vals);
            }
            else{
                char prev = olha(ops);
                if(verPrecedencia(spot) > verPrecedencia(prev)){
                    empurra(vals, val);
                    empurra(ops, spot);
                    val = 0;
                }
                else{
                    int preval = popa(vals);
                    int prevop = popa(ops);
                    preval = calcula(preval, val, prevop);
                    empurra(vals, preval);
                    empurra(ops,spot);
                    val = 0;
                }
            }
        }
        pos++;
    }
    while(!vazia(ops)){
        int prev = popa(vals);
        char spot = popa(ops);
        val = calcula(prev, val, spot);
    }
    return val;
}
