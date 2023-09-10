#include <stdlib.h>
#include <stdio.h>

int main(void) {    
    int *p;
    int i = 0;
    p = malloc(128);
    while( i < 32 ) {    //como cada int ocupa 4 bytes, alocando 128, 32 iterações é o máximo que faço
        printf("%ld\n", (long)p);
        i++;
    }
    free( p );
    return (0);
}