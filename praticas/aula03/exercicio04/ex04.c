#include <stdio.h>

#define PI 3.14159

int main() {
    const float GRAVIDADE = 9.81; 
    float raio = 2.0;             
    float area_do_circulo = PI * raio * raio;

    printf("Área do círculo: %f\n", area_do_circulo);
    return 0;
}
