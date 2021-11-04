#include "MyList.h"

int main(void) {
    Product *pstHead = NULL;
    int choice = 0;
    insert(&pstHead, createProduct("Melkerull", 20.9, 10));
    insert(&pstHead, createProduct("Dorull", 20.9, 10));
    insert(&pstHead, createProduct("Leskedrikk", 20.9, 10));
    printf("Printing\n");
    printAll(&pstHead);
    
    printf("**** EKSAMEN LIST ****\n");
        while(choice != 9 ) {
        char *szNameOfProduct = (char*) malloc(sizeof(char) * 50);
        if ( szNameOfProduct ) { 
            float fPrice;
            int iQuantity;
            printf("1: Nytt produkt\n2: \033[31mAngre\033[0m ( Slett det siste produktet ).\n3: \033[31mSlett\033[0m alle etter navn.\n4: Summer total pris av alle varer.\n5. Print ut en kvittering.\n9. \033[31mEXIT\033[0m\n");
            printf("Skriv inn ditt valg: ");
            Product *temp = (Product*) malloc(sizeof(Product));
            if ( scanf("%d", &choice) != 0 ) {
                
                switch (choice)
                {
                case 1:

                    printf("Vi trenger å lage produktet ditt. hjelp oss\n");

                    printf("Navn: ");
                    scanf("%s", szNameOfProduct);

                    printf("Pris: ");
                    scanf("%f", &temp->fPrice);

                    printf("Antall: ");
                    scanf("%i", &temp->iQuantity);
                    temp->szName = szNameOfProduct;
                    insert(&pstHead, temp);
                    
                    break;
                case 2:
                    deleteLast(&pstHead);
                    break;
                case 3:
                    printf("*****************************************\n");
                    printf("Hvilket produkt vil du slette?\nNavn: ");
                    scanf("%s", szNameOfProduct);
                    deleteAllByName(&pstHead, szNameOfProduct);
                    printf("*****************************************\n");
                    free(szNameOfProduct);
                    break;
                case 4:
                    printf("Pris av alle varene: %f", getPriceOfAllProduct(&pstHead));
                    break;
                case 5:
                    printAll(&pstHead);
                    break;
                default:
                    printf("Exiting!\n");
                    break;
                }
                printf("\n\n\n");
            }
        } else {
            perror("Failed Malloc");
            return ERROR;
        }
    }

    // FREE ALL

    while( pstHead != NULL) {
        pstHead = pstHead->pstNext;
        free(pstHead->pstPrev);
    }
    free(pstHead);
    
    return OK;
}