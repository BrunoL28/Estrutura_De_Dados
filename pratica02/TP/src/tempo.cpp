#include "../include/tempo.hpp"

/**
 * @brief Função para medição do tempo de relógio.
 * @return double 
 */

double clockTime() {
    clock_t start = clock();
    return static_cast<double>( start ) / CLOCKS_PER_SEC;
}

/**
 * @brief Função para medir o tempo de utilização de recursos do usuário.
 * @param start 
 * @param end 
 * @return double 
 */

double userTime ( struct rusage *start, struct rusage *end ) {
    return ( end->ru_utime.tv_sec - start->ru_utime.tv_sec ) +
    1e-6 * ( end->ru_utime.tv_usec - start->ru_utime.tv_usec  );
}

/**
 * @brief Função para medir o tempo de utilização de recursos do sistema.
 * @param start 
 * @param end 
 * @return double 
 */

double systemTime ( struct rusage *start, struct rusage *end ) {
    return ( end->ru_stime.tv_sec - start->ru_stime.tv_sec ) + 
    1e-6 * ( end->ru_stime.tv_usec - start->ru_stime.tv_usec );
}