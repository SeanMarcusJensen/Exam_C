#include <stdio.h>

#include "HexToAsciiReader.h"

int main(void) {

    FILE *pInputFile = NULL;
    FILE *pOutputFile = NULL;
    pInputFile = fopen(ENCRYPTED_FILE, "r");
    pOutputFile = fopen(DECODED_FILE, "w");

    // Checking if the file actually returned something.
    // if it doesn't, throw error and exit.
    if ( pInputFile ) {
        if ( pOutputFile ) {
            // I only want to read 2 bytes at the time.
            // Since it is Ascii hex, i know there is Lengsth % 2 == 0. 
            // As long as the file is not empty.
            while ( !feof(pInputFile) ) {
                unsigned char *szBuffer = (char *) malloc(sizeof(char) * 2);
                if ( szBuffer ) {
                    // Reading 2 bytes from the file, and only continuing on success!
                    if ( fread(szBuffer, sizeof(char), 2, pInputFile) != 0 ) {
                        printf("%c", hexToIntConverter(szBuffer));
                        fprintf(pOutputFile, "%c", hexToIntConverter(szBuffer));
                        free(szBuffer);
                    }   // End if - Read File
                } else {    /* End Malloc */
                    perror("FAILED to malloc space to buffer\n");
                }   // End else Malloc
            }   // End While - !feof(pFile);
            fclose(pOutputFile);
        } else {    /* End Validating pInputFile */ 
            perror("ERROR in opening desired Output file\n");
            exit(EXIT_FAILURE);
        }   // End ELSE OUTPUTFILE
        // Closing file after use.
        fclose(pInputFile);
    } else {    /*End Validating pOutput file. */ 
        perror("ERROR in opening desired file\n");
        exit(EXIT_FAILURE);
    }   // END ELSE INPUTFILE.

    return OK;
}