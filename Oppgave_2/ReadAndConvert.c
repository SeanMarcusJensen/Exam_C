#include "ReadAndConvert.h"

int hexToInt(char *szHex) {
    return strtol(szHex, 0, 16);
}

char* combineTwo(char chFirst, char chSecond) {
    char *combined = (char*) malloc(sizeof(char) * 3);
    if ( combined ) {
       *combined = chFirst;
       *(combined + 1) = chSecond;
       *(combined + 2) = '\0';
    }
    return combined;
}

// This will take in one array, and char. convert it to Lowercase and then adding count.
void countOccorances(int *piSet, char chCharacter) {
    // checking if its actually characters we have, NO space, signs or numbers.
    if ( validateChar(chCharacter) == OK ) {
        chCharacter = toupper(chCharacter); // converting it to uppercase
        piSet[chCharacter % 65]++;  // Taking % 65 to make uppercase into 0 - 25.
    }
}

int validateChar(char chChar) {  // a-zA-Z0-9
    if ( chChar >= 65 && chChar <= 90 ) // Checking for uppercase letters.
        return OK;
    else if ( chChar >= 97 && chChar <= 122) // Checking for lowecase letters.
        return OK;

    return ERROR;
}