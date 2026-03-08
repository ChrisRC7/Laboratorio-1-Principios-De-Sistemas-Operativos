#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long factorial(long n){
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main(long argc, char *argv[]){
    struct rlimit rl;
    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        rl.rlim_cur = rl.rlim_max;  // subir soft limit al máximo permitido
        setrlimit(RLIMIT_STACK, &rl);
    }

    if(argc != 2){
        printf("Uso: ./factorial numero\n");
        return 1;
    }

    long num = atol(argv[1]);

    clock_t inicio = clock();

    long resultado = factorial(num);

    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    //printf("Factorial: %ld\n", resultado);
    printf("Tiempo: %f\n", tiempo);

    return 0;
}