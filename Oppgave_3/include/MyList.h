#ifndef MYLIST_H
#define MYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK      0
#define ERROR   -1

/*
Du skal lage funksjoner som utfører følgende operasjoner på listen:
• Legge til et element i slutten av listen
• Slette siste element i listen (en «angreknapp»)
• Sletter alle elementer i listen som har et gitt VARENAVN (sendes som
parameter til funksjonen)
• Summerer sammen total pris for varene i listen (husk å ta hensyn til antall)
• Printer ut en kvittering (i konsoll vinduet)
*/

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

// test
int test();
/*

Product *pstHead;

// Makes a Product, all linkes are null. Need to be set by insert.
struct Product* createProduct();

// Insert at end of list.
int insert();

// Deletes the tail of list.
int deleteLast();

// Deletes All Products with name...?
int deleteAllByName(char *szName);

// Returns the sum of total price for products in list.
float getPriceOfAllProduct();

// Simply prints out the Receipt. # Product info.
void receipt();


*/
#endif