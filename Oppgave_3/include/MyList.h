#ifndef MYLIST_H
#define MYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK      0
#define ERROR   -1

typedef struct Product {
    struct Product *pstNext;
    struct Product *pstPrev;
    float fPrice;
    char *szName;
    int iQuantity;
} Product;

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
void receipt(struct Product *pstProduct);

void printAll(Product **pstHead);

#endif