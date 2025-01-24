#include <stdio.h>
#include <stdlib.h>

struct Card {
    char city[25];
    int population;
    float area;
    float PIB;
    int tourist;
    float densityPopulation;
    float PIBPerPerson;
};

struct State {
    char name[20];
    struct Card card[4];
};

struct Country {
    char name[20];
    struct State state[8];
};

struct Card* createCard() {
    struct Card *card = (struct Card *)malloc(sizeof(struct Card));
    printf("Enter city: ");
    scanf("%s", &card->city);
    printf("Enter population: ");
    scanf("%d", &card->population);
    printf("Enter area: ");
    scanf("%f", &card->area);
    printf("Enter PIB: ");
    scanf("%f", &card->PIB);
    printf("Enter tourist: ");
    scanf("%d", &card->tourist);
    printf("\n");
    card->densityPopulation = (float) card->population / card->area;
    card->PIBPerPerson = (float) card->PIB / card->population;

    return card;
}

void displayCard(struct Card *card) {
    printf("******************\n");
    printf("%s\n", card->city);
    printf("Population: %d\n", card->population);
    printf("Area: %.2f\n", card->area);
    printf("PIB: %.2f\n", card->PIB);
    printf("Tourist: %d\n", card->tourist);
    printf("DensityPopulation: %.2f\n", card->densityPopulation);
    printf("PIBPerPerson: %.2f\n", card->PIBPerPerson);
    printf("******************\n");
}

int main(void)
{
    struct Country country;

    printf("Enter country name: ");
    scanf("%s", country.name);

    for (int i = 0; i < 8; i++) {
        printf("Enter country state[%d]: ", i + 1);
        scanf("%s", country.state[i].name);

        for (int j = 0; j < 4; j++) {
            country.state[i].card[i] = *createCard();
            break;
        }
        break;
    }

    for (int i = 0; i < 8; i++) {
        printf("********* STATE ************ \n");
        printf("%s\n", country.state[i].name);
        for (int j = 0; j < 4; j++) {
            displayCard(&country.state[i].card[j]);
        }
        printf("***************************** \n");
    }
}
