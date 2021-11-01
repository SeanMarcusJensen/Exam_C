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
            // Declare Variables.
            char chCurrent, chPrev;
            char* szPair;
            int *piOcc = (int*) malloc(sizeof(int) * 25); // Count of alfabeth.
            int count = 0;
            // While File has chars.
            while((chCurrent = fgetc(pInputFile)) != EOF ) {
                // I want to skip all if the char is \n, else it will bring problems.
                if ( chCurrent == '\n') {
                    continue;
                }
                // adding Count to see when we have 2 chars to combine.
                count++;
                if ( count % 2 == 0 ) { // We GOT 2 chars.
                    // Sending in both chars to combine function. and then write it to file.
                    szPair = combineTwo(chPrev, chCurrent);
                    char chCharacter = hexToInt(szPair);
                    countOccorances(piOcc ,chCharacter);
                    fprintf(pOutputFile, "%c", chCharacter);
                } else {    // End if count % 2 == 0.
                    chPrev = chCurrent;
                }   // End else count % 2 == 0
            }   // End while getc(pInput);
            for ( int i = 0; i <= 25; i++ ) {
                printf("%c: %i\n", i + 65, piOcc[i]);
            }
            free(piOcc);
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
