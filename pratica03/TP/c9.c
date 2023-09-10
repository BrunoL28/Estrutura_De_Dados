#include <stdlib.h>

void f(void) {

    int* x = malloc(10 * sizeof(int));   //[] [] [] [] [] [] [] [] [] []
    x[10] = 0;                           //0  1  2  3  4  5  6  7  8  9

}

int main(void) {

    f();
    return 0;

}


