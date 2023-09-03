#include "../include/fatorial.hpp"

/**
 * @brief  Função que calcula o n-ésimo fatorial de forma recursiva. Isto é, com 
 * chamadas a si mesma. A ideia de retornar um unsigned long long visa evitar
 * um overflow, dado que o fatorial a partir de algum momento cresce muito, de forma
 * rápida.
 * @param n 
 * @return unsigned long long 
 */

unsigned long long fatorialRecursivo ( int n ) {
    if ( n == 0 ) {
        return 1;
    }
    if ( n == 1 ) {
        return 1;
    }
    return n * fatorialRecursivo( n - 1 );
}

/**
 * @brief Função que calcula o n-ésimo fatorial de forma iterativa. Diferente da função
 * recursiva, que executa tarefas quebrando-as em instãncias menores e mais simples de executar,
 * na função iterativa o procedimento é feito com instruções completas. 
 * A ideia de retornar um unsigned long long visa evitar um overflow, dado que 
 * o fatorial a partir de algum momento cresce muito, de forma rápida.
 * @param n 
 * @return unsigned long long 
 */

unsigned long long fatorialIterativo ( int n ) {
    if ( n == 0 ) {
        return 1;
    } else if ( n == 1 ) {
        return 1;
    } else {
        int fatorial = 1;
        for ( int i = n; i > 0; i-- ) {
            fatorial *= i;
        }
        return fatorial;
    }
    
}
