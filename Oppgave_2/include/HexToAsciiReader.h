#ifndef HEXTOASCIIREADER_H
#define HEXTOASCIIREADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK      0
#define ERROR   -1

#define ENCRYPTED_FILE "./encrypted.md"
#define DECODED_FILE "./decoded.md"

int hexToIntConverter(char *szLine);
unsigned char hexToTextConverter(char *szLine);
char *combineChars(char chA, char chB);

#endif