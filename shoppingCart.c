#include <stdio.h>

float cart(char *items[], int *amountForEach, float priceForEach[], int sizeItems){
    while (1){
        if (sizeItems == 0){
            printf("Your cart is still empty!\n");
            return -1;
        }
        float total = 0.0f;

        printf("=============Your cart=============\n");
        for (int i = 0; i < sizeItems; i++){
            printf("Item #%d\n", i + 1);
            printf("Item name: %s\n", items[i]);        
            printf("Item amount in cart: %d\n", amountForEach[i]);        
            printf("Item price for each: %.2f\n", priceForEach[i]);
            printf("Subtotal: %.2f\n", amountForEach[i] * priceForEach[i]);
            printf("-----------------------------------\n");
            total += amountForEach[i] * priceForEach[i];
        }
        printf("Total: %.2f\n", total);
        printf("-----------------------------------\n");

        char choice = '\0';
        printf("1. Change item amount by name\n");
        printf("2. Go to payment\n");
        scanf("%c", &choice);

        if (choice == '1'){
            int num = 0;

            while (num > sizeItems || num < 1){
                printf("Select item by it's number: ");
                scanf("%d", &num);
            }
    
            int newAmount = 0;
            printf("Select the new amount: ");
            scanf("%d", &newAmount);
            amountForEach[num - 1] = newAmount;
        }

        else if (choice == '2'){
            if (sizeItems == 0){
                printf("Your cart is still empty\n");
                return -1;
            }
            return total;
        }
        else{
            printf("Your choice is invalid, please to try again!\n");
        }
    }
}

int main(){
    char *item[] = {"Adidas Shoe", "Calculus 1 Book"};
    int amount[] = {1, 3};
    float price[] = {229.5, 39.5};
    cart(item, amount, price, 2);

    return 0;
}
