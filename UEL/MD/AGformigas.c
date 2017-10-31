#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int valorPorPeso[400], qtd, k, m, M;

struct obj {
  int valor;
  int peso;
  float ferormonio;
  int logic;
};
struct obj objeto[400];

struct best {
  int valorT;
  int pesoT;
  int select[400];
};
struct best melhor[400];

void formigas(int iterate){
  int w, c, i, it, melhorValor; i=0;
  // ag de seleçao
  for(int it=1; it<=iterate; it++){
    srand(time(NULL));
    c=0;
    while(c < 10){
       melhor[c].select[i] = objeto[i].ferormonio * (rand()%10);
       if(melhor[c].select[i] >= 1){
         while(melhor[c].pesoT + objeto[i].peso <= M){
           melhor[c].pesoT += objeto[i].peso;
           melhor[c].valorT += objeto[i].valor;
           melhor[c].select[i] = objeto[i].valor;
           i++; if(i > qtd){ break; }
         }
       }
       if(melhor[c].valorT > melhorValor){
         melhorValor = melhor[c].valorT;
         m = c;
         w = i;
      }
     c++;
    }
  // atualizaçao do ferormonio - +0,1 / -0,1
  k=0;
  for(i=0;i<10;k++){
    if(melhor[m].select[i] == objeto[k].valor){
      objeto[k].ferormonio += 0.1;
      objeto[k].logic=1;
    }
      if (k==qtd) {
        i++;
        k=0;
      }
  }

  for(k=0;k<qtd;k++){
    if(objeto[k].logic==0){
      objeto[k].ferormonio -= 0.1;
    }
  }
}

// resposta
for(i=0;i<=w;i++){
  printf("%d ",melhor[m].select[i]);
}

printf("melhor valor = %d\n",melhorValor);
printf("peso = %d\n",melhor[m].pesoT);
}

void main(){
    int soma,i,iterate; soma=0;
    printf("capacidade da mochila: ");
    scanf("%d", &M);
    printf("qtd de objetos:");
    scanf("%d", &qtd);

    printf("peso e interesse do objeto:\n");
  for(i=0;i<qtd;i++){
    scanf("%d %d", &objeto[i].peso, &objeto[i].valor);
    objeto[i].ferormonio = 1;
  }
  printf("qtd de iterate = ");
  scanf("%d", &iterate);

  formigas(iterate);
}

// Como o código funciona?
/*
  - O usuário entra com os valores da capacidade M da mochila, com a quantidade Q de itens, os respectivos pesos e valores dos objetos
  a serem avaliados pelo algoritmo e, por fim, a quantidade de iterações que o código deve realizar a fim de determinar a configuração
  ideal dos objetos a serem colocados dentro da mochila.
  - Inicialmente, todos os itens a serem avaliados recebem o valor fixo de 1 para a quantidade de feromônio. Uma quantidade padrão de
  10 formigas é utilizado e cada uma das formigas pega um dos itens I de forma aleatória. Cada formiga, então, coloca um item I dentro
  da mochila até que uma das seguintes condições aconteça: o espaço M da mochila seja menor que o peso P. Assim que todas as formigas
  realizam esse mesmo processo, para cada formiga, é realizada uma iteração para identificar qual foi o item que mais adicionou valor.
  Assim que esse item for encontrado, o valor de F será incrementado em 0.1. Então, todos os itens, com exceção daqueles cujos valores
  de F foram aumentados em 0.1, sofrerão uma redução de 0.1 em F. Isso garante que a formiga, após várias iterações, seja sempre capaz
  de escolher os melhores itens para colocar na mochila.
*/
// Dificuldades encontradas
/*
  - (aqui você escreve, porque eu não lembro os rolos que deram)
*/
