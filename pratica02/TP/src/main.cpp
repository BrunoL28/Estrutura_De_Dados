#include "../include/fatorial.hpp"
#include "../include/fibonacci.hpp"
#include "../include/tempo.hpp"
#include "../include/msgassert.hpp"
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

    struct timespec ti, tf;
    parse_args( argc, argv );
    int resFatRecursivo, resFibRecursivo, resFatIterativo, resFibIterativo;
    double clockFatR, clockFatI, clockFibR, clockFibI;
    double startTimeFatR, startTimeFatI, startTimeFibR, startTimeFibI, endTimeFatR, endTimeFatI, endTimeFibR, endTimeFibI;
    double timeSystemFatR, timeSystemFatI, timeSystemFibR, timeSystemFibI, timeUserFatR, timeUserFatI, timeUserFibR, timeUserFibI;

    switch ( opcaoEscolhida ) {

        case EXEC_FATORIAL :

            std::cout << std::endl << "Fatorial Recursivo" << std::endl;

            clock_gettime( CLOCK_MONOTONIC, &ti );

            startTimeFatR = systemTime();
            resFatRecursivo = fatorialRecursivo( numeroEscolhido );
            endTimeFatR = systemTime();
            timeSystemFatR = endTimeFatR - startTimeFatR;

            startTimeFatR = userTime();
            resFatRecursivo = fatorialRecursivo( numeroEscolhido );
            endTimeFatR = userTime();
            timeUserFatR = endTimeFatR - startTimeFatR;

            clock_gettime( CLOCK_MONOTONIC, &tf );

            clockFatR = clockTime( ti, tf );

            std::cout << std::endl << "Fatorial, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFatRecursivo << std::endl;

            std::cout << std::endl << "Dados do fatorial recursivo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario: " << timeUserFatR << std::endl;
            std::cout << std::endl << "Tempo de sistema: " << timeSystemFatR << std::endl;
            std::cout << std::endl << "Tempo de relogio: " << clockFatR << std::endl;

            std::cout << std::endl << "Fatorial Iterativo" << std::endl;

            clock_gettime( CLOCK_MONOTONIC, &ti );

            startTimeFatI = systemTime();
            resFatIterativo = fatorialIterativo( numeroEscolhido );
            endTimeFatI = systemTime();
            timeSystemFatI = endTimeFatI - startTimeFatI;

            startTimeFatI = userTime();
            resFatIterativo = fatorialIterativo( numeroEscolhido );
            endTimeFatI = userTime();
            timeUserFatI = endTimeFatI - startTimeFatI;

            clock_gettime( CLOCK_MONOTONIC, &tf );

            clockFatI = clockTime( ti, tf );

            std::cout << std::endl << "Fatorial, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFatIterativo << std::endl;

            std::cout << std::endl << "Dados do fatorial iterativo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario: " << timeUserFatI << std::endl;
            std::cout << std::endl << "Tempo de sistema: " << timeSystemFatI << std::endl;
            std::cout << std::endl << "Tempo de relogio: " << clockFatI << std::endl;

            break;

        case EXEC_FIBONACCI :

                std::cout << std::endl << "Fibonacci Recursivo" << std::endl;

                clock_gettime( CLOCK_MONOTONIC, &ti );

                startTimeFibR = systemTime();
                resFibRecursivo = fibonacciRecursivo( numeroEscolhido );
                endTimeFibR = systemTime();
                timeSystemFibR = endTimeFibR - startTimeFibR;

                startTimeFibR = userTime();
                resFibRecursivo = fibonacciRecursivo( numeroEscolhido );
                endTimeFibR = userTime();
                timeUserFibR = endTimeFibR - startTimeFibR;

                clock_gettime( CLOCK_MONOTONIC, &tf );

                clockFibR = clockTime( ti, tf );

                std::cout << std::endl << "Fibonacci, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFibRecursivo << std::endl;

                std::cout << std::endl << "Dados do fibonacci recursivo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario: " << timeUserFibR << std::endl;
                std::cout << std::endl << "Tempo de sistema: " << timeSystemFibR << std::endl;
                std::cout << std::endl << "Tempo de relogio: " << clockFibR << std::endl;

                std::cout << std::endl << "Fibonacci Iterativo" << std::endl;

                clock_gettime( CLOCK_MONOTONIC, &ti );

                startTimeFibI = systemTime();
                resFibIterativo = fibonacciIterativo( numeroEscolhido );
                endTimeFibI = systemTime();
                timeSystemFibI = endTimeFibI - startTimeFibI;

                startTimeFibI = userTime();
                resFibIterativo = fibonacciIterativo( numeroEscolhido );
                endTimeFibI = userTime();
                timeUserFibI = endTimeFibI - startTimeFibI;

                clock_gettime( CLOCK_MONOTONIC, &tf );


                clockFibI = clockTime( ti, tf );
                
                std::cout << std::endl << "Fibonacci, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFibIterativo << std::endl;

                std::cout << std::endl << "Dados do fibonacci iterativo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario: " << timeUserFibI << std::endl;
                std::cout << std::endl << "Tempo de sistema: " << timeSystemFibI << std::endl;
                std::cout << std::endl << "Tempo de relogio: " << clockFibI << std::endl;

                break;

        default:
            break;
    }

    return 0;

}
