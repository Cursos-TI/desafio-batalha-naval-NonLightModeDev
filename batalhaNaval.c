#include <stdio.h>

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

int main() {
    // Nível Novato - Posicionamento dos Navios
    short int tabuleiro[10][10];
    short int tamanhoNavio1, posicionamentoNavio1, linhaNavio1;
    char colunaNavio1;
    short int tamanhoNavio2, posicionamentoNavio2, linhaNavio2;
    char colunaNavio2;

    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);
    exibirInfo();
    printf("Navio 1:");
    printf("\n  -> Tamanho (2 a 4): ");
    scanf("%hd", &tamanhoNavio1);
    short int navio1[tamanhoNavio1];
    inicializarNavio(navio1, tamanhoNavio1);
    printf("  -> Posicionamento (1. Vertical | 2. Horizontal): ");
    scanf("%hd", &posicionamentoNavio1);
    printf("  -> Linha (1 a 10): ");
    scanf("%hd", &linhaNavio1);
    printf("  -> Coluna (A a J): ");
    scanf(" %c", &colunaNavio1);
    atualizarTabuleiro(tabuleiro, navio1, tamanhoNavio1, posicionamentoNavio1, linhaNavio1, colunaNavio1);
    printf("\nNavio 2:");
    printf("\n  -> Tamanho (2 a 4): ");
    scanf("%hd", &tamanhoNavio2);
    short int navio2[tamanhoNavio2];
    inicializarNavio(navio2, tamanhoNavio2);
    printf("  -> Posicionamento (1. Vertical | 2. Horizontal): ");
    scanf("%hd", &posicionamentoNavio2);
    printf("  -> Linha (1 a 10): ");
    scanf("%hd", &linhaNavio2);
    printf("  -> Coluna (A a J): ");
    scanf(" %c", &colunaNavio2);
    atualizarTabuleiro(tabuleiro, navio2, tamanhoNavio2, posicionamentoNavio2, linhaNavio2, colunaNavio2);
    exibirTabuleiro(tabuleiro);

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
