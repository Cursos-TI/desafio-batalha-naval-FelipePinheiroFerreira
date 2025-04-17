#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializando todo o tabuleiro com água (0)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

     // Definir navios

     int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3}; 
     int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};   

     // Posicionar os navios

     int linhaHorizontal = 2;
     int colunaHorizontal = 4;

      // Verificar se o navio cabe no tabuleiro (horizontal)
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    }
 
    // Coordenadas do navio vertical (coluna fixa, linha variável)
    int linhaVertical = 5;
    int colunaVertical = 6;

     // Verificar se o navio cabe no tabuleiro (vertical)
    // E verificar se não haverá sobreposição
    int sobreposicao = 0;
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }
    }

    if (!sobreposicao) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    } else {
        printf("Erro: Sobreposição detectada! Navio vertical não posicionado.\n");
    }

   // Exibir o tabuleiro

   printf("\n=== Tabuleiro Batalha Naval ===\n\n");

   for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
       for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
           printf("%d ", tabuleiro[linha][coluna]);
       }
       printf("\n");
   }

    return 0;
}
