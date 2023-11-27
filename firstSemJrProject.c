#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Item {
    char name[50];
    int quantity;
    int price;
    int  isSelected;
};

void printTitle() {
    printf("\t============================\n");
    printf("\t|   Welcome to Restaurant  |\n");
    printf("\t============================\n");
    printf("\t          |MENU|            \n");
    printf("\t          ======\n");
}

void printMenu(struct Item *items, int size) {
    printf("\n\n");
    printf("\n---------------------------------\n");
    for(int i=0; i<size; ++i) {
        printf("%d. %s \t %d/- \n",i+1, items[i].name, items[i].price);
    }
    printf("\n---------------------------------\n");
}


void takeOrder(struct Item* items, int size) {
    int itemIndex;
    
    printf("Select item : ");
    scanf("%d", &itemIndex);

    int quantity;
    printf("Kindly tell quantity : ");
    scanf("%d", &quantity);

    itemIndex -=1;

    items[itemIndex].isSelected = 1;

    items[itemIndex].quantity = quantity;

}


void calculateBill(struct Item* items, int size) {
    int grandTotal = 0;

    for(int i=0; i<size; ++i) {
        grandTotal += (items[i].price * items[i].quantity);
    }

    printf("Grand total : %d\n\n", grandTotal);
}

void printBill(struct Item* items, int size) {
    printf("\t\n          \t--------");
    printf("\t\n          \t| BILL |");																	
    printf("\n---------------------------------------------");
    printf("\n|NAME|");
    printf("\t |QUANTITY|");
    printf("\t |PRICE|");
    printf("\t |TOTAL|");
    printf("\n---------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        if(items[i].isSelected == 1) {
            printf("%s \t %d \t %d \t %d \n", items[i].name, items[i].quantity, items[i].price, (items[i].price * items[i].quantity));
        }
        
    }
}

int main() {
    struct Item items[5] = {
        {"Chicken Tikka", 0, 120, 0},
        {"Chapli kabab", 0, 100, 0},
        {"Briyani", 0, 150, 0},
        {"Zarda", 0, 120, 0},
        {"Roti", 0, 15, 0}
    };
    char input = '\0';
    for(int i=0; i<5; ++i) {
        system("cls");
        printTitle();
        printMenu(items, 5);
        takeOrder(items, 5);

        printf("\n\nDo you want to calculate bill? y/n : ");
        fflush(stdin);
        scanf("%c", &input);

        if(input == 'y') {
            break;
        }
    }

    printBill(items, 5);
    calculateBill(items, 5);

    return 0;
}
