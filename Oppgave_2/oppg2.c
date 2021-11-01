#include "ReadAndConvert.h"
#include "TestReadAndConvert.h"

int RunTests() {
    validateDataTest();
    combineCharsTest();
}

int main(void) {
    RunTests();
    
    FILE *pInputFile = fopen(INPUT_FILE, "r");
    if ( pInputFile ) {
        FILE *pOutputFile = fopen(OUTPUT_FILE, "w");
        if ( pOutputFile ) {
            char *szBuffer = (char*) malloc(sizeof(char) * 3);
            char current;
            char prev;
            char* pair;
            int count = 0;
            if ( szBuffer ) {
                while((current = fgetc(pInputFile)) != EOF ) {
                    if ( current == '\n') {
                        continue;
                    }
                    count++;
                    if ( count % 2 == 0 ) { // We GOT 2 chars.
                        pair = combineTwo(prev, current);
                        printf("%c", hexToInt(pair));

                    } else {
                        prev = current;
                    }
                }   // End while getc(pInput);
            } else {// End if szBuffer else
                perror("Error in Malloc szBuffer");
                return ERROR;
            }   // End else szBuffer;

            fclose(pOutputFile);
        } else { // End if pOutput
            perror("Error in opening Outputfile");
            return ERROR;
        }   // End else pOutput

        fclose(pInputFile);
    } else {    // End if pInput
        perror("Error in opening InputFile");
        return ERROR;
    }   // End else pInput

    return OK;
}
