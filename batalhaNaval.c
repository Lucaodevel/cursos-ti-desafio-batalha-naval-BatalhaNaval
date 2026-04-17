#include <stdio.h>

int main(){

    // Declaração das Variaveis
    int areaTab = 10;
    int areaNavio = 3;

    // Matriz do Tabuleiro iniciando em '0'
    int tabuleiro[10][10];

    for (int i = 0; i < areaTab; i++) {
        for(int j = 0; j < areaTab; j++) {
            tabuleiro[i][j] = 0;            
        }
    }

    // Colocando navios no tabuleiro
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    //Coordenadas Iniciais
    int linhaH = 2, colunaH = 4; // Horizontal
    int linhaV = 5, colunaV = 1; // Vertical

    // Navio Horizontal
    if (colunaH + areaNavio > areaTab) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // Verifica sobreposição
    for (int i = 0; i < areaNavio; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    }

    // Posição navio horizontal

    for (int i = 0; i < areaNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Navio Vertical
    if (linhaV + areaNavio > areaTab) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // Verifica sobreposição
    for (int i = 0; i < areaNavio; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < areaNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // -------- EXIBIÇÃO --------
    printf("\nTabuleiro Batalha Naval:\n");

    printf("\n   ");

    // Letras das colunas
    for (int j = 0; j < areaTab; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Linhas + conteúdo
    for(int i = 0; i < areaTab; i++) {
        printf("%2d ", i + 1); // linhas de 1 a 10

        for(int j = 0; j < areaTab; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0