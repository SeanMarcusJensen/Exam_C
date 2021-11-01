#include "TestReadAndConvert.h"

void validateDataTest() {
    char A = 'A';
    char not = '/';
    char a = 'a';
    char num = '9';

    int validate = 0;

    for ( int i = 0; i < 256; i++ ) {
        if ( i < 48 && validateChar(i) != -1 ) {
            printf("Error on less than 48\n");
            validate = 1;
        } 
        if ( i >= 48 && i <= 57 && validateChar(i) == -1 ) {
            printf("Error on numbers\n");
            validate = 1;
        } 
        if ( i > 57 && i < 65 && validateChar(i) != -1 ) {
            printf("Error on symbols 57 - 65\n");
            validate = 1;
        }
        if ( i >= 65 && i <= 90 && validateChar(i) == -1 ) {
            printf("Error on CAP letters\n");
            validate = 1;
        } 
        if ( i > 97 && i <= 122 && validateChar(i) == -1 ) {
            printf("Error on LOWER letters\n");
            validate = 1;
        }
        if ( i > 122 && validateChar(i) != -1 ) {
            printf("Error on 122 - 256\n");
            validate = 1;
        }
    }

    if ( validate == 0 ) {
        printf("SUCCESS on Validating Data Test\n");
    }
    else {
        printf("ERROR, There is something wrong\n");
    }

}

void combineCharsTest() {
    int validate = 0;

    if ( strcmp(combineTwo(97, 65), "aA") != 0) {
        validate = 1;
    }

    if ( strcmp(combineTwo(72, 105), "Hi") != 0) {
        validate = 1;
    }

    if ( strcmp(combineTwo(57, 105), "9i") != 0) {
        validate = 1;
    }

    if ( validate == 0 ) {
        printf("SUCCESS on Combine!\n");
    } else {
        printf("Error on combine\n");
    }
}