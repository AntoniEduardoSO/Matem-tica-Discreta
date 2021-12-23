#include <stdio.h>

int achar_x(int a, int b , int m , int x)
{
    if( ( ( (a * x) - b ) % m != 0) && x != 0){
        x++;
        achar_x(a,b,m,x);
    }

    return x;
}


int main(void)
{
    int a, x, b, m;

    scanf("%d %d %d ", &a, &b, &m);

   printf("%d", achar_x(a,b,m,x) );

   return 0;
}