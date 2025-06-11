#include <stdio.h>

// Definição da estrutura Carta
struct Carta {
    char estado;                // Letra de 'A' a 'H'
    char codigo[4];             // Ex: A01, B03 (3 caracteres + '\0')
    char nomeCidade[100];      // Nome da cidade
    int populacao;             // Número de habitantes
    float area;                // Área em km²
    float pib;                 // Produto Interno Bruto
    int pontosTuristicos;      // Número de pontos turísticos
};

void lerCarta(struct Carta *carta, int numero) {
    printf("Digite os dados da Carta %d:\n", numero);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpa o buffer do teclado
    fgets(carta->nomeCidade, 100, stdin);
    // Remover o caractere de nova linha se presente
    int i = 0;
    while (carta->nomeCidade[i] != '\0') {
        if (carta->nomeCidade[i] == '\n') {
            carta->nomeCidade[i] = '\0';
            break;
        }
        i++;
    }

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("\n");
}

void exibirCarta(struct Carta carta, int numero) {
    printf("Carta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("\n");
}

int main() {
    struct Carta carta1, carta2;

    // Leitura dos dados
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibição dos dados
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
