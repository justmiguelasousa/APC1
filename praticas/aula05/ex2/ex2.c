#include <stdio.h>

int main() { 
    char str[31];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    printf("A string lida foi: %s", str);
    return 0;
}