#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesjogo.h"
#include "funcoesbombas.h"


int main(){

  printf("\n\t\t\tBem vindo ao Campo Minado!\n");

  printf("\t\tAntes de iniciarmos o jogo, selecione a dificuldade:\n");

  int option;

  printf("\t1 - Fácil\n");
  printf("\t2 - Médio\n");
  printf("\t3 - Difícil\n");

  scanf("%d", &option);

  Jogo *jogo = (Jogo *)malloc(sizeof(Jogo));

  if (jogo == NULL){
    printf("\tErro na alocação de memória\n");
    return 0;
  }


  switch(option){
    case 1:
      printf("\tVocê selecionou a dificuldade Fácil\n");
      jogo = cria_jogo(jogo, 1, BOMB_FACIL, VIZINHO_FACIL, TAM_FACIL);
      inicializa_jogo(jogo);
      libera_jogo(jogo);
      break;
    case 2:
      printf("\tVocê selecionou a dificuldade Médio\n");
      jogo = cria_jogo(jogo, 2, BOMB_MEDIO, VIZINHO_MEDIO, TAM_MEDIO);
      inicializa_jogo(jogo);
      jogo = libera_jogo(jogo);
      break;
    case 3:
      printf("\tVocê selecionou a dificuldade Difícil\n");
      jogo = cria_jogo(jogo, 3, BOMB_DIFICIL, VIZINHO_DIFICIL, TAM_DIFICIL);
      inicializa_jogo(jogo);
      jogo = libera_jogo(jogo);
      break;
    default:
      printf("\tOpção inválida\n");
      break;
  }

  return 0;

}


