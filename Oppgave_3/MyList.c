#include "MyList.h"

// Simply prints out the Receipt. # Product info.
void receipt(Product *pstProduct) {
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
    if ( *pstHead ) {
        Product *temp = *pstHead;
        receipt(temp);
        while( (temp = temp->pstNext) != NULL ) {
            receipt(temp);
        }
    } else {
        perror("No Head.\n");
    }
}

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
int insert(Product **pstHead, Product *pstProduct) {
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
int deleteLast(Product **pstHead) {
    
    if ( pstHead ) {
        Product *temp = (*pstHead);

        while ( temp->pstNext != NULL ) {
            temp = temp->pstNext;
        }
        
        if ( temp->pstPrev ) {
            temp->pstPrev->pstNext = NULL;
        }

        free(temp);

        return OK;
    } else {
        perror("ERROR: NO HEAD TO FOLLOW.");
        return ERROR;
    }
}

// Deletes All Products with name...? NEED TO FREE.
int deleteAllByName(Product **pstHead, char *szName) {
    if ( (*pstHead )) {
        
        Product *current = *pstHead;
        Product *next;

        // Looping thu aslong as current is not null.
        while (current) {
            // we want do check if the name is the same as we want to delete.
            if ( strcmp(current->szName, szName) == 0 ) {
                // Setting next to be the next link.
                // We want this because we will move links around.
                next = current->pstNext;
                
                // if the current is the same as head, we want to make head next link.
                if ( current == (*pstHead ) )
                    (*pstHead) = current->pstNext;

                // if the next link is available, we set the nextlinks prev to be the
                // Link before us.
                if ( current->pstNext != NULL )
                    current->pstNext->pstPrev = current->pstPrev;

                // if we have a link to prev. we can set the next prev link to
                // point to the next.
                if ( current->pstPrev != NULL ) 
                    current->pstPrev->pstNext = current->pstNext;

                free(current);

                current = next;
            
            // if its not the same. we move on to the next link.
            } else {
                current = current->pstNext;
            }
        }
        return OK;
    } else {
        perror("Listy Entry you gave is not valid\n");
        return ERROR;
    }
}

// Returns the sum of total price for products in list.
float getPriceOfAllProduct(Product **pstHead) {
    float sum = 0;
    if ( pstHead ) {
        Product *temp = *pstHead;
        while(temp != NULL ) {
            sum += temp->fPrice * temp->iQuantity;
            temp = temp->pstNext;
        }
    }
    return sum;
}