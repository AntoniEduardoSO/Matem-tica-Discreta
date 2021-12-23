#include <stdio.h>

int achar_t( int a, int mod, int s, int variavel, int euclides)
{
    if(mod > euclides){
        if( ( (a * s) + (mod * variavel) ) == euclides ) return variavel;

        variavel--;
        achar_t(a,mod,s,variavel,euclides);
    }

    else{
        if( ( (a * s) + (mod * variavel) ) == euclides ) return variavel;

        variavel++;
        achar_t(a,mod,s,variavel,euclides);
    }
}

int mdc(int a, int b)
{
  if(b == 0) return a;
  mdc(b, a%b);
}

int achar_invertido(int a, int b, int variavel)
{
        if(  ( ( ( (a * variavel ) -1  ) ) % b == 0) && variavel != 0) return variavel;
        
        else if(a % 2 == 0 && b % 2 == 0){
            printf("Impossivel achar o inverso desses dois numeros");
            return 0;
        }
        
        
        variavel++;
        achar_invertido(a,b,variavel);
}

int main(void)
{
    int a, b, m, s, e, t;
    
    scanf("%d %d %d", &a, &b, &m);
    
    s = achar_invertido(a,m,1);
    if(s != 0)
    {
        e = mdc(m,a);
        t = achar_t(a,m,s,0,e);
        (t < 0) ?  printf("MDC(A,B): %d = (%d * %d) + (%d * %d)", e, a , s, m, t) : printf("MDC(A,B): %d = (%d * %d) + (%d * %d)", e, a , s, m, t);
    }
}