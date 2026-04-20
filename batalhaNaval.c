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
    int linhaD1 = 0, colunaD1 = 0; // Diagonal 1 (\)
    int linhaD2 = 7, colunaD2 = 9; // Diagonal 2 (/)

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

    // Posiciona Navio Diagonal 1
    if (linhaD1 + areaNavio <= areaTab && colunaD1 + areaNavio <= areaTab){
        int sobreposicao = 0;
        for (int i = 0; i < areaNavio; i++){
            if (tabuleiro[linhaD1 + i] [colunaD1 + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < areaNavio; i++){
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // Posiciona Navio Diagonal 2
    if (linhaD2 + areaNavio <= areaTab && colunaD2 - areaNavio >= 0){
        int sobreposicao = 0;
        for (int i = 0; i < areaNavio; i++){
            if(tabuleiro[linhaD2 + i][colunaD2 - i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao){
            for (int i = 0; i < areaNavio; i++){
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
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