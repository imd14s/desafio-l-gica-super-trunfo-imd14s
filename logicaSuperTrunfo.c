#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Estrutura que representa uma carta de cidade com diversos atributos.
 * 
 * Campos:
 * - state: nome do estado da cidade (string de até 50 caracteres).
 * - id_card: identificador único da carta (string de até 50 caracteres).
 * - city: nome da cidade (string de até 50 caracteres).
 * - population: população da cidade (float).
 * - field: área territorial da cidade (float).
 * - pib: Produto Interno Bruto da cidade (float).
 * - tourist_spot_numbers: número de pontos turísticos na cidade (int).
 * - population_density: densidade populacional da cidade (float).
 * - pib_capital: PIB per capita da cidade (float).
 * - super_power: atributo especial da cidade, pode representar algum índice ou característica diferenciada (float).
 */
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


/**
 * Solicita ao usuário a entrada dos atributos de uma nova carta de cidade.
 * Realiza a leitura e validação dos dados de entrada.
 * Calcula atributos derivados como densidade populacional, PIB per capita e super poder.
 * 
 * Retorna:
 * - Uma variável do tipo Card com todos os campos preenchidos com os valores informados e calculados.
 */
Card add_attributes()
{
    Card new_card;
    char buffer[100];

    // Solicita o nome da cidade e remove o caractere de nova linha
    printf("\nDigite o nome da cidade: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");  // Remove o '\n' do final da string
    strcpy(new_card.city, buffer);

    // Solicita o nome do estado e remove o caractere de nova linha
    printf("\nDigite o nome do estado: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");
    strcpy(new_card.state, buffer);

    // Solicita o código identificador da carta e remove o caractere de nova linha
    printf("\nDigite o codigo da carta: \n");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");
    strcpy(new_card.id_card, buffer);

    // Solicita a população e valida a entrada para garantir número válido
    printf("\nDigite a quantidade de população: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.population) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    // Solicita o tamanho da área e valida a entrada
    printf("\nDigite o tamanho da área: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.field) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    // Solicita o PIB e valida a entrada
    printf("\nDigite o PIB: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%f", &new_card.pib) == 1)
            break;
        printf("Valor inválido. Digite um número: ");
    }

    // Solicita a quantidade de pontos turísticos e valida entrada como inteiro
    printf("\nDigite a quantidade de pontos turísticos: \n");
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%d", &new_card.tourist_spot_numbers) == 1)
            break;
        printf("Valor inválido. Digite um número inteiro: ");
    }

    // Calcula a densidade populacional (população / área)
    new_card.population_density = new_card.population / new_card.field;

    // Calcula o PIB per capita (PIB / população)
    new_card.pib_capital = new_card.pib / new_card.population;

    // Calcula o "super poder" combinando densidade, PIB per capita e pontos turísticos
    new_card.super_power = 1 / new_card.population_density + new_card.pib_capital + new_card.tourist_spot_numbers;

    return new_card;
}


/**
 * Exibe todas as informações de uma carta do tipo Card formatadas no console.
 * 
 * Parâmetros:
 * - card: ponteiro para a carta que será exibida.
 * 
 * Retorno: nenhum (void).
 */
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
    printf(" PIB per capital:        %.2f\n", card->pib_capital);
    printf(" Super poder:            %.2f\n", card->super_power);
    printf("=========================================\n");
}


/**
 * Exibe o menu principal e lê a opção escolhida pelo usuário.
 * 
 * A função apresenta um menu com 4 opções:
 * [1] - Cadastrar carta
 * [2] - Comparar cartas
 * [3] - Exibir cartas cadastradas
 * [0] - Finalizar
 * 
 * A entrada do usuário é lida como string e convertida para número.
 * Se a entrada for válida (entre 0 e 3), retorna a escolha.
 * Caso contrário, exibe uma mensagem de erro e repete até entrada válida.
 * 
 * Retorno:
 * - int: a opção escolhida pelo usuário (0 a 3)
 */
int first_menu()
{
    char buffer[100]; // Buffer para ler a entrada do usuário
    int user_choice;

    while (1)
    {
        printf("\n###############################\n\n");
        printf("[1] - Cadastrar carta\n");
        printf("[2] - Comparar cartas\n");
        printf("[3] - Exibir cartas cadastradas\n");
        printf("[0] - Finalizar\n");
        printf("\n###############################\n\n");

        printf("Digite a opção: ");
        fgets(buffer, sizeof(buffer), stdin); // Lê a entrada do usuário como string

        // Tenta extrair um número do buffer e valida se está entre 0 e 3
        if (sscanf(buffer, "%d", &user_choice) == 1 && user_choice >= 0 && user_choice <= 3)
        {
            return user_choice;
        }

        printf("Opção inválida!\n");
    }
}



/**
 * Exibe a lista completa de cartas cadastradas.
 * Para cada carta no array, exibe um cabeçalho indicando a posição da carta na lista
 * e chama a função display_card para mostrar os detalhes da carta.
 * 
 * Parâmetros:
 * - list_card[]: array contendo as cartas cadastradas
 * - quantity_card: quantidade total de cartas no array
 * 
 * Retorno: nenhum (void)
 */
void viewer_list_card(Card list_card[], int quantity_card)
{
    for (int index = 0; index < quantity_card; index++)
    {
        printf("\n\n#########################################");
        printf("\n#           CARTA %02d DE %02d           #", index + 1, quantity_card);
        printf("\n#########################################\n");

        display_card(&list_card[index]);
    }
}


/**
 * Permite ao usuário escolher dois atributos para a comparação entre cartas.
 * Exibe um menu com as opções de atributos disponíveis e valida a escolha do usuário.
 * Armazena as escolhas nos índices 0 e 1 do array list_comparison_attributes.
 * 
 * Parâmetros:
 * - list_comparison_attributes[]: array onde serão armazenados os dois atributos escolhidos pelo usuário
 * 
 * Retorno: nenhum (void)
 */
void menu_comparison(int list_comparison_attributes[])
{
    char buffer[100];                 // Buffer para entrada do usuário
    int picked = 0;

    while (picked < 2)
    {
        printf("\nEscolha o %dº atributo que será comparado:\n", picked + 1);
        printf("[1] - Densidade populacional\n");
        printf("[2] - Área\n");
        printf("[3] - PIB per capita\n");
        printf("[4] - Pontos Turísticos\n");
        printf("[5] - Super Poder\n");

        fgets(buffer, sizeof(buffer), stdin);
        int option;

        if (sscanf(buffer, "%d", &option) == 1 && option >= 1 && option <= 5)
        {
            list_comparison_attributes[picked++] = option;
        }
        else
        {
            printf("Opção inválida!\n");
        }
    }
}


/**
 * Permite ao usuário selecionar duas cartas para comparação.
 * Exibe um prompt para o usuário escolher as cartas pelo índice (1 a quantity_card).
 * Valida se a escolha está dentro do intervalo válido.
 * Armazena os índices escolhidos (convertidos para base 0) no array list_picked_card.
 * 
 * Parâmetros:
 * - list_picked_card[]: array onde serão armazenados os índices das cartas escolhidas
 * - quantity_card: quantidade total de cartas disponíveis para escolha
 * 
 * Retorno: nenhum (void)
 */
void picked_card(int list_picked_card[], int quantity_card)
{
    char buffer[100];                 // Buffer para entrada do usuário
    int quantity_picked = 0;

    // faz um loop até obter as 2 cartas para comparação
    while (quantity_picked < 2)
    {
        printf("\nEscolha a %dª carta que será comparada (1 a %d): ", quantity_picked + 1, quantity_card);
        fgets(buffer, sizeof(buffer), stdin); // ler a entrada do usuario
        int user_choice;

        // verifica se oque foi digitado é um numero, e adiciona a variavel user_choice.
        if (sscanf(buffer, "%d", &user_choice) == 1 && user_choice >= 1 && user_choice <= quantity_card)
        {
            list_picked_card[quantity_picked++] = user_choice - 1;
        }
        else
        {
            printf("Opção inválida!\n"); // mesagem de erro caso usuario digite uma opção invalida
        }
    }
}


/**
 * Compara duas cartas com base em dois atributos escolhidos.
 * 
 * Parâmetros:
 * - list_of_chosen_attributes[]: array com os índices dos atributos a serem comparados (2 atributos)
 * - list_of_chosen_cards[]: array com os índices das duas cartas a serem comparadas
 * - list_card[]: array com todas as cartas cadastradas
 * 
 * Retorno:
 * - 0 se a primeira carta vence
 * - 1 se a segunda carta vence
 * - -1 se houver empate
 * 
 * Regras de comparação:
 * - Para o atributo densidade populacional (1), menor valor vence
 * - Para os demais atributos, maior valor vence
 */
int compare_cards(int list_of_chosen_attributes[], int list_of_chosen_cards[], Card list_card[]) {
    int score_card_one = 0, score_card_two = 0;

    for (int index = 0; index < 2; index++) {
        int attribution = list_of_chosen_attributes[index];

        Card card_one = list_card[list_of_chosen_cards[0]];
        Card card_two = list_card[list_of_chosen_cards[1]];

        float value_attribution_card_one = 0, value_attribution_card_two = 0;

        // Atribui os valores correspondentes ao atributo escolhido
        switch (attribution) {
            case 1:  // Menor densidade populacional vence
                value_attribution_card_one = card_one.population_density;
                value_attribution_card_two = card_two.population_density;
                break;
            case 2:
                value_attribution_card_one = card_one.field;
                value_attribution_card_two = card_two.field;
                break;
            case 3:
                value_attribution_card_one = card_one.pib_capital;
                value_attribution_card_two = card_two.pib_capital;
                break;
            case 4:
                value_attribution_card_one = card_one.tourist_spot_numbers;
                value_attribution_card_two = card_two.tourist_spot_numbers;
                break;
            case 5:
                value_attribution_card_one = card_one.super_power;
                value_attribution_card_two = card_two.super_power;
                break;
        }

        // Regra especial: menor densidade populacional vence
        if (attribution == 1) {
            if (value_attribution_card_one < value_attribution_card_two) {
                score_card_one++;
            } else if (value_attribution_card_one > value_attribution_card_two) {
                score_card_two++;
            }
        } else {
            // Para os demais atributos, maior valor vence
            if (value_attribution_card_one > value_attribution_card_two) {
                score_card_one++;
            } else if (value_attribution_card_one < value_attribution_card_two) {
                score_card_two++;
            }
        }
    }

    // Retorno com base na pontuação total
    if (score_card_one > score_card_two) {
        return 0; // Primeira carta vence
    } else if (score_card_two > score_card_one) {
        return 1; // Segunda carta vence
    } else {
        return -1; // Empate
    }
}

/**
 * Executa o processo de comparação entre duas cartas:
 * - Exibe todas as cartas cadastradas
 * - Permite que o usuário escolha duas cartas e dois atributos para comparação
 * - Compara as cartas com base nos atributos escolhidos
 * - Exibe a carta vencedora ou, em caso de empate, exibe ambas
 * 
 * Parâmetros:
 * - list_card[]: array contendo todas as cartas cadastradas
 * - quantity_card: quantidade total de cartas cadastradas
 * 
 * Retorno: void (não retorna valor)
 */
void comparison(Card list_card[], int quantity_card)
{
    char buffer[100];                 // Buffer para entrada do usuário
    int list_of_chosen_attributes[2]; // Armazena os atributos escolhidos para comparação
    int list_of_chosen_cards[2];      // Armazena os índices das cartas escolhidas

    // Exibe todas as cartas cadastradas
    viewer_list_card(list_card, quantity_card);

    // Solicita que o usuário escolha duas cartas
    picked_card(list_of_chosen_cards, quantity_card);

    // Solicita que o usuário escolha dois atributos para comparar
    menu_comparison(list_of_chosen_attributes);

    // Realiza a comparação e retorna o índice da carta vencedora
    int card_winner = compare_cards(list_of_chosen_attributes, list_of_chosen_cards, list_card);

    // Verifica se houve carta vencedora
    if (card_winner >= 0)
    {
        printf("\n\nCarta Vencedora!\n\n");
        display_card(&list_card[list_of_chosen_cards[card_winner]]);
    }
    else
    {
        // Em caso de empate, exibe ambas as cartas empatadas
        printf("\nEmpate entre as cartas!\n");

        // Cria um array temporário com as cartas empatadas
        Card list_card_draw[2] = {
            list_card[list_of_chosen_cards[0]],
            list_card[list_of_chosen_cards[1]]};

        // Usa função de exibição para mostrar ambas
        viewer_list_card(list_card_draw, 2);
    }

    // Pausa para o usuário visualizar o resultado
    printf("\n\nPressione qualquer tecla para continuar!\n");
    fgets(buffer, sizeof(buffer), stdin);
}


/**
 * Função principal do programa.
 * 
 * Gerencia o fluxo principal:
 * - Inicializa a lista dinâmica de cartas com capacidade inicial.
 * - Exibe menu para o usuário escolher ações:
 *   - Cadastrar novas cartas (redimensionando a lista se necessário)
 *   - Comparar cartas cadastradas
 *   - Exibir todas as cartas cadastradas
 *   - Finalizar o programa
 * 
 * O programa continua em loop até o usuário escolher finalizar.
 * 
 * Retorno:
 * - int: código de saída do programa (0 indica sucesso)
 */
int main()
{
    int quantity_card = 0;    // Número de cartas cadastradas
    int length_list_card = 5; // Capacidade inicial da lista de cartas
    int option;               // Opção escolhida pelo usuário no menu

    Card *list_card = malloc(length_list_card * sizeof(Card)); // Alocação inicial da lista

    while (1)
    {
        // Redimensiona a lista quando atinge a capacidade máxima
        if (quantity_card == length_list_card)
        {
            length_list_card *= 2;
            list_card = realloc(list_card, length_list_card * sizeof(Card));
        }

        // Exibe o menu principal e lê a escolha do usuário
        option = first_menu();

        switch (option)
        {
        case 1:
        {
            // Adiciona uma nova carta e exibe seus dados
            Card new_card = add_attributes();
            list_card[quantity_card++] = new_card;
            printf("\n\nCarta adicionada!\n");
            display_card(&new_card);
            break;
        }
        case 2:
            // Compara cartas se houver pelo menos duas cadastradas
            if (quantity_card >= 2)
            {
                comparison(list_card, quantity_card);
            }
            else
            {
                printf("Você precisa de pelo menos 2 cartas para comparar!\n");
            }
            break;
        case 3:
            // Exibe todas as cartas cadastradas
            viewer_list_card(list_card, quantity_card);
            break;
        case 0:
            // Encerra o programa e libera a memória alocada
            printf("Finalizando programa...\n");
            free(list_card);
            return 0;
        }
    }
}

