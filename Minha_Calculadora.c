//ALUNO:      ALEXANDRE DOS SANTOS BINDO CABRAL
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

//variaveis globais
int *pont;         // para apontar pra uma espaço de memoria livre
int *topo_pil;  // ponteiro que indicará o topo da pilha
int *fim_pil;  // ponteiro que indicará o fim da da pilha

//escopo das funções
void push (int valor);
int pop (void);



int main()
{
int x, y, raiz, ptcia;    
char str[80];
pont =(int *) malloc(MAX*sizeof(int));  //aloca uma memoria dinamica
if(!pont){
    printf("problemas para alocar memória\n");
    exit(1);
    
}
topo_pil = pont;
fim_pil = pont + MAX-1;
printf("*** Minha calculadora digite 'q' se desejar sair ou um numero  ****");

do
{
    
    printf(": ");
    gets(str);
    switch (*str)
    {
    case '+':
    x = pop();
    y = pop();
    printf("%d\n",y+x);
    push(y+x);
        break;


    case '-':
    x = pop();
    y = pop();
    printf("%d\n",y-x);
    push(y-x);
        break;

        
    case '*':
    x = pop();
    y = pop();
    printf("%d\n",y*x);
    push(y*x);
        break; 

        
    case '/':
    x = pop();
    y = pop();

    if(x==0){
        printf("não exist divisão por zero\n");
        break;
    }
    printf("%d\n",y/x);
    push(y/x);
        break;


    case '#':
    x = pop();
    y = pop();
    raiz = sqrt (x);
    
    printf("%d\n", raiz);
    push(raiz);
        break;



    case '^':
    x = pop();
    y = pop();
    ptcia = pow(x, y);

    printf("%d\n", ptcia);
    push(ptcia);
        break; 

     

    case '.':
    x = pop();
    push(x);
    printf("valor esta no topo da pilha:  %d\n", x);
        break;        
    
    
    default:
    push(atoi (str));
        break;

    }
    printf("digite o proximo dado ");
} while (*str!='q');



    return 0;
}

//corpo das funções:

//função coloca elemento no topo da pilha
void push (int valor){
    if(pont>fim_pil){
        printf("pilha lotada\n");
        return;
    }
    *pont = valor;
    pont++;


}

//função retira elemento do topo da pilha
int pop (void){
    pont--;
    if(pont<topo_pil){
        printf("pilha vazia\n");
        return 0;
    }
    return *pont;
    

}







