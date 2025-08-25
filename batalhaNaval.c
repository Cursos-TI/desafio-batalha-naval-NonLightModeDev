#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void inicializarTabuleiro(short int tabuleiro[10][10]) {
    for(short int i = 0; i < 10; i++) {
        for(short int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int exibirTabuleiro(short int tabuleiro[10][10]) {
    char coluna[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    printf("\n");
    printf("  ");
    for(short int i = 0; i < 10; i++) {
        printf("  %c", coluna[i]);
    }
    printf("\n");
    for(short int i = 0; i < 9; i++) {
        printf(" %d  ", (i + 1));
        for(short int j = 0; j < 10; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("%d  ", (10));
    for(short int j = 0; j < 10; j++) {
        printf("%d  ", tabuleiro[9][j]);
    }
    printf("\n\n");
}

void inicializarNavio(short int navio[], int len) {
    for(short int i = 0; i < len; i++) {
        navio[i] = 3;
    }
};

void exibirInfo() {
    printf("| ------------------ Info ------------------ |\n");
    printf("| -> Informe o tamanho do navio              |\n");
    printf("| -> Informme o posicionamento do navio      |\n");
    printf("| -> Informe as coordenadas do navio         |\n");
    printf("|   -> Ex.:                                  |\n");
    printf("|     -> Coluna B-D (vai de B a D) e Linha 4 |\n");
    printf("|     -> Coluna B e Linha 5-9 (vai de 5 a 9) |\n");
    printf("| ------------------------------------------ |\n");
}

int atualizarTabuleiro(short int tabuleiro[10][10], short int navio[], short int tamanhoNavio, short int posicionamento, short int linha, char coluna) {
    short int c = 0;
    short int l = linha - 1;
    short int ok = 1;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};

    for(short int i = 0; i < 10; i++) {
        if(coluna == letras[i]) {
            c = i;
            break;
        }
    }

    // printf("\n\n\nPos: %d\n\n\n", posicionamento);

    if(posicionamento == 1) {
        for(short int i = l; i < l + tamanhoNavio; i++) {
            if(i >= 10 || tabuleiro[i][c] != 0) {
                ok = 0;
                printf("\n |* %c%d ocupado! Navio descartado... *| \n\n", coluna, linha);
                break;
            }
        }

        if(ok) {
            for(short int i = l; i < l + tamanhoNavio; i++) {
                for(short int j = 0; j < tamanhoNavio; j++) {
                    tabuleiro[i][c] = navio[j];
                }
            }
        }
    } else if(posicionamento == 2) {
        for(short int i = c; i < c + tamanhoNavio; i++) {
            if(i >= 10 || tabuleiro[l][i] != 0) {
                printf("\n |* %c%d ocupado! Navio descartado... *| \n\n", coluna, linha);
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(short int i = c; i < c + tamanhoNavio; i++) {
                for(short int j = 0; j < tamanhoNavio; j++) {
                    tabuleiro[l][i] = navio[j];
                }
            }
        }
    }

    return ok;
}

struct Navio {
    short int tamanho;
    short int posicionamento;
    short int linha;
    char coluna;
    short int *partes;
};

int main() {
    // Nível Novato - Posicionamento dos Navios
    short int tabuleiro[10][10];
    short int numeroDeNavios = 4;
    struct Navio *navios = malloc(4 * sizeof(struct Navio));

    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);
    exibirInfo();
    for(int i = 0; i < numeroDeNavios; i++) {
        printf("Navio %d:", (i+1));
        printf("\n  -> Tamanho (2 a 4): ");
        scanf("%hd", &navios[i].tamanho);
        if(navios[i].tamanho < 2 || navios[i].tamanho > 4) {
            printf("\n |* Tamanho inválido! *| \n");
            printf(" |* Saindo... *| \n\n");
            return 1;
        }
        navios[i].partes = malloc(navios[i].tamanho * sizeof(short int));
        inicializarNavio(navios[i].partes, navios[i].tamanho);
        printf("  -> Posicionamento (1. Vertical | 2. Horizontal): ");
        scanf("%hd", &navios[i].posicionamento);
        if(navios[i].posicionamento < 1 || navios[i].posicionamento > 2) {
            printf("\n |* Posicionamento inválido! *| \n");
            printf(" |* Saindo... *| \n\n");
            free(navios);
            return 1;
        }
        printf("  -> Linha (1 a 10): ");
        scanf("%hd", &navios[i].linha);
        if(navios[i].linha < 1 || navios[i].linha > 10) {
            printf("\n |* Linha inválida! *| \n");
            printf(" |* Saindo... *| \n\n");
            free(navios);
            return 1;
        }
        printf("  -> Coluna (A a J): ");
        scanf(" %c", &navios[i].coluna);
                if(navios[i].coluna < 'A' || navios[i].coluna > 'J') {
            printf("\n |* Coluna inválida! *| \n");
            printf(" |* Saindo... *| \n\n");
            free(navios);
            return 1;
        }
        atualizarTabuleiro(tabuleiro, navios[i].partes, navios[i].tamanho, navios[i].posicionamento, navios[i].linha, navios[i].coluna);
    }
    exibirTabuleiro(tabuleiro);

    // Liberando memória alocada
    free(navios);

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

    return 0;
}
