typedef struct _stack {
    int *valores;
    int tamanho;
    int qtd;
} Stack;

//Cria estrutura de Stack
Stack *stack_cria(int tamanho);

//Imprime a estrutura de Stack
void stack_imprime(Stack *stack);

//Coloca item no Stack
void push(Stack *stack, int valor);

//Retira item do Stack
int pop(Stack *stack);

//Olha o item no topo da pilha
int peek(Stack *stack);
