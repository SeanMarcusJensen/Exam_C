#include "CharProcess.h"

static int validateChar(char chChar) {  // a-zA-Z0-9
    return ( chChar >= 65 && chChar <= 90 || chChar >= 97 && chChar <= 122) ? OK : ERROR;
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
    (validateChar(chCharacter) == OK) ? piSet[toupper(chCharacter) % 65]++ : 0;
}

