#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesjogo.h"
#include "funcoesbombas.h"

int inicializa_jogo(Jogo *jogo){

  int explodiu = 0;
  int coluna = 0;
  int posicao, posicao2 = 0;

  while(jogo->abertos < jogo->tamanho - jogo->bombas && explodiu == 0){
        
    printf("\n\t\t\tCampo Minado\n");
  
    printf("\t\t     0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
  
    for(int i = 0; i < jogo->tamanho; i++){

      if (coluna % 8 == 0 && (coluna / 8) < 10)
        printf("\t\t%d  | ", (coluna / 8));
      else if (coluna % 8 == 0 && (coluna / 8) >= 10)
          printf("\t\t%d | ", (coluna / 8));

      if(jogo->tabuleiro[i].aberto == 0)
        printf("* | ");
      else if(jogo->tabuleiro[i].aberto == 1)
        printf("%d | ", jogo->tabuleiro[i].numero);
      
      coluna++;

      if (coluna % 8 == 0 && coluna != 0)
            printf("\n");
          
    }
  
    printf("\n\tDigite a linha e a coluna que deseja abrir:\n");

    posicao = 0;
    posicao2 = 0;
  
    scanf("%d %d", &posicao, &posicao2);

    posicao = posicao * 8 + posicao2;
  
    if(jogo->tabuleiro[posicao].bomba == 1){
      explodiu = 1;
      printf("\n\tVocê perdeu!\n");
      return 0;
    } else {
        jogo->tabuleiro[posicao].aberto = 1;
        jogo->abertos++;
      }

    jogo = encontra_similares(jogo, posicao);

    coluna = 0;

  }

  printf("Você venceu!\n");

  return 1;
}

Jogo *cria_jogo(Jogo *jogo, int dificuldade, int num_bombas, int vizinho, int tamanho){

  jogo->dificuldade = dificuldade;
  jogo->tamanho = tamanho;
  jogo->bombas = num_bombas;
  jogo->abertos = 0;
  jogo->tabuleiro = (Celula *)malloc(tamanho * sizeof(Celula));

  if(jogo->tabuleiro == NULL){
    printf("\tErro na alocação de memória\n");
    return NULL;
  }

  for(int i = 0; i < tamanho; i++){
    jogo->tabuleiro[i].bomba = 0;
    jogo->tabuleiro[i].aberto = 0;
    jogo->tabuleiro[i].numero = 0;
  }

  jogo = insere_bombas(jogo, vizinho);

  return jogo;

}

Jogo *libera_jogo (Jogo *jogo){

  free(jogo->tabuleiro);
  free(jogo);

  return NULL;

}