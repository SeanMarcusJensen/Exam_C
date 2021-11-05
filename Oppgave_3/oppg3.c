#include "MyList.h"

int main(void) {
    Product *pstHead = NULL;
    int choice = 0;
    char szNameOfProduct[50];
    float fPrice;
    int iQuantity;

    printf("**** EKSAMEN LIST ****\n");

    while(choice != 9 ) {

        printf("1: Nytt produkt\n");
        printf("2: \033[31mAngre\033[0m ( Slett det siste produktet ).\n");
        printf("3: \033[31mSlett\033[0m alle etter navn.\n");
        printf("4: Summer total pris av alle varer.\n");
        printf("5. Print ut en kvittering.\n");
        printf("9. \033[31mEXIT\033[0m\n");
        printf("Skriv inn ditt valg: ");
            
        if ( scanf("%d", &choice) != 0 ) {
            switch (choice)
            {
            case 1:

                printf("Vi trenger å lage produktet ditt. hjelp oss\n");

                printf("Navn: ");
                scanf("%s", szNameOfProduct);

                printf("Pris: ");
                scanf("%f", &fPrice);

                printf("Antall: ");
                scanf("%i", &iQuantity);

                insert(&pstHead, createProduct(szNameOfProduct, fPrice, iQuantity));
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
                break;
            case 4:
                printf("Pris av alle varene: kr %f,-", getPriceOfAllProduct(&pstHead));
                break;
            case 5:
                printf("-----------------------------------------\n");
                printAll(&pstHead);
                break;
            default:
                printf("Exiting!\n");
                break;
            }
            printf("\n\n\n");
        }
    }

    // FREE ALL
    Product *temp = NULL;
    while(pstHead != NULL ) {
        temp = pstHead->pstNext;
        free(pstHead->szName);
        free(pstHead);
        pstHead = temp;
    }
    free(pstHead->szName);
    free(temp);
    
    return OK;
}