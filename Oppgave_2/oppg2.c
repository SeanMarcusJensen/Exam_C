#include "CharProcess.h"

int main(void) {
    FILE *pInputFile = fopen(INPUT_FILE, "r");
    if ( pInputFile ) {
        FILE *pOutputFile = fopen(OUTPUT_FILE, "w");
        if ( pOutputFile ) {
            // Declare Variables.
            char chCurrent, chPrev;
            char *szPair;
            int count = 0;
            int *piOcc = (int*) malloc(sizeof(int) * 25); // Count of alfabeth.
            if ( piOcc) {
                // While filePointer is not at EOF.
                while((chCurrent = fgetc(pInputFile)) != EOF ) {
                    // I want to skip all if the char is \n, else it will bring problems.
                    if ( chCurrent == '\n') continue;
                    
                    // adding Count to see when we have 2 chars to combine.
                    count++;
                    if ( count % 2 == 0 ) { // We GOT 2 chars.
                        // Sending in both chars to combine function. and then write it to file.
                        szPair = combineTwo(chPrev, chCurrent);
                        
                        countOccorances(piOcc , (int) strtol(szPair, 0, 16)); // Sending 
                        fprintf(pOutputFile, "%c", (int) strtol(szPair, 0, 16));
                        free(szPair);
                    } else {    // End if count % 2 == 0.
                        chPrev = chCurrent;
                    }   // End else count % 2 == 0
                }   // End while getc(pInput);

                // Printing out the output of all chars in the file.
                printf("Character Count found in file:\n");
                for ( int i = 0; i <= 25; i++) printf("%c, %i\n", i + 65, piOcc[i]);
                free(piOcc);
            } else {  // End if piOcc malloc
                perror("Error in malloc piOcc");
                return ERROR;
            } // End else Malloc piOcc
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
