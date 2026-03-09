import time
import sys
sys.setrecursionlimit(10**9)
#sys.set_int_max_str_digits(1000000000)

def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n-1)

input_str = input("Ingrese un número para calcular su factorial: ")
num = int(input_str)

inicio = time.time()
resultado = factorial(num)
fin = time.time()

#print("Factorial:", resultado)
print("Tiempo:", fin - inicio)