#include "../include/tempo.hpp"

/**
 * @brief Função para medir o tempo de utilização de recursos do usuário.
 * @param start 
 * @param end 
 * @return double 
 */

double userTime () {
    struct rusage time;
    getrusage( RUSAGE_SELF, &time );
    double userTime = ( ( ( double )time.ru_utime.tv_sec + ( double )time.ru_utime.tv_usec ) / 1000000 );
    return userTime;
}

/**
 * @brief Função para medir o tempo de utilização de recursos do sistema.
 * @param start 
 * @param end 
 * @return double 
 */

double systemTime () {
    struct rusage time;
    getrusage( RUSAGE_SELF, &time );
    double systemTime = ( ( ( double )time.ru_stime.tv_sec + ( double )time.ru_stime.tv_usec ) / 1000000 );
    return systemTime;
}

/**
 * @brief Função que recebe um tempo inicial, que é o tempo de tick do clock
 * e um tempo final, executando uma subtração entre os dois tempos para obter
 * o período de relógio do sistema.
 * @param ti 
 * @param tf 
 * @return double 
 */

double clockTime ( struct timespec ti, struct timespec tf ) {
    struct timespec res;
    if ( tf.tv_nsec < ti.tv_nsec ) {
        res.tv_nsec = 1000000000 + tf.tv_nsec - ti.tv_nsec;
	    res.tv_sec = tf.tv_sec - ti.tv_sec - 1;
    } else {
	    res.tv_nsec = tf.tv_nsec - ti.tv_nsec;
	    res.tv_sec = tf.tv_sec - ti.tv_sec;
    }
    return ( double )res.tv_sec * 1000 + ( double )res.tv_nsec / 1000000;
}