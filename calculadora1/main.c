/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float numero1;
    float numero2;
    char operador;
    float resultado;
    
    printf("---Calduladora---\n");
    printf("\nDigite dois numeros\n");
    scanf("%f %f", &numero1, &numero2);
    printf("\nSeus numeros sao respectivamente %f, %f\n", numero1, numero2);
    printf("\nDigite um operador\n");
    scanf(" %c", &operador);
    if (operador == '+') 
    {
        resultado = numero1 + numero2;
        printf("\nO resultado da soma e :%f", resultado);
    }
    
    if (operador == '-')
    {
        resultado = numero1 - numero2;
        printf("\nO resultado da subtracao e :%f", resultado);
    }
    
    if (operador == '*')
    {
        resultado = numero1 * numero2;
        printf("\nO resultado da sua multiplicacao e: %f", resultado);
    }
    
    if (operador == '/')
    {
        resultado = numero1 / numero2;
        printf("\nO resultado da sua divisao e: %f", resultado);
    }
    
    return 0;
}
