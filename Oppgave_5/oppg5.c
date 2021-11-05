#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OUTPUT_FILE "./output.md"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char *getSubString(char *szMessage, int start, int end) {
    char *subtext = malloc(sizeof(char) * end );

    strncpy(subtext, &szMessage[start], end);

    return subtext;
}

void *writeToFile(void *szMessage) {
    pthread_mutex_lock(&mutex);

    FILE *pOutput = fopen(OUTPUT_FILE, "a");
    if ( pOutput ) {
        if ( szMessage ) {
            for ( int i = 0; i < strlen((char*) szMessage); i+=10) {

                if ( i + 10 > strlen((char*) szMessage) ) {
                    char* final =
                        getSubString((char*) szMessage, 0 + i,
                        strlen((char*) szMessage) - (i - 10));
                    fprintf(pOutput, "%s", final);
                    free(final);
                    break;
                }

                char* final = getSubString((char*) szMessage, 0 + i, 10);
                fprintf(pOutput, "%s", final);
                free(final);
            }

            fprintf(pOutput, "\n");
        }
        fclose(pOutput);
    } else {
        perror("Could not open file\n");
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);
}


int main(void) {

    pthread_t stThread;

    char msg[100];
    int choice = 0;

    printf("Welcome to \"You write in Terminal, i Write file\"\n");
    while( choice != 3 ) {
        
        printf("1: Write Word\n");
        printf("3: \033[31mEXIT\033[0m\n");
        printf("Your choice: ");
        scanf("%i%*c", &choice);

        switch (choice)
        {
        case 1:
            printf("Write a sentence for me on the next line:\n");
            scanf("%[^\n]", msg);
            pthread_create(&stThread, NULL, writeToFile, msg);
            break;
        case 2: 
            printf("You pressed me\n");
            break;
        case 3:
            printf("Nice to play with you\n");
            exit(EXIT_SUCCESS);
        default:
            break;
        }
        pthread_join(stThread, NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}