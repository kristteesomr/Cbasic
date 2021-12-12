#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define E 2.71828
int main(int argc, char* argv[]){
    
    if (argc != 3){
        printf("Wrong number of arguments!\n");
        return 1;
    }

    float a;
    int a2;

    a2 = atoi(argv[2]);
    a = pow(E,a2);
    printf("%f",a);
}