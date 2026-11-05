#include <stdio.h>
// variável global
int contador = 10; 

int main() {
    // variável local
    int contador = 5; 
    printf("Valor de contador dentro do main: %d\n", contador);
    return 0;
}
