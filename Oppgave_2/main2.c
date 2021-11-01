#include <stdio.h>
#include <stdlib.h>

#define ENCODED_FILE "./encrypted.md"
#define DECODED_FILE "./decoded.md"

#define ERROR -1
#define OK 0


int main(void) {
    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;
    pInputFile = fopen(ENCODED_FILE, "r");
    pOutputFile = fopen(DECODED_FILE, "w");
    if ( pInputFile ) {
        if( pOutputFile ) {
            while( !feof(pInputFile) ) {
                char *szBuffer = (char*) malloc(sizeof(char) * 2 );
                if ( szBuffer ) {
                    if ( fread(szBuffer, sizeof(char), 2, pInputFile) ) {
                        printf("%s - ", szBuffer);
                        int coded = strtol(szBuffer, 0, 16);
                        printf("%c\n", coded);
                    }
                    free(szBuffer);
                } else {
                    perror("FAILED to malloc buffer");
                    return ERROR;
                }
            }
            fclose(pOutputFile);
        } else {
            perror("ERROR in opening outputfile");
            return ERROR;
        }
        fclose(pInputFile);
    } else {
        perror("ERROR in opening inputfile");
        return ERROR;
    }

    return OK;
}