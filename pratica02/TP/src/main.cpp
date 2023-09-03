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

            default:
                std::cerr << "A opcao: " << optopt << "eh invalida ou ausente." << std::endl;
                break;
        }
    }
}

int main ( int argc, char **argv ) {

    struct rusage start, end;
    parse_args( argc, argv );
    int resFatRecursivo, resFibRecursivo, resFatIterativo, resFibIterativo;

    switch ( opcaoEscolhida ) {

        case EXEC_FATORIAL :

            getrusage( RUSAGE_SELF, &start );
            std::cout << std::endl << "Fatorial Recursivo" << std::endl;
            resFatRecursivo = fatorialRecursivo( numeroEscolhido );
            std::cout << std::endl << "Fatorial, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFatRecursivo << std::endl;
            getrusage( RUSAGE_SELF, &end );

            std::cout << std::endl << "Dados do fatorial recursivo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario, em segundos: " << userTime( &start, &end ) << std::endl;
            std::cout << std::endl << "Tempo de sistema, em segundos: " << systemTime( &start, &end ) << std::endl;

            getrusage( RUSAGE_SELF, &start );
            std::cout << std::endl << "Fatorial Iterativo" << std::endl;
            resFatIterativo = fatorialIterativo( numeroEscolhido );
            std::cout << std::endl << "Fatorial, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFatIterativo << std::endl;
            getrusage( RUSAGE_SELF, &end );

            std::cout << std::endl << "Dados do fatorial iterativo: " << std::endl;
            std::cout << std::endl << "Tempo de usuario, em segundos: " << userTime( &start, &end ) << std::endl;
            std::cout << std::endl << "Tempo de sistema, em segundos: " << systemTime( &start, &end ) << std::endl;
            break;

        case EXEC_FIBONACCI :

                getrusage( RUSAGE_SELF, &start );
                std::cout << std::endl << "Fibonacci Recursivo" << std::endl;
                resFibRecursivo = fibonacciRecursivo( numeroEscolhido );
                std::cout << std::endl << "Fibonacci, calculado de forma recursiva, de: " << numeroEscolhido << " eh: " << resFibRecursivo << std::endl;
                getrusage( RUSAGE_SELF, &end );

                std::cout << std::endl << "Dados do fibonacci recursivo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario, em segundos: " << userTime( &start, &end ) << std::endl;
                std::cout << std::endl << "Tempo de sistema, em segundos: " << systemTime( &start, &end ) << std::endl;

                getrusage( RUSAGE_SELF, &start );
                std::cout << std::endl << "Fibonacci Iterativo" << std::endl;
                resFibIterativo = fibonacciIterativo( numeroEscolhido );
                std::cout << std::endl << "Fibonacci, calculado de forma iterativa, de: " << numeroEscolhido << " eh: " << resFibIterativo << std::endl;
                getrusage( RUSAGE_SELF, &end );

                std::cout << std::endl << "Dados do fibonacci iterativo: " << std::endl;
                std::cout << std::endl << "Tempo de usuario, em segundos: " << userTime( &start, &end ) << std::endl;
                std::cout << std::endl << "Tempo de sistema, em segundos: " << systemTime( &start, &end ) << std::endl;
                break;
        default:
            break;
    }

    return 0;

}