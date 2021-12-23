#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solucao(int *b, int *n, int *s, int divisao_total, int tamanho)
{
    int total = 0, i;
    for(i = 0; i< tamanho; i++){
        total += (b[i] * n[i] * s[i]);  
    }
    
    total %= divisao_total;
    
    return total;
}

int verifica_s(int n, int variavel, int mod)
{
    if( ( (n * variavel) - 1) % mod == 0) return variavel;
    
    variavel++;
    verifica_s(n,variavel,mod);
}

int verifica_n(int i, int *mod, int tamanho)
{
    int x, variavel = 1;
    for(x = 0; x < tamanho; x++){
        if(x != i) variavel *= mod[x];
    }
    
    return variavel;
}

int verifica_b(int num, int negative, int mod, int variavel)
{
    if( ( ( (num * variavel) - negative) % mod == 0) && variavel != negative) return variavel;

    variavel++;
    verifica_b(num,negative,mod,variavel);
}

void calculo(int *num, int  *negative, int *mod, int i, int *b, int *s, int *n, int tamanho)
{
    if(i < tamanho){
        b[i] = verifica_b(num[i], negative[i] ,mod[i], 1);
        // printf("b : %d\n", b[i]);
        n[i] = verifica_n(i,mod, tamanho);
        // printf("n : %d\n", n[i]);
        s[i] = verifica_s(n[i],1,mod[i]);
        // printf("s:  %d\n", s[i]);
        
        i++;
        calculo(num,negative,mod,i,b,s,n,tamanho);
    }

    else{
        int sominha = 1;
        for(i = 0; i < tamanho; i++){
            sominha *= mod[i];
        }
        
        printf("SOLUCAO: %d\n", solucao(b,n,s,sominha, tamanho));
        
        return;
    }

}

int verifica_primos(int *mod, int i, int j, int divisor, int pontos)
{
  if(divisor <= mod[i]){
    if(mod[i] % divisor == 0 && mod[j] % divisor == 0) pontos++;
    // printf("I: %d J: %d DIVISOR: %d\n", mod[i], mod[j], divisor);

    if(pontos > 0) return pontos;

    divisor++;
    verifica_primos(mod,i,j,divisor,pontos);
  }

  else return pontos;
}

bool verifica_mod(int *mod, int tamanho)
{
    int i, j, divisor, pontos;
      for(i = 0; i < tamanho;i++){
          for(j = i + 1; j < tamanho; j++){
            pontos = verifica_primos(mod,i,j,2, 0);
            // printf("I: %d J: %d pontos: %d\n",mod[i], mod[j], pontos);

              if(pontos > 0) return false; 
          }
      }

    return true;
}

void ler_array(int *num, int  *negative, int *mod, int i, int tamanho)
{
    if(i < tamanho){
        // printf("%d proposição:", i  + 1);
        scanf("%d", &num[i]);
        scanf("%d", &negative[i]);
        scanf("%d", &mod[i]);

        i++;
        ler_array(num, negative, mod, i, tamanho);
    }
}

int main(void)
{
    int tamanho;
    // printf("Digite as n proposicoes:");
    scanf("%d", &tamanho);
    int num[tamanho], negative[tamanho], mod[tamanho], b[tamanho], s[tamanho], n[tamanho];

    ler_array(num,negative,mod, 0, tamanho);
    if( verifica_mod(mod, tamanho) == true){
    //   printf("funciona!\n");
      calculo(num,negative,mod, 0, b,s,n, tamanho);
    } 
    else printf("Nao sao coprimos!");
    
    // calculos(num,negative,divisor, 0, b,s,n);


}