#include "HexToAsciiReader.h"

int hexToIntConverter(char *szLine) {
    return strtol(szLine, 0, 16);
}

unsigned char hexToTextConverter(char *szLine) {
    char chCode;
    sprintf(&chCode, "%c", hexToIntConverter(szLine));
    return chCode;
}

void numberOfOccurances(FILE *pTextFile) {
    if ( pTextFile != NULL ) {
        int **occurances;
        
        fclose(pTextFile);
    } else {
        perror("ERROR in opening file\n");
        return NULL;
    }
}