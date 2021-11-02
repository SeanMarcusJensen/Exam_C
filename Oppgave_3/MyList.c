#include "MyList.h"

// Makes a Product, all linkes are null. Need to be set by insert.
struct Product* createProduct(char *szName, float fPrice, int iQuantity);

// Insert at end of list.
int insert(struct Product **pstHead, struct Product *pstProduct);

// Deletes the tail of list.
int deleteLast(struct Product **pstHead);

// Deletes All Products with name...?
int deleteAllByName(struct Product **pstHead, char *szName);

// Returns the sum of total price for products in list.
float getPriceOfAllProduct(struct Product **pstHead);

// Simply prints out the Receipt. # Product info.
void receipt(struct Product *pstProduct) {
    printf("%s {\n", pstProduct->szName);
    printf("\tPrice: kr %.2f,-\n", pstProduct->fPrice);
    printf("\tQuantity: %03i stk\n", pstProduct->iQuantity);
    if ( pstProduct->pstNext ) {
        printf("\tNext: %s\n", pstProduct->pstNext->szName);
    } else {
        printf("\tNext: NULL\n");
    }
    if ( pstProduct->pstPrev ) {
        printf("\tPrev: %s\n", pstProduct->pstPrev->szName);
    } else {
        printf("\tPrev: NULL\n");
    }
    printf("}\n\n");

    printf("-----------------------------------------\n");
    printf("Name:\t\t%s\n", pstProduct->szName);
    printf("Price:\t\tkr %.2f,-\n", pstProduct->fPrice);
    printf("Quantity:\t%03i stk\n", pstProduct->iQuantity);
    if ( pstProduct->pstNext ) {
        printf("Next:\t\t%s\n", pstProduct->pstNext->szName);
    } else {
        printf("Next:\t\tNULL\n");
    }
    if ( pstProduct->pstPrev ) {
        printf("Prev:\t\t%s\n", pstProduct->pstPrev->szName);
    } else {
        printf("Prev:\t\tNULL\n");
    }
    printf("-----------------------------------------\n");
}

int test() {
    Product *head = (Product*) malloc(sizeof(Product));
    if ( head ) {
        head->szName = "Melkerull";
        head->fPrice = 21.99;
        head->iQuantity = 22;
        head->pstNext = NULL;
        head->pstPrev = NULL;        

        receipt(head);
        free(head);
        return OK;
    }

    return ERROR;
}