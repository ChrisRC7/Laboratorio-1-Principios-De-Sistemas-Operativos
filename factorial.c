#include <stdio.h>
#include <time.h>

volatile long long sink;

long long factorial(long n){
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main(){
    int num;

    clock_t inicio, fin;
    double tiempo;

    printf("Ingrese un número para calcular su factorial: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Error: entrada inválida\n");
        return 1;
    }

    inicio = clock();
        
    sink = factorial(num);

    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    //printf("El factorial de %d es: %lld\n", num, resultado);
    printf("Tiempo: %f\n", tiempo);
    
    return 0;
}