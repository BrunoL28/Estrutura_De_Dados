#include "../include/fibonacci.hpp"

/**
 * @brief Função que calcula o n-ésimo número da sequência de Fibonacci de forma recursiva. Isto é, com 
 * chamadas a si mesma. A ideia de retornar um unsigned long long visa evitar
 * um overflow, dado que a sequência a partir de algum momento cresce muito, de forma
 * rápida.
 * @param n 
 * @return unsigned long long 
 */

unsigned long long fibonacciRecursivo ( int n ) {
    if ( n == 0 ) { 
        return 0;
    }
    if ( n == 1 || n == 2 ) {
        return 1;
    }
    return fibonacciRecursivo( n - 1 ) + fibonacciRecursivo( n - 2 );
}

/**
 * @brief Função que calcula o n-ésimo número da sequência de Fibonacci de forma iterativa. Diferente 
 * da função recursiva, que executa tarefas quebrando-as em instãncias menores e mais simples 
 * de executar, na função iterativa o procedimento é feito com instruções completas. 
 * A ideia de retornar um unsigned long long visa evitar um overflow, dado que 
 * a sequência de Fibonacci a partir de algum momento cresce muito, de forma rápida.
 * 
 * @param n 
 * @return unsigned long long 
 */

unsigned long long fibonacciIterativo ( int n ) {
    unsigned long long anterior = 0;
    unsigned long long atual = 1;
    unsigned long long proximo = 0;

    if ( n <= 1 ) {
        return n;
    } 
    
    for ( int i = 2; i <= n; i++ ) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}
