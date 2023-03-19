#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;
const int FALSE = 0;

typedef struct {
    int value;
    char type[1];
} Card;

void bubbleSort(Card *card, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (card[j].value < card[j - 1].value) {
                Card swapCard = card[j];
                card[j] = card[j - 1];
                card[j - 1] = swapCard;
            }
        }
    }
}

void selectionSort(Card *card, int n) {
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (card[j].value < card[minj].value) {
                minj = j;
            }
        }
        Card swapCard = card[i];
        card[i] = card[minj];
        card[minj] = swapCard;
    }
}

int isStable(Card *card1, Card *card2, int n) {
    for (int i = 0; i < n; i++) {
        if (card1[i].type[0] != card2[i].type[0]) {
            return FALSE;
        }
    }
    return TRUE;
}

void printCard(Card *card, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%s%d\n", card[i].type, card[i].value);
        } else {
            printf("%s%d ", card[i].type, card[i].value);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Card *card = malloc(n * sizeof(Card));
    Card bubbleSortCard[n];
    Card selectionSortCard[n];

    // initialize cards
    for (int i = 0; i < n; i++) {
        // input \0 -> initialize
        card[i].type[0] = '\0';
        card[i].value = 0;
        bubbleSortCard[i].type[0] = '\0';
        bubbleSortCard[i].value = 0;
        selectionSortCard[i].type[0] = '\0';
        selectionSortCard[i].value = 0;
    }

    for (int i = 0; i < n; i++) {
        char tmp[2];
        scanf("%s", tmp);
        card[i].type[0] = tmp[0];
        // char to int
        card[i].value = tmp[1] - '0';
        bubbleSortCard[i] = card[i];
        selectionSortCard[i] = card[i];
    }

    bubbleSort(bubbleSortCard, n);
    selectionSort(selectionSortCard, n);

    int isOK = TRUE;

    isOK = isStable(bubbleSortCard, selectionSortCard, n);

    printCard(bubbleSortCard, n);
    printf("Stable\n");
    printCard(selectionSortCard, n);
    if (isOK) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
}
