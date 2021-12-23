#include <stdio.h>

int mmc(int num1, int num2, int divisor, int total)
{
  if(num1 > 1 ||  num2 > 1){
    if(num1 % divisor == 0 && num2 % divisor == 0){
      num1 /= divisor;
      num2 /= divisor;
      total *= divisor;
      printf("numero 1: (%d) | numero 2: (%d) | MMC: (%d)\n",num1,num2, divisor);
      divisor = 2;
    }

    else if(num1 % divisor == 0){
      num1 /= divisor;
      total *= divisor;
      printf("numero 1: (%d) | numero 2: (%d) | MMC: (%d)\n",num1,num2, divisor);
      divisor = 2;
    }

    else if(num2 % divisor == 0){
      num2 /= divisor;
      total *= divisor;
      printf("numero 1: (%d) | numero 2: (%d) | MMC: (%d)\n",num1,num2, divisor);
      divisor = 2;
    }

    else divisor++;

    mmc(num1,num2,divisor,total);
  }

  else return printf("Total [MMC]: (%d)\n", total);
}

int mdc(int num1, int num2, int divisor, int total)
{
  if(num1 != 1 && num2 != 1){
      if(num1 % divisor == 0 && num2 % divisor == 0){
           num1/=divisor;
          num2/=divisor;
          total *= divisor;
          printf("numero 1: (%d) | numero 2: (%d) | MDC: (%d)\n",num1,num2, divisor);
          divisor  = 2;
      }

      else{
          if(num1 % divisor == 0){
              num1 /= divisor;
              divisor = 2;
          }
            
          else if(num2 % divisor == 0){
               num2/= divisor;
              divisor = 2;
           }

          else divisor++;
      }

      mdc(num1,num2,divisor,total);
  }

  else return printf("Total [MDC]: (%d)\n", total);
}

int main(void)
{
  int num1, num2;
  scanf("%d%d", &num1, &num2);

  mdc(num1,num2,2,1);
  printf("--------------------------------- [xxx] -------------\n");

  mmc(num1,num2,2,1);
}