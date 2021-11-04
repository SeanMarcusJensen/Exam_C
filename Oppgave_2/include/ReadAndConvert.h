#ifndef READ_AND_CONVERT_H
#define READ_AND_CONVERT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define OK      0
#define ERROR   -1

#define INPUT_FILE "./encrypted.md"
#define OUTPUT_FILE "./decoded.md"

char* combineTwo(char chFirst, char chSecond);
void countOccorances(int *piSet, char szCharacter);
int validateChar(char chChar);  // a-zA-Z

#endif