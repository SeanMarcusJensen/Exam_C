#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OUTPUT_FILE "./output.md"

static pthread_mutex_t mutexWrite = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condWrite = PTHREAD_COND_INITIALIZER;

int iStartWork = 0;

void *writeToFile(void *szMessageToWrite) {

    FILE *pFile = fopen(OUTPUT_FILE, "a");
    int iThreadActive;

    if ( !pFile ) {
        perror("Could not open file!\n");
        return NULL;
    }

    // Want the thread to alway do work as long as program is live.
    while (1) {
        // Need to lock thread for others.
        printf("Locking Thread!\n");
        fputs((char*) szMessageToWrite, pFile);
        iThreadActive = pthread_mutex_lock(&mutexWrite);

        // if locked, stay here...
        while(!iStartWork) {
            printf("Thread Blocked!\n");
            iThreadActive = pthread_cond_wait(&condWrite, &mutexWrite);
            printf("Not locked any more!\n");
        } // We got approved, we start work again.

        // Write to file
        printf("Thread Awake, we can now do some work!\n");
        fprintf(pFile, "We have it going\n");
        printf("Should have written to file now...\n");

        // Set iStartWork back to 0
        // Which will wait for user to press 1. 
        iStartWork = 0;
    }

    fclose(pFile);
    return NULL;
}

int main(void) {
    char szMessage[10] = "Please!!!";
    // Init Thread, Mutex & cond.
    pthread_t stWorkThread;
    pthread_mutex_init(&mutexWrite, NULL);
    pthread_cond_init(&condWrite, NULL);
    
    // Starting Thread.
    printf("Creating Thread\n");
    pthread_create(&stWorkThread, NULL, writeToFile, szMessage);

    int choice = 0;

    while( choice != 3 ) {
        // Printing menu.
        printf("----------------------------\n");
        printf("--- Time to choose. ---\n");
        printf("1: \033[32mContinue\033[0m\n");
        printf("3: \033[31mExit\033[0m\n");
        printf("Choice: ");

        // User input.
        scanf("%i%*c", &choice);

        switch (choice)
        {
        case 1:
            // Should send message to thread, that it can begin again.
            printf("StartWork active!\n");
            pthread_cond_signal(&condWrite);
            iStartWork = 1;
            break;

        case 3:
            printf("Exiting...\n");
            pthread_cond_signal(&condWrite);

            iStartWork = 1;
            break;

        default:
            printf("Try again\n");
            break;
        }
    }

    printf("Joining Thread\n");
    pthread_join(stWorkThread, NULL);
    printf("Its Joined..\n");
    pthread_mutex_destroy(&mutexWrite);
    pthread_cond_destroy(&condWrite);

    return 0;
}