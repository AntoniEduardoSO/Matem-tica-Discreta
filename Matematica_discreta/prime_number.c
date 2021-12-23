#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 2019990

int main(void)
{
    int num[N],i, limite = sqrt(N), j, contador = 1;
    double tempo, t_i, t_f;

    t_i = time(NULL);
    for(i = 0; i < N; i++)
        num[i] = i + 1;

    for(i = 1; i<= limite; i++){
        if(num[i] != 0){
            for(j = pow(num[i],2); j <= N; j += num[i])
                num[j - 1] = 0;
        }
    }

    for(i = 0; i < N; i++)
        if(num[i] != 0){
          printf("%d\t Quantidade: %d\n", num[i], contador);
          contador++;
        }

    t_f = time(NULL);
    tempo = difftime(t_f,t_i);
    printf("Tempo: %.2lf(s)", (tempo));
    
}