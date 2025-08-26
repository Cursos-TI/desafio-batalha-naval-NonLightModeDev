#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    *
    * Structs
    *
*/
// Para criar um navio
struct Navio {
    short int tamanho;
    short int posicionamento;
    short int linha;
    char coluna;
    short int *partes;
};

// Para criar uma habilidade
struct Habilidade {
    short int codigo;
    char nome[50];
    short int partes[3][5];
};

/*
    *
    * Funções
    *
*/
// Para inicializar o tabuleiro com 0s
void inicializarTabuleiro(short int tabuleiro[10][10]) {
    for(short int i = 0; i < 10; i++) {
        for(short int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Para exibir o tabuleiro
int exibirTabuleiro(short int tabuleiro[10][10]) {
    char coluna[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    printf("\n");
    printf("  ");

    // Imprimindo as letras das colunas
    for(short int i = 0; i < 10; i++) {
        printf("  %c", coluna[i]);
    }
    printf("\n");

    // Imprimindo as linhas bem como os valores
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

// Para inicializar um navio com 3s de acordo com tamanho
void inicializarNavio(struct Navio *navio) {
    for(short int i = 0; i < navio->tamanho; i++) {
        navio->partes[i] = 3;
    }
};

// Para exibir o menu
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

// Para atualizar o tabuleiro, inserindo um navio
void atualizarTabuleiro(short int tabuleiro[10][10], struct Navio *navio) {
    short int c = 0;
    short int l = navio->linha - 1;
    short int ok = 1;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};

    // Pegando o índice da coluna
    for(short int i = 0; i < 10; i++) {
        if(navio->coluna == letras[i]) {
            c = i;
            break;
        }
    }

    // Posicionamento um navio de acordo com as coordenadas informadas
    if(navio->posicionamento == 1) {
        // Posicionamento Vertical
        for(short int i = l; i < l + navio->tamanho; i++) {
            if(i >= 10 || tabuleiro[i][c] != 0) {
                ok = 0;
                printf("\n |* Não há espaço! Navio descartado... *| \n\n");
                break;
            }
        }

        if(ok) {
            for(short int i = l, j = 0; i < l + navio->tamanho; i++, j++) {
                tabuleiro[i][c] = navio->partes[j];
            }
        }
    } else if(navio->posicionamento == 2) {
        // Posicionamento Horizontal
        for(short int i = c; i < c + navio->tamanho; i++) {
            if(i >= 10 || tabuleiro[l][i] != 0) {
                printf("\n |* Não há espaço! Navio descartado... *| \n\n");
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(short int i = c, j = 0; i < c + navio->tamanho; i++, j++) {
                tabuleiro[l][i] = navio->partes[j];
            }
        }
    } else {
        // Posicionamento Diagonal
        for(short int i = l, col = c; i < l + navio->tamanho; i++, col++) {
            if(i >= 10 || tabuleiro[i][col] != 0) {
                printf("\n |* Não há espaço! Navio descartado... *| \n\n");
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(short int i = l, j = 0, col = c; i < l + navio->tamanho; i++, j++, col++) {
                tabuleiro[i][col] = navio->partes[j];
            }
        }
    }
}

// Para inicilizar uma habilidade com 0s
void inicializarHabilidade(struct Habilidade *habilidade) {
    for(short int i = 0; i < 3; i++) {
        for(short int j = 0; j < 5; j++) {
            habilidade->partes[i][j] = 0;
        }
    }
}

// Para criar um Cone
void criarHabilidadeCone(struct Habilidade *habilidade) {
    inicializarHabilidade(habilidade);
    for(short int i = 0; i < 3; i++) {
        for(short int j = 0; j < 5; j++) {
            if(i == 0 && j == 2) {
                habilidade->partes[i][j] = 1;
            } else if(i == 1 && (j != 0 && j != 4)) {
                habilidade->partes[i][j] = 1;
            } else if(i == 2) {
                habilidade->partes[i][j] = 1;
            }
        }
    }
}

// Para criar uma Cruz
void criarHabilidadeCruz(struct Habilidade *habilidade) {
    inicializarHabilidade(habilidade);
    for(short int i = 0; i < 3; i++) {
        for(short int j = 0; j < 5; j++) {
            if((i == 0 || i == 2) && j == 2) {
                habilidade->partes[i][j] = 5;
            } else if(i == 1) {
                habilidade->partes[i][j] = 5;
            }
        }
    }
}

// Para criar um Octaedro
void criarHabilidadeOctaedro(struct Habilidade *habilidade) {
    inicializarHabilidade(habilidade);
    for(short int i = 0; i < 3; i++) {
        for(short int j = 0; j < 5; j++) {
            if((i == 0 || i == 2) && j == 2) {
                habilidade->partes[i][j] = 8;
            } else if(i == 1 && (j != 0 && j != 4)) {
                habilidade->partes[i][j] = 8;
            }
        }
    }
}

// Para exibir como ficou uma habilidade
void exibirHabilidade(struct Habilidade *habilidade) {
    printf("\n");
    for(short int i = 0; i < 3; i++) {
        for(short int j = 0; j < 5; j++) {
            printf("%d ", habilidade->partes[i][j]);
        }
        printf("\n");
    }
}

// Para inserir uma habilidade no tabuleiro
void inserirHabilidadeNoTabuleiro(short int tabuleiro[10][10], struct Habilidade *habilidade, char coluna, short int linha) {
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
    
    // Inserindo habilidade
    switch(habilidade->codigo) {
        case 1:
            // Inserindo habilidade Cone
            if((l >= 0 && l <= 7) && (c >= 2 && c <= 7)) { // l (linha calculada) e c (coluna calculada)
                c -= 2; // Como a matriz da habilidade começa com 0s, para poder inserir o topo na posição correta, é necessário voltar 2 colunas
                for(short int i = l, hI = 0; i < l + 3; i++, hI++) { // i (linha do tabuleiro) e hI (linha da habilidade)
                    for(short int j = c, hJ = 0; j < c + 5; j++, hJ++) { // j (coluna do tabuleiro) e hJ (coluna da habilidade)
                        if(habilidade->partes[hI][hJ] == 0) continue;
                        tabuleiro[i][j] = habilidade->partes[hI][hJ];
                    }
                }
            }
            break;

        case 2:
        case 3:
            // Inserindo habilidade Cruz e Octaedro
            if((l >= 1 && l <= 7) && (c >= 2 && c <= 7)) { // l (linha calculada) e c (coluna calculada)
                l -= 1; // Para poder inserir o centro na posição correta, é necessário voltar 1 linha
                c -= 2; // Como a matriz da habilidade começa com 0s, para poder inserir o topo na posição correta, é necessário voltar 2 colunas
                for(short int i = l, hI = 0; i < l + 3; i++, hI++) { // i (linha do tabuleiro) e hI (linha da habilidade)
                    for(short int j = c, hJ = 0; j < c + 5; j++, hJ++) { // j (coluna do tabuleiro) e hJ (coluna da habilidade)
                        if(habilidade->partes[hI][hJ] == 0) continue;
                        tabuleiro[i][j] = habilidade->partes[hI][hJ];
                    }
                }
            }
            break;
    }
}

int main() {
    short int tabuleiro[10][10];
    short int numeroDeNavios = 4;
    struct Navio *navios = malloc(numeroDeNavios * sizeof(struct Navio));

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
        inicializarNavio(&navios[i]);
        printf("  -> Posicionamento (1. Vertical | 2. Horizontal | 3. Diagonal): ");
        scanf("%hd", &navios[i].posicionamento);
        if(navios[i].posicionamento < 1 || navios[i].posicionamento > 3) {
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
        atualizarTabuleiro(tabuleiro, &navios[i]);
    }
    printf("\nNavios:\n");
    exibirTabuleiro(tabuleiro);

    // Liberando memória alocada
    free(navios);


    // Criando habilidade Cone
    struct Habilidade cone;
    cone.codigo = 1;
    strcpy(cone.nome, "Cone");
    criarHabilidadeCone(&cone);
    inserirHabilidadeNoTabuleiro(tabuleiro, &cone, 'C', 3);

    // Criando habilidade Cruz
    struct Habilidade cruz;
    cruz.codigo = 2;
    strcpy(cruz.nome, "Cruz");
    criarHabilidadeCruz(&cruz);
    inserirHabilidadeNoTabuleiro(tabuleiro, &cruz, 'G', 2);

    // Criando habilidade Octaedro
    struct Habilidade octaedro;
    octaedro.codigo = 2;
    strcpy(octaedro.nome, "Octaedro");
    criarHabilidadeOctaedro(&octaedro);
    inserirHabilidadeNoTabuleiro(tabuleiro, &octaedro, 'G', 7);

    // Exibindo tabuleiro
    printf("\n\nResultado:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
