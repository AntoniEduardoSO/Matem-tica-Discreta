#include <stdio.h>

void decompor(int num, int divisor)
{
    if(num  != 1){
        if(num % divisor == 0){
            printf("%d\n", divisor);
            num/= divisor;
            divisor = 2;
        }

        else divisor++;

        decompor(num,divisor);
    }
}


int main(void)
{
    int num;
    scanf("%d", &num);

    decompor(num,2);
}