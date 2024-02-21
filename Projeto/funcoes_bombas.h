// Função que conta a quantidade de bombas vizinhas de uma célula
Jogo* conta_bombas(Jogo *jogo, int VIZINHO);

// Função que insere aleatoriamente as bombas no tabuleiro
Jogo* insere_bombas (Jogo *jogo, int vizinho);

// Função que encontra células com a mesma quantidade de bombas vizinhas
Jogo* encontra_similares(Jogo *jogo, int posicao);

// Função que verifica se uma posição é válida
int valida_x(int x, int tam);