#include <stdio.h>

#include "HexToAsciiReader.h"

int main(void) {

    FILE *pInputFile = NULL;
    pInputFile = fopen(ENCRYPTED_FILE, "r");
    FILE *pOutputFile = NULL;
    pOutputFile = fopen("./decoded.md", "w");

    // Checking if the file actually returned something.
    // if it doesn't, throw error and exit.
    if ( pInputFile != NULL ) {
        if ( pOutputFile != NULL ) {
            // I only want to read 2 bytes at the time.
            // Since it is Ascii hex, i know there is Lengsth % 2 == 0. 
            // As long as the file is not empty.
            while ( !feof(pInputFile) ) {
                unsigned char *szBuffer = (char *) malloc(sizeof(char) * 2);
                if ( szBuffer != NULL ) {
                    // Reading 2 bytes from the file, and only continuing on success!
                    if ( fread(szBuffer, sizeof(char), 2, pInputFile) != 0 ) {
                        printf("%c", hexToIntConverter(szBuffer));
                        strncpy(szBuffer, '\0', sizeof(char));
                        fprintf(pOutputFile, "%c", hexToIntConverter(szBuffer));
                        free(szBuffer);
                    }   // End if - Read File
                } /* End Malloc */ else {
                    perror("FAILED to malloc space to buffer\n");
                }
            }   // End While - !feof(pFile);
            fclose(pOutputFile);
        } /* End Validating pInputFile */ else {
            perror("ERROR in opening desired Output file\n");
            exit(EXIT_FAILURE);
        }   // End ELSE OUTPUTFILE
        // Closing file after use.
        fclose(pInputFile);
    } /*End Validating pOutput file. */ else {
        perror("ERROR in opening desired file\n");
        exit(EXIT_FAILURE);
    }   // END ELSE INPUTFILE.

    return OK;
}