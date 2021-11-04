#ifndef CHAR_PROCESS_H
#define CHAR_PROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define OK      0
#define ERROR   -1

#define INPUT_FILE "./encoded.md"
#define OUTPUT_FILE "./decoded.md"

char* combineTwo(char chFirst, char chSecond);
void countOccorances(int *piSet, char szCharacter);

#endif