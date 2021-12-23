#include <stdio.h>

int mdc(int a, int b)
{
  if(b == 0) return printf("%d\n",a);
  mdc(b, a%b);
}

void entradas()
{
  int x,y;

  if(scanf("%d %d", &x, &y) != EOF){
    printf("MDC(%d,%d) = ", x, y);
    mdc(y,x);
    entradas();
  }

  return;
}

int main(void)
{
 entradas();
}
