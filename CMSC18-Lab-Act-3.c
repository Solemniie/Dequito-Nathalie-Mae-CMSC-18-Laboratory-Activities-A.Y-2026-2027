#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEQUITO M-2L

int main(){
    
    char productName[30][80] = {"\0"};
    int productQuantity[30] = {0};
    float productPrice[30] = {0.00f};

    float totalPrice = 0.00f;
    float dtotalPrice = 0.00f;
    char userSpecialClassification[4][20] = {
    "PWD",
    "Senior Citizen",
    "Pregnant",
    "None"
    };  

    int productCount = 0;
    char addAnotherItem;
    int classificationChoice;
    char pesoSign[30] = "php"; 
    int fieldWidth = 24;

    goto start;

    //Welcome Line
    start:
    printf("Nyaa! Welcome to Cat Boss' Receipt Maker (=^ o 3 o ^=)!\n");
    printf("Please enter the product name, price, and quantity! Meow~\n");

    do {
        printf("\nProduct Name: ");
        fgets(productName[productCount], sizeof(productName[productCount]), stdin);
        productName[productCount][strcspn(productName[productCount], "\n")] = '\0';
        printf("Product Price: ");
        scanf("%f", &productPrice[productCount]);
        printf("QTY: ");
        scanf("%d", &productQuantity[productCount]);
        while (getchar() != '\n' && getchar() != EOF) {
        }

        float itemTotal = productPrice[productCount] * productQuantity[productCount];
        totalPrice += itemTotal;
        printf("Updated total: %.2f%s\n", totalPrice, pesoSign);

        productCount++;

        if (productCount == 30) {
            break;
        }

        printf("\nDone, meow! Add another item? (y/n): ");
        scanf(" %c", &addAnotherItem);
        while (getchar() != '\n' && getchar() != EOF) {
        }

    } while (addAnotherItem == 'y');
    for (int productIndex = 0; productIndex < productCount; productIndex++) {
        float itemTotal = productPrice[productIndex] * productQuantity[productIndex];

    }
    goto classification_input;

        // To know the customer classification :3
        classification_input:
        printf("____________________________________________________________________\n");
        printf("Nya! Proceeding to checkout...\n");
        totalPrice = 0.00f;
        for (int productIndex = 0; productIndex < productCount; productIndex++) {
            totalPrice += productPrice[productIndex] * productQuantity[productIndex];
        }
        printf("\nYour total is %.2f %s\n", totalPrice, pesoSign);
        printf("Please select your customer classification, meow!:\n\n");
        printf("%s\n", userSpecialClassification[0]);
        printf("%s\n", userSpecialClassification[1]);
        printf("%s\n", userSpecialClassification[2]);
        printf("%s\n", userSpecialClassification[3]);
        printf("\nEnter the number corresponding to your classification (1-4): "); 
            scanf("%d", &classificationChoice);
            int classification_index = classificationChoice - 1;
            if (classification_index >= 0 && classification_index <= 3) {
                float discount = 0.0;
                switch (classification_index) {
                    case 0: // PWD
                        discount = 0.05; // 5% 
                        break;
                    case 1: // Senior Citizen
                        discount = 0.20; // 20% 
                        break;
                    case 2: // Pregnant
                        discount = 30.00; // 30.00
                        break;
                    case 3: // None
                        discount = 0.0; 
                        break;
                    }

                printf("\nYou selected: %s\n", userSpecialClassification[classification_index]);
                    if (classification_index == 2) {
                    dtotalPrice = (int)(totalPrice - discount);
                } else {
                    dtotalPrice = (int)((totalPrice - (abs(totalPrice * discount))));
                }
                printf("Your current total is: %.2f %s\n", totalPrice, pesoSign);
                printf("Your total after discount is: %.2f %s\n", dtotalPrice, pesoSign);

                // printing receipt :>
                printf("\nHere is your receipt, meow!:");
                printf("\n--------------------------------------------------------------------\n");
                printf("%-30s %20s %10s\n", "Product Name", "Price", "QTY");
                    for (int productIndex = 0; productIndex < productCount; productIndex++) {
                        printf("%-30s %20.2f %10d\n",
                               productName[productIndex],
                               productPrice[productIndex],
                               productQuantity[productIndex]);
                    }
                    printf("%-38s%14.2f\n", "\nTotal:", totalPrice);
                    printf("%-37s%14s\n",  "Your discount:", userSpecialClassification[classification_index]);
                    if (classification_index == 4) {
                        printf("%-37s%14.2f\n", "Total after discount:", totalPrice);
                    } else {
                        printf("%-37s%14.2f\n", "Total after discount:", dtotalPrice);
                    }
                    printf("\nHave a great day! Meow!\n");
                    printf("Thank you for using Cat Boss' Receipt Maker! (=^ o w o ^=)");
                    printf("\n--------------------------------------------------------------------\n");
                    return 0;
                    
            } else {
                printf("Invalid classification selected, meow! Please select again (=^ o x o ^=).\n");
                goto classification_input;
                }
    return 0;
}
