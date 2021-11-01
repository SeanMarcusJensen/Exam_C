#ifndef READ_AND_CONVERT_H
#define READ_AND_CONVERT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK      0
#define ERROR   -1

#define INPUT_FILE "./encrypted.md"
#define OUTPUT_FILE "./decoded.md"

char* combineTwo(char szFirst, char szSecond);
int hexToInt(char *szHex);
// This will take in one array, and char. convert it to Lowercase and then adding count.
void countOccorances(int *ppiSet, char szCharacter);
int validateChar(char szChar);  // a-zA-Z0-9

#endif