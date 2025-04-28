#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.
typedef struct {
    char state[50]; 
    char id_card[50];
    char city[50];
    float population;
    float field;
    float pib;  
    int tourist_spot_numbers;
} Card;

void add_attributes(Card *new_card) {
    printf("Digite o nome da cidade: \n");
    scanf("%s", &new_card->city);

    printf("Digite o nome do estado: \n");
    scanf("%s", &new_card->state);

    printf("Digite o codigo da carta: \n");
    scanf("%s", &new_card->id_card);

    printf("Digite a quantidade de pupolação: \n");
    scanf("%f", &new_card->population);

    printf("Digite o tamanho da área: \n");
    scanf("%f", &new_card->field);

    printf("Digite o PIB: \n");
    scanf("%f", &new_card->pib);

    printf("Digite a quantidade de pontos turisticos: \n");
    scanf("%d", &new_card->tourist_spot_numbers);
};

// estado, código da carta, nome da cidade, população, área, PIB e número de pontos turísticos
int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    Card card_one;
    Card card_two;
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)
    
    // função que recebe a struct de carta para interagir com usuario e adicionar a carta.

    add_attributes(&card_one);
    add_attributes(&card_two);

    printf("cidade 1: %s \n", card_one.city);
    printf("cidade 2 %s \n", card_two.city);
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
