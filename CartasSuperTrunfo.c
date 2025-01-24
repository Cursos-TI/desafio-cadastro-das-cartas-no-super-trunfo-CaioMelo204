#include <stdio.h>

struct Card {
    char city[25];
    int population;
    float area;
    float PIB;
    int tourist;
};

struct State {
    char name[20];
    struct Card card[4];
};

struct Country {
    char name[20];
    struct State state[8];
};

int main(void)
{
    struct Country country;

    printf("Enter country name: ");
    scanf("%s", country.name);

    for (int i = 0; i < 8; i++) {
        printf("Enter country state[%d]: ", i + 1);
        scanf("%s", country.state[i].name);

        for (int j = 0; j < 4; j++) {
            printf("Enter city: ");
            scanf("%s", country.state[i].card[j].city);
            printf("Enter population: ");
            scanf("%d", &country.state[i].card[j].population);
            printf("Enter area: ");
            scanf("%f", &country.state[i].card[j].area);
            printf("Enter PIB: ");
            scanf("%f", &country.state[i].card[j].PIB);
            printf("Enter tourist: ");
            scanf("%d", &country.state[i].card[j].tourist);
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("%s\n", country.state[i].name);
        for (int j = 0; j < 4; j++) {
            printf("%s ", country.state[i].name);
            printf("%s ", country.state[i].card[j].city);
            printf("%d ", country.state[i].card[j].population);
            printf("%f ", country.state[i].card[j].area);
            printf("%f ", country.state[i].card[j].PIB);
            printf("%d ", country.state[i].card[j].tourist);
        }
    }
}
