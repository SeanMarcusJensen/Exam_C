#include "ReadAndConvert.h"

int hexToInt(char *szHex) {
    return strtol(szHex, 0, 16);
}

char* combineTwo(char szFirst, char szSecond) {
    char *combined = (char*) malloc(sizeof(char) * 3);
    if ( combined ) {
       *combined = szFirst;
       *(combined + 1) = szSecond;
       *(combined + 2) = '\0';
    }
    return combined;
}

// This will take in one array, and char. convert it to Lowercase and then adding count.
void countOccorances(int *ppiSet, char szCharacter);

int validateChar(char szChar) {  // a-zA-Z0-9'
    if ( szChar >= 48 && szChar <= 57 ) // Checking for numbers.
        return OK;
    else if ( szChar >= 65 && szChar <= 90 ) // Checking for uppercase letters.
        return OK;
    else if ( szChar >= 97 && szChar <= 122) // Checking for lowecase letters.
        return OK;

    return ERROR;
}