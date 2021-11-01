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
            char current = getc(pInputFile);
            char *szBuffer = (char*) malloc(sizeof(char) * 3);
            if ( szBuffer ) {
                while(current!= EOF ) {
                    if ( current == '\n' ) {
                        continue;
                    }


                    current = getc(pInputFile);
                }   // End while getc(pInput);
            } else {// End if szBuffer else
                perror("Error in opening Outputfile");
                return ERROR;
            }   // End else szBuffer;
            fclose(pOutputFile);
        } else { // End If pOutput
            perror("Error in opening Outputfile");
            return ERROR;
        }   // End else pOutput

        fclose(pInputFile);
    } else {    // End If pInput
        perror("Error in opening InputFile");
        return ERROR;
    }   // End else pInput

    return OK;
}
