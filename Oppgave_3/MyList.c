#include "MyList.h"

// Makes a Product, all linkes are null. Need to be set by insert.
struct Product* createProduct(char *szName, float fPrice, int iQuantity) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    if ( newProduct ) {
        newProduct->fPrice = fPrice;
        newProduct->iQuantity = iQuantity;
        newProduct->szName = szName;
        newProduct->pstNext = NULL;
        newProduct->pstPrev = NULL;
        return newProduct;
    } else {
        perror("Failed to make new Product!\n");
        return NULL;
    }
}

// Insert at end of list.
int insert(struct Product **pstHead, struct Product *pstProduct) {
    if ( (*pstHead) == NULL ) {
        (*pstHead) = pstProduct;
        return OK;
    } else {
        Product *temp = (*pstHead);
        while( temp->pstNext != NULL ) {
            temp = temp->pstNext;
        }
        temp->pstNext = pstProduct;
        pstProduct->pstPrev = temp;
        return OK;
    }
    return ERROR;
}

// Deletes the tail of list.
int deleteLast(struct Product **pstHead) {
    if ( pstHead ){
        Product *temp = (*pstHead);
        while ( (temp = temp->pstNext) != NULL );
        temp = NULL;
        free(temp);
        return OK;
    } else {
        return ERROR;
    }
}

// Deletes All Products with name...? NEED TO FREE.
int deleteAllByName(struct Product **pstHead, char *szName);

// Returns the sum of total price for products in list.
float getPriceOfAllProduct(struct Product **pstHead);
// Simply prints out the Receipt. # Product info.
void receipt(struct Product *pstProduct) {
    printf("-----------------------------------------\n");
    printf("Name:\t\t%s\n", pstProduct->szName);
    printf("Price:\t\tkr %.2f,-\n", pstProduct->fPrice);
    printf("Quantity:\t%03i stk\n", pstProduct->iQuantity);
    
    if ( pstProduct->pstPrev ) {
        printf("Prev:\t\t%s\n", pstProduct->pstPrev->szName);
    } else {
        printf("Prev:\t\tNULL\n");
    }
    if ( pstProduct->pstNext ) {
        printf("Next:\t\t%s\n", pstProduct->pstNext->szName);
    } else {
        printf("Next:\t\tNULL\n");
    }
    printf("-----------------------------------------\n");
}

void printAll(Product **pstHead) {
    Product *temp = *pstHead;
    receipt(temp);
    while( (temp = temp->pstNext) != NULL ) {
        receipt(temp);
    }
}

int test() {
    Product *head = NULL;
    insert(&head, createProduct("Tannbørste", 37.59, 55));
    insert(&head, createProduct("Tannkrem", 22.9, 2));
    insert(&head, createProduct("Apelort", 22.9, 2));

    printAll(&head);

    deleteLast(&head);

    printAll(&head);

    return ERROR;
}
/*


// Makes a Product, all linkes are null. Need to be set by insert.
struct Product* createProduct() {
    Product *newProduct = (Product*) malloc(sizeof(Product));
    if ( newProduct ) {
        char szProductName[50];
        float fPrice;
        int iQuantity;

        printf("Navn på produkt: ");
        scanf("%s", szProductName);
        printf("Pris på varen: ");
        scanf("%f", &fPrice);
        printf("Hvor mange har du: ");
        scanf("%d", &iQuantity);

        newProduct->szName = szProductName;
        newProduct->fPrice = fPrice;
        newProduct->iQuantity = iQuantity;
        newProduct->pstNext = NULL;
        newProduct->pstPrev = NULL;

    } else {
        printf("Ute av drift!\n");
        return NULL;
    }
}

// Insert at end of list.
int insert(){
    Product *newOne = createProduct();
    pstHead = newOne;
    /*
    if ( !pstHead ) {
        pstHead = newOne;
    } else {
        Product *temp = pstHead;
        while( !temp->pstNext ) {
            temp = temp->pstNext;
        }
        temp->pstNext = newOne;
        newOne->pstPrev = temp;
    }
    return OK;
}

// Deletes the tail of list.
int deleteLast() {
    return OK;
}

// Deletes All Products with name...?
int deleteAllByName(char *szName) {
    return OK;
}

// Returns the sum of total price for products in list.
float getPriceOfAllProduct() {
    return 0.1f;
}

// Simply prints out the Receipt. # Product info.
void receipt() {
        printf("-----------------------------------------\n");
        printf("Name:\t\t%s\n", pstHead->szName);
        printf("Price:\t\tkr %.2f,-\n", pstHead->fPrice);
        printf("Quantity:\t%03i stk\n", pstHead->iQuantity);
        if ( pstHead->pstNext ) {
            printf("Next:\t\t%s\n", pstHead->pstNext->szName);
        } else {
            printf("Next:\t\tNULL\n");
        }
        if ( pstHead->pstPrev ) {
            printf("Prev:\t\t%s\n", pstHead->pstPrev->szName);
        } else {
            printf("Prev:\t\tNULL\n");
        }
        printf("-----------------------------------------\n");
}
*/