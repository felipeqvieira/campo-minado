#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesjogo.h"

int valida_x(int x, int tam){

  if (x >= 0 && x < tam)
    return 1;
  
  return 0;
}

Jogo* conta_bombas(Jogo *jogo, int VIZINHO){

  for(int i = 0; i < jogo->tamanho; i++){

    if(jogo->tabuleiro[i].bomba != 1){

      if(valida_x(i - 1, jogo->tamanho) && jogo->tabuleiro[i - 1].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i + 1, jogo->tamanho) && jogo->tabuleiro[i + 1].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i - (VIZINHO - 1), jogo->tamanho) && jogo->tabuleiro[i - (VIZINHO - 1)].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i + (VIZINHO - 1), jogo->tamanho) && jogo->tabuleiro[i + (VIZINHO - 1)].bomba == 1)
        jogo->tabuleiro[i].numero++;
      
      if(valida_x(i - (VIZINHO - 2), jogo->tamanho) && jogo->tabuleiro[i - (VIZINHO - 2)].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i + (VIZINHO - 2), jogo->tamanho) && jogo->tabuleiro[i + (VIZINHO - 2)].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i - VIZINHO, jogo->tamanho) && jogo->tabuleiro[i - VIZINHO].bomba == 1)
        jogo->tabuleiro[i].numero++;

      if(valida_x(i + VIZINHO, jogo->tamanho) && jogo->tabuleiro[i + VIZINHO].bomba == 1)
        jogo->tabuleiro[i].numero++;

    }
  }

  return jogo;

}

Jogo* insere_bombas (Jogo *jogo, int vizinho){

  srand(time(NULL));

  int numberi = 0;

  for(int bombas = 0; bombas < jogo->bombas; bombas++){

    numberi = rand() % jogo->tamanho;
  
    while(jogo->tabuleiro[numberi].bomba == 1){
      numberi = rand() % jogo->tamanho;
    }

    jogo->tabuleiro[numberi].bomba = 1;

  }

  jogo = conta_bombas(jogo, vizinho);

  return jogo;
}


Jogo* encontra_similares(Jogo *jogo, int posicao){

  if(valida_x(posicao + (VIZINHO_FACIL - 1), jogo->tamanho) && jogo->tabuleiro[posicao + (VIZINHO_FACIL - 1)].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + (VIZINHO_FACIL - 1)].aberto == 0){

    jogo->tabuleiro[posicao + (VIZINHO_FACIL - 1)].aberto = 1;
    jogo->abertos++;
    jogo = encontra_similares(jogo, posicao + (VIZINHO_FACIL - 1));
      
  }

  if(valida_x(posicao - (VIZINHO_FACIL - 1), jogo->tamanho) && jogo->tabuleiro[posicao - (VIZINHO_FACIL - 1)].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - (VIZINHO_FACIL - 1)].aberto == 0){

    jogo->tabuleiro[posicao - (VIZINHO_FACIL - 1)].aberto = 1;
    jogo->abertos++;
    jogo = encontra_similares(jogo, posicao - (VIZINHO_FACIL - 1));
      
  }

  if(posicao % 8 == 0){

    if(valida_x(posicao + 1, jogo->tamanho) && jogo->tabuleiro[posicao + 1].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + 1].aberto == 0){

      jogo->tabuleiro[posicao + 1].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao + 1);
        
    }

    if(valida_x(posicao + VIZINHO_FACIL, jogo->tamanho) && jogo->tabuleiro[posicao + VIZINHO_FACIL].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + VIZINHO_FACIL].aberto == 0){

      jogo->tabuleiro[posicao + VIZINHO_FACIL].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao + VIZINHO_FACIL);
      
    }

  } else if ((posicao + 1) % 8 == 0){

    if(valida_x(posicao - 1, jogo->tamanho) && jogo->tabuleiro[posicao - 1].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - 1].aberto == 0){

      jogo->tabuleiro[posicao - 1].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao - 1);
        
    }

    if(valida_x(posicao - VIZINHO_FACIL, jogo->tamanho) && jogo->tabuleiro[posicao - VIZINHO_FACIL].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - VIZINHO_FACIL].aberto == 0){

      jogo->tabuleiro[posicao - VIZINHO_FACIL].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao - VIZINHO_FACIL);

    }

  } else {

    if(valida_x(posicao + 1, jogo->tamanho) && jogo->tabuleiro[posicao + 1].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + 1].aberto == 0){

      jogo->tabuleiro[posicao + 1].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao + 1);
        
    }

    if(valida_x(posicao - 1, jogo->tamanho) && jogo->tabuleiro[posicao - 1].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - 1].aberto == 0){

      jogo->tabuleiro[posicao - 1].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao - 1);
        
    }

    if(valida_x(posicao - (VIZINHO_FACIL - 2), jogo->tamanho) && jogo->tabuleiro[posicao - (VIZINHO_FACIL - 2)].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - (VIZINHO_FACIL - 2)].aberto == 0){

      jogo->tabuleiro[posicao - (VIZINHO_FACIL - 2)].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao - (VIZINHO_FACIL - 2));
        
    }

    if(valida_x(posicao + (VIZINHO_FACIL - 2), jogo->tamanho) && jogo->tabuleiro[posicao + (VIZINHO_FACIL - 2)].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + (VIZINHO_FACIL - 2)].aberto == 0){

      jogo->tabuleiro[posicao + (VIZINHO_FACIL - 2)].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao + (VIZINHO_FACIL - 2));
        
    }

    if(valida_x(posicao - VIZINHO_FACIL, jogo->tamanho) && jogo->tabuleiro[posicao - VIZINHO_FACIL].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao - VIZINHO_FACIL].aberto == 0){

      jogo->tabuleiro[posicao - VIZINHO_FACIL].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao - VIZINHO_FACIL);

    }

    if(valida_x(posicao + VIZINHO_FACIL, jogo->tamanho) && jogo->tabuleiro[posicao + VIZINHO_FACIL].numero == jogo->tabuleiro[posicao].numero && jogo->tabuleiro[posicao + VIZINHO_FACIL].aberto == 0){

      jogo->tabuleiro[posicao + VIZINHO_FACIL].aberto = 1;
      jogo->abertos++;
      jogo = encontra_similares(jogo, posicao + VIZINHO_FACIL);
      
    }

  }
      
  return jogo;
   
}