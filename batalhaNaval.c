#include <stdio.h>

// Definições de constantes para facilitar a manutenção e legibilidade
#define TAM_TAB 10      // Tamanho do tabuleiro
#define TAM_HAB 5       // Tamanho das matrizes de habilidade (5x5)
#define AGUA 0          // Representação da água
#define NAVIO 3         // Representação do navio
#define HABILIDADE 5    // Representação da área de efeito

int main() {
    // 1. Declaração de matrizes
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionamento dos Navios
    int areaNavio = 3;
    
    // Navio Horizontal
    int linhaH = 2, colunaH = 4;
    for (int i = 0; i < areaNavio; i++) tabuleiro[linhaH][colunaH + i] = NAVIO;

    // Navio Vertical
    int linhaV = 5, colunaV = 1;
    for (int i = 0; i < areaNavio; i++) tabuleiro[linhaV + i][colunaV] = NAVIO;

    // Navio Diagonal 1 (\)
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < areaNavio; i++) tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;

    // Navio Diagonal 2 (/)
    int linhaD2 = 7, colunaD2 = 9;
    for (int i = 0; i < areaNavio; i++) tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;


    // 3. Habilidades
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            
            // --- Lógica do CONE ---
            if (i < 3 && j >= (centro - i) && j <= (centro + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }

            // --- Lógica da CRUZ ---
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }

            // --- Lógica do OCTAEDRO (Losango) ---
            int dist_i = (i > centro) ? (i - centro) : (centro - i);
            int dist_j = (j > centro) ? (j - centro) : (centro - j);
            if (dist_i + dist_j <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // 4. Sobreposição de Habilidades.
    int origemConeL = 2, origemConeC = 7;
    int origemCruzL = 8, origemCruzC = 4;
    int origemOctL = 5,  origemOctC = 6;

    // Aplicando habilidades usando loops aninhados
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            
            // Cálculo da posição no tabuleiro
            int tabLinCone = origemConeL + (i - centro);
            int tabColCone = origemConeC + (j - centro);
            
            int tabLinCruz = origemCruzL + (i - centro);
            int tabColCruz = origemCruzC + (j - centro);
            
            int tabLinOct  = origemOctL + (i - centro);
            int tabColOct  = origemOctC + (j - centro);

            // Condicionais para garantir que a habilidade esteja dentro do tabuleiro (0-9)
            // Aplica Cone
            if (tabLinCone >= 0 && tabLinCone < TAM_TAB && tabColCone >= 0 && tabColCone < TAM_TAB) {
                if (cone[i][j] == 1) tabuleiro[tabLinCone][tabColCone] = HABILIDADE;
            }
            
            // Aplica Cruz
            if (tabLinCruz >= 0 && tabLinCruz < TAM_TAB && tabColCruz >= 0 && tabColCruz < TAM_TAB) {
                if (cruz[i][j] == 1) tabuleiro[tabLinCruz][tabColCruz] = HABILIDADE;
            }
            
            // Aplica Octaedro
            if (tabLinOct >= 0 && tabLinOct < TAM_TAB && tabColOct >= 0 && tabColOct < TAM_TAB) {
                if (octaedro[i][j] == 1) tabuleiro[tabLinOct][tabColOct] = HABILIDADE;
            }
        }
    }

    // 5. --- Exibição ---
    printf("\n===============================================\n");
    printf("     BATALHA NAVAL - NIVEL MESTRE - FINAL\n");
    printf("===============================================\n\n");

    // Cabeçalho das colunas (A-J)
    printf("    ");
    for (int j = 0; j < TAM_TAB; j++) printf("%c ", 'A' + j);
    printf("\n");

    // Conteúdo do tabuleiro
    for (int i = 0; i < TAM_TAB; i++) {
        printf("%2d  ", i + 1); // Número da linha
        for (int j = 0; j < TAM_TAB; j++) {
            // Diferenciação visual para facilitar a leitura
            if (tabuleiro[i][j] == NAVIO) printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("5 ");
            else printf("0 ");
        }
        printf("\n");
    }

    printf("\nLegenda: 0=Água | 3=Navio | 5=Habilidade\n");

    return 0;
}