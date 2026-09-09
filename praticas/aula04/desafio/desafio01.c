#include <stdio.h>

int main() {
    int x = 5 / 2;     
    int y = x++;       
    int z = x % 2;    

    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
