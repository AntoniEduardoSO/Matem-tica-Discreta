#include <stdio.h>

int achar_invertido(int a, int b, int variavel)
{
        if(  ( ( ( (a * variavel ) -1  ) ) % b == 0) && variavel != 0) return variavel;
        
        
        variavel++;
        achar_invertido(a,b,variavel);
}

int main(void)
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("Solucao do inverso modular positivo: ");
    
    printf("%d", achar_invertido(a,b,1) );
}