#include <stdio.h>
#include <string.h>

// struct da cidade.
typedef struct {
    char state[50]; 
    char id_card[50];
    char city[50];
    float population;
    float field;
    float pib;  
    int tourist_spot_numbers;
} Card;

// função que recebe a struct de carta para interagir com usuario e adicionar a carta.
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

int main() {

    Card card_one;
    Card card_two;
    // variavel onde será armazenado a pontuação da cidade.
    int play_one, play_two;


    add_attributes(&card_one);
    printf(" \n \n adicionado carta 2 \n \n ");
    add_attributes(&card_two);

    if (card_one.population < card_two.population) {
        printf("A cidade %s tem a menor densidade populacional. \n", card_one.city);
        play_one = play_one + 1;
    } else {
        printf("A cidade %s tem a menor densidade populacional. \n", card_two.city);
        play_two =  play_two + 1;
    }
    if (card_one.field > card_two.field) {
        printf("A cidade %s tem maior área. \n", card_one.city);
        play_one = play_one + 1;
    } else {
        printf("A cidade %s tem maior área. \n", card_two.city);
        play_two =  play_two + 1;
    }
    if (card_one.pib > card_two.pib) {
        printf("A cidade %s tem maior PIB. \n", card_one.city);
        play_one = play_one + 1;
    } else {
        printf("A cidade %s tem maior PIB. \n", card_two.city);
        play_two =  play_two + 1;
    }
    if (card_one.tourist_spot_numbers > card_two.tourist_spot_numbers) {
        printf("A cidade %s tem mais pontos turisticos. \n", card_one.city);
        play_one = play_one + 1;
    } else {
        printf("A cidade %s tem mais pontos turisticos. \n", card_two.city);
        play_two =  play_two + 1;
    }


    // verificando vencedor.
    if(play_one > play_two) {
        printf("A cidade vencedora é: %s\n", card_one.city);
    } else if (play_one > play_two) {
        printf("A cidade vencedora é: %s\n", card_two.city);
    } else {
        prinft("As cidade empataram!")
    }

    return 0;
}
