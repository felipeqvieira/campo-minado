// Tamanho do campo na dificuldade fácil
#define TAM_FACIL 64
// Quantidade de bombas na dificuldade fácil
#define BOMB_FACIL 15
// Casa mais distante que pode ser vizinha na dificuldade fácil
#define VIZINHO_FACIL 9

// Tamanho do campo na dificuldade média
#define TAM_MEDIO 96
// Quantidade de bombas na dificuldade média
#define BOMB_MEDIO 30
// Casa mais distante que pode ser vizinha na dificuldade média
#define VIZINHO_MEDIO 10

// Tamanho do campo na dificuldade difícil
#define TAM_DIFICIL 120
// Quantidade de bombas na dificuldade difícil
#define BOMB_DIFICIL 45
// Casa mais distante que pode ser vizinha na dificuldade difícil
#define VIZINHO_DIFICIL 11

// Estrutura que representa uma célula do tabuleiro
typedef struct{
  // 0 = não é bomba, 1 = é bomba
  int bomba;
  // 0 = desconhecido, 1 = aberto
  int aberto;
  // Número de bombas vizinhas
  int numero;
} Celula;

typedef struct{
  // 1 = FÁCIL, 2 = Médio, 3 = Difícil
  int dificuldade;
  // Número de bombas no tabuleiro
  int bombas;
  // Número de células abertas
  int abertos;
  // Tamanho do tabuleiro
  int tamanho;
  Celula *tabuleiro;
} Jogo;

// Função que começa o jogo
int inicializa_jogo(Jogo *jogo);

// Função que inicializa as variáveis da estrutura do jogo
Jogo *cria_jogo(Jogo *jogo, int dificuldade, int num_bombas, int vizinho, int tamanho);

//Função que libera memória alocada
Jogo *libera_jogo(Jogo *jogo);