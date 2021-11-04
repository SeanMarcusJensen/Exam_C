#include "MyList.h"

int main(void) {
    

    if ( test() == 0 )  {
        printf("OK!");
        return OK;
    }
    else {
        printf("ERROR!");
    }

    int choice = 0;
    char szNameOfProduct[50];
    printf("**** EKSAMEN LIST ****\n");

        while(choice != 9 ) {
            printf("1: Insert new Item\n2: Angre ( Slett det siste produktet ).\n3: Slett alle etter navn.\n4: Summer total pris av alle varer.\n5. Print ut en kvittering.\n9. EXIT\n");
            printf("Skriv inn dit valg: ");
            if ( scanf("%d", &choice) != 0 ) {
            
            switch (choice)
            {
            case 1:
                // insert();
                break;
            case 2:
                // deleteLast();
                break;
            case 3:
                /*printf("*****************************************\n");
                printf("Hvilket produkt vil du slette?\nNavn: ");
                scanf("%s", szNameOfProduct);
                deleteAllByName(szNameOfProduct);
                memset(szNameOfProduct, 0, sizeof(char) * 50); 
                printf("*****************************************\n");
                */
                break;
            case 4:
                //getPriceOfAllProduct();
                break;
            case 5:
                //receipt();
                break;

            default:
                printf("Exiting!\n");
                break;
            }
            printf("\n\n\n");
        }
    }

    /* FREE ALL

    while( head->pstNext != NULL) {
        head = head->pstNext;
        free(head->pstPrev);
    }
    free(head);
    */
    return OK;
}