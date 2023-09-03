#include "../include/fatorial.hpp"
#include "../include/fibonacci.hpp"
#include "../include/tempo.hpp"
#include "../include/msgassert.hpp"
#include "../include/utils.hpp"
#include <getopt.h>

static int opcaoEscolhida;
int numeroEscolhido;

void uso() {
    std::cerr << "main" << std::endl;
    std::cerr << "\t-f \t(executar fatorial)" << std::endl;
    std::cerr << "\t-b \t(executar fibonacci)" << std::endl;
    std::cerr << "\t-n \t(escolher um numero)" << std::endl;
    std::cerr << "\t-h \t(solicitar ajuda)" << std::endl;
}

void parse_args( int argc, char **argv ) {
    numeroEscolhido = -1; //flag para erros
    opcaoEscolhida = -1; //flag para erros
    int c; //variável auxiliar

    while( ( c = getopt( argc, argv, "fbn:h") ) != EOF ) {
        switch ( c ) {

            case 'f' :
                avisoAssert( opcaoEscolhida == -1, "Mais de uma operacao escolhida." );
                opcaoEscolhida = EXEC_FATORIAL;
                break;

            case 'b' :
                avisoAssert( opcaoEscolhida == -1, "Mais de uma operacao escolhida." );
                opcaoEscolhida = EXEC_FIBONACCI;
                break;

            case 'n' :
                if ( optarg != NULL ) {
                    numeroEscolhido = atoi( optarg );
                }
                break;

            case 'h' :
                std::cout << std::endl << "Precisa de Ajuda?" << std::endl;
                std::cout << "Segue uma descricao das opcoes que voce pode escolher para executar o codigo" << std::endl;
                std::cout << "-f => Executa as funcoes relacionadas ao fatorial." << std::endl;
                std::cout << "-b => Executa as funcoes relacionadas ao fibonacci." << std::endl;
                std::cout << "-n => Escolhe um numero para exectar as operacoes." << std::endl;
                break;

            default:
                std::cerr << "A opcao: " << optopt << "eh invalida ou ausente." << std::endl;
                break;
        }
    }
}

int main ( int argc, char **argv ) {

    struct rusage start, end;
    struct timespec ti, tf;
    parse_args( argc, argv );
    int resFatRecursivo, resFibRecursivo, resFatIterativo, resFibIterativo;
    double clockFatR, clockFatI, clockFibR, clockFibI;

    switch ( opcaoEscolhida ) {

        case EXEC_FATORIAL :

            std::cout << std::endl << "Fatorial Recursivo" << std::endl;

            clock_gettime( CLOCK_MONOTONIC, &ti );
            getrusage( RUSAGE_SELF, &start );
            resFatRecursivo = fatorialRecursivo( numeroEscolhido );
            clock_gettime( CLOCK_MONOTONIC, &tf );
            getrusage( RUSAGE_SELF, &end );

            clockFatR = clockTime( ti, tf );

            std::cout << std::endl << "Fatorial, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFatRecursivo << std::endl;

            std::cout << std::endl << "Dados do fatorial recursivo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario: " << formatValue( userTime( &start, &end ), 7 ) << std::endl;
            std::cout << std::endl << "Tempo de sistema: " << formatValue( systemTime( &start, &end ), 7 ) << std::endl;
            std::cout << std::endl << "Tempo de relogio: " << formatValue( clockFatR, 7 ) << std::endl;

            std::cout << std::endl << "Fatorial Iterativo" << std::endl;

            clock_gettime( CLOCK_MONOTONIC, &ti );
            getrusage( RUSAGE_SELF, &start );
            resFatIterativo = fatorialIterativo( numeroEscolhido );
            clock_gettime( CLOCK_MONOTONIC, &tf );
            getrusage( RUSAGE_SELF, &end );

            clockFatI = clockTime( ti, tf );

            std::cout << std::endl << "Fatorial, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFatIterativo << std::endl;

            std::cout << std::endl << "Dados do fatorial iterativo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario: " << formatValue( userTime( &start, &end ), 7 ) << std::endl;
            std::cout << std::endl << "Tempo de sistema: " << formatValue( systemTime( &start, &end ), 7 ) << std::endl;
            std::cout << std::endl << "Tempo de relogio: " << formatValue( clockFatI, 7 ) << std::endl;

            break;

        case EXEC_FIBONACCI :

                std::cout << std::endl << "Fibonacci Recursivo" << std::endl;

                clock_gettime( CLOCK_MONOTONIC, &ti );
                getrusage( RUSAGE_SELF, &start );
                resFibRecursivo = fibonacciRecursivo( numeroEscolhido );
                clock_gettime( CLOCK_MONOTONIC, &tf );
                getrusage( RUSAGE_SELF, &end );

                clockFibR = clockTime( ti, tf );

                std::cout << std::endl << "Fibonacci, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFibRecursivo << std::endl;

                std::cout << std::endl << "Dados do fibonacci recursivo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario: " << formatValue( userTime( &start, &end ), 7 ) << std::endl;
                std::cout << std::endl << "Tempo de sistema: " << formatValue( systemTime( &start, &end ), 7 ) << std::endl;
                std::cout << std::endl << "Tempo de relogio: " << formatValue( clockFibR, 7 ) << std::endl;

                std::cout << std::endl << "Fibonacci Iterativo" << std::endl;

                clock_gettime( CLOCK_MONOTONIC, &ti );
                getrusage( RUSAGE_SELF, &start );
                resFibIterativo = fibonacciIterativo( numeroEscolhido );
                clock_gettime( CLOCK_MONOTONIC, &tf );
                getrusage( RUSAGE_SELF, &end );

                clockFibI = clockTime( ti, tf );
                
                std::cout << std::endl << "Fibonacci, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFibIterativo << std::endl;

                std::cout << std::endl << "Dados do fibonacci iterativo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario: " << formatValue( userTime( &start, &end ), 7 ) << std::endl;
                std::cout << std::endl << "Tempo de sistema: " << formatValue( systemTime( &start, &end ), 7 ) << std::endl;
                std::cout << std::endl << "Tempo de relogio: " << formatValue( clockFibI, 7 ) << std::endl;

                break;

        default:
            break;
    }

    return 0;

}