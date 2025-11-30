#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------
// Estrutura de uma sala (nó da árvore)
// ---------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// ------------------------------------------------
// Função: criarSala()
// Cria dinamicamente uma sala com nome fornecido
// ------------------------------------------------
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ----------------------------------------------------------
// Função: explorarSalas()
// Permite que o jogador navegue pela mansão
// indo para esquerda (e), direita (d) ou saindo (s)
// Percorre até chegar em um nó folha
// ----------------------------------------------------------
void explorarSalas(Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está na sala: **%s**\n", atual->nome);

        // nó folha = fim da exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Não há mais caminhos! Você chegou ao fim da exploração.\n");
            return;
        }

        printf("\nEscolha um caminho:\n");
        if (atual->esquerda != NULL) printf("  (e) Ir para a esquerda -> %s\n", atual->esquerda->nome);
        if (atual->direita != NULL)  printf("  (d) Ir para a direita -> %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        }
        else if (opcao == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            return;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// ---------------------------
// Função principal
// Monta a árvore da mansão
// ---------------------------
int main() {

    // Criando as salas (nós da árvore)
    Sala* hall        = criarSala("Hall de Entrada");
    Sala* salaEstar   = criarSala("Sala de Estar");
    Sala* cozinha     = criarSala("Cozinha");
    Sala* biblioteca  = criarSala("Biblioteca");
    Sala* jardim      = criarSala("Jardim");
    Sala* porao       = criarSala("Porão");

    /*
        Estrutura da mansão (exemplo):

                    Hall
                   /     \
           Sala Estar    Cozinha
            /     \          \
     Biblioteca   Jardim     Porão
    */

    hall->esquerda = salaEstar;
    hall->direita  = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita  = jardim;

    cozinha->direita = porao;

    // Começa a exploração pelo Hall
    printf("=== Detective Quest ===\n");
    printf("Você iniciará a exploração pelo Hall da Mansão.\n");
    
    explorarSalas(hall);

    printf("\nObrigado por jogar!\n");

    return 0;
}
