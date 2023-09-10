#include <stdlib.h>

void f(void) {

    int* x = malloc(11 * sizeof(int));   //[] [] [] [] [] [] [] [] [] []
    x[10] = 0;                           //0  1  2  3  4  5  6  7  8  9
    free( x );

}

int main(void) {

    f();
    return 0;

}