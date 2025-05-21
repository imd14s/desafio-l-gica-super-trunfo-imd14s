#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct da cidade.
typedef struct
{
    char state[50];
    char id_card[50];
    char city[50];
    float population;
    float field;
    float pib;
    int tourist_spot_numbers;
    float population_density;
    float pib_capital;
    float super_power;
} Card;

// função que recebe a struct de carta para interagir com usuario e adicionar a carta.
Card add_attributes()
{
    Card new_card;
    char buffer[100];

    printf("\nDigite o nome da cidade: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n"); // remove o \n
    strcpy(new_card.city, buffer);

    printf("\nDigite o nome do estado: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");
    strcpy(new_card.state, buffer);

    printf("\nDigite o codigo da carta: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");
    strcpy(new_card.id_card, buffer);

    printf("\nDigite a quantidade de população: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.population) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    printf("\nDigite o tamanho da área: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.field) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    printf("\nDigite o PIB: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.pib) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    printf("\nDigite a quantidade de pontos turísticos: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%d", &new_card.tourist_spot_numbers) == 1)
            break;
        printf("Valor inválido. Digite um número inteiro: ");
    }

    // Calculando atributos derivados
    new_card.population_density = new_card.population / new_card.field;
    new_card.pib_capital = new_card.pib / new_card.population;
    new_card.super_power = 1 / new_card.population_density + new_card.pib_capital + new_card.tourist_spot_numbers;

    return new_card;
}

// função responsavel de exibir os atributos.
void display_card(Card *card)
{
    printf("\n=========================================\n");
    printf("         INFORMAÇÕES DA CARTA            \n");
    printf("=========================================\n");
    printf(" Cidade:                 %s\n", card->city);
    printf(" Estado:                 %s\n", card->state);
    printf(" Código da carta:        %s\n", card->id_card);
    printf("-----------------------------------------\n");
    printf(" População:              %.2f\n", card->population);
    printf(" Área (km²):             %.2f\n", card->field);
    printf(" PIB (R$):               %.2f\n", card->pib);
    printf(" Pontos turísticos:      %d\n", card->tourist_spot_numbers);
    printf("-----------------------------------------\n");
    printf(" Densidade populacional: %.2f hab/km²\n", card->population_density);
    printf(" PIB per capita:         %.2f\n", card->pib_capital);
    printf(" Super poder:            %.2f\n", card->super_power);
    printf("=========================================\n");
}

int frist_manu()
{
    char buffer[100];
    int option;
    int list_option[] = {0, 1, 2, 3};

    while (1)
    {
        printf("\n###############################\n\n");
        printf("[1] - Cadastrar carta\n");
        printf("[2] - Comparar cartas\n");
        printf("[3] - Exibir cartas cadastradas\n");
        printf("[0] - Finalizar\n");
        printf("\n###############################\n\n");

        printf("Digite a opção: ");
        fgets(buffer, sizeof(buffer), stdin); // lê como string

        if (sscanf(buffer, "%d", &option) != 1)
        { // não é número
            printf("\nOpção inválida! Digite apenas números.\n");
            continue;
        }

        // verifica se está entre as opções permitidas
        int valido = 0;
        for (int i = 0; i < 4; i++)
        {
            if (option == list_option[i])
            {
                valido = 1;
                break;
            }
        }

        if (!valido)
        {
            printf("\nOpção inválida! Número fora das opções.\n");
            continue;
        }

        return option; // opção válida
    }
}

int main()
{
    int quantity_card = 0;
    int length = 5;
    int option = 0;
    Card *list_card = malloc(length * sizeof(Card));
    Card new_card;

    while (1)
    {
        if (quantity_card == length)
        {
            length *= 5;
            list_card = realloc(list_card, length * sizeof(Card));
        }
        option = frist_manu();
        switch (option)
        {
        case 1:
            new_card = add_attributes();
            list_card[quantity_card] = new_card;
            quantity_card++;
            printf("\n\nCarta adicionada\n");
            display_card(&new_card);
            continue;
        case 3:
            for (int i = 0; i < quantity_card; i++)
            {
                printf("\n\n#########################################");
                printf("\n#           CARTA %d DE %d               #", i + 1, quantity_card);
                printf("\n#########################################\n");

                display_card(&list_card[i]);
            }

            continue;
        default:
            break;
        }
    };

    free(list_card);
    return 0;
}
