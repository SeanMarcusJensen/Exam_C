#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define OUTPUT_FILE "./output.md"

static pthread_mutex_t mutexWrite = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condWrite = PTHREAD_COND_INITIALIZER;

int iEXIT = 0;

char *getSubString(char *szMessage, int start, int step) {
    char *subtext = malloc(sizeof(char) * step );

    strncpy(subtext, &szMessage[start], step);

    return subtext;
}

void *writeToFile(void *szMessageToWrite) {

    while( iEXIT != 1 ) {
        if ( szMessageToWrite ) {
            FILE *pFile = fopen(OUTPUT_FILE, "a");
            int iThreadActive;

            if ( !pFile ) {
                    perror("Could not open file!\n");
                    return NULL;
            }
            fprintf(pFile, "%s\n", (char*) szMessageToWrite);

            fclose(pFile);
            sleep(1);
        } 
        pthread_mutex_trylock(&mutexWrite);
        pthread_cond_wait(&condWrite, &mutexWrite);
    }

    return NULL;
}

int main(void) {
    // A cry for help...
    char *temp = (char*) malloc(sizeof(char) * 100);
    char *szMessage = (char*) malloc(sizeof(char) * 10 );

    if ( !szMessage) {
        perror("malloc fail!");
        return 1;
    }

    // Init Thread, Mutex & cond.
    pthread_t stWorkThread;
    pthread_mutex_init(&mutexWrite, NULL);
    pthread_cond_init(&condWrite, NULL);
    
    // Starting Thread.
    printf("Creating Thread\n");
    pthread_create(&stWorkThread, NULL, writeToFile, szMessage);

    int iChoice = 0;
    int iScanf;
    int i;

    while( iChoice != 3 ) {
        // Printing menu.
        printf("----------------------------\n");
        printf("--- Time to choose. ---\n");
        printf("1: \033[32mContinue\033[0m\n");
        printf("3: \033[31mExit\033[0m\n");
        printf("Choice: ");

        // User input.
        iScanf = scanf("%i%*c", &iChoice);

        switch (iChoice)
        {
        case 1:
            // Should send message to thread, that it can begin again.
            printf("Please enter sentence: ");
            iScanf = scanf("%[^\n]", temp);
            strncpy(szMessage, temp, 10);
            pthread_cond_signal(&condWrite);
            while(strlen(temp)) {
                for (i = 0; i < 10; i++) temp++;
                strncpy(szMessage, temp, 10);
                pthread_cond_signal(&condWrite);
            }

            // PARSE TEXT AND RETURN 10 chars. which i will send to thread.

            break;

        case 3:
            printf("Exiting...\n");
            iEXIT = 1;
            pthread_cond_signal(&condWrite);
            break;

        default:
            printf("Try again\n");
            break;
        }
    }

    printf("Joining Thread\n");
    pthread_join(stWorkThread, NULL);
    free(szMessage);
    printf("Its Joined..\n");
    pthread_mutex_destroy(&mutexWrite);
    pthread_cond_destroy(&condWrite);

    return 0;
}