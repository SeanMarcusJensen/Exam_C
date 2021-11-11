#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define OUTPUT_FILE "./output.md"

pthread_mutex_t mutexWrite = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condWrite = PTHREAD_COND_INITIALIZER;
pthread_cond_t condMain = PTHREAD_COND_INITIALIZER;

typedef struct _ {
    char szData[11];
    int iQuit;
} Work;

void *writeToFile(void *szMessageToWrite) {

    Work *stWordData = (Work*) szMessageToWrite;

    while( stWordData->iQuit ) {
        pthread_mutex_lock(&mutexWrite);
        pthread_cond_wait(&condWrite, &mutexWrite);

        if ( strlen(szMessageToWrite) > 0 && strncmp(stWordData->szData, "quit", 4) ) {
            FILE *pFile = fopen(OUTPUT_FILE, "a");
            if ( !pFile ) {
                    perror("Could not open file!\n");
                    return NULL;
            }
            fprintf(pFile, "%s", stWordData->szData);
            fclose(pFile);
        }
        
        pthread_cond_signal(&condMain);
        pthread_mutex_unlock(&mutexWrite);
    }

    pthread_exit(0);
    return NULL;
}

int main(void) {
    // A cry for help...
    Work *stWorkData = malloc(sizeof(Work));
    stWorkData->iQuit = 1;
    char chInputValid;

    if ( !stWorkData ) {
        perror("malloc fail!\n");
        return 1;
    }

    // Init Thread, Mutex & cond.
    pthread_t stWorkThread;
    pthread_mutex_init(&mutexWrite, NULL);
    pthread_cond_init(&condWrite, NULL);
    pthread_cond_init(&condMain, NULL);
    pthread_create(&stWorkThread, NULL, writeToFile, stWorkData->szData);

    // Looping thru till text == quit. then we set iExit to 1, and exit.
    printf("Write a sentence or type \"\033[31mquit\033[0m\" to quit.\n");  
    while( strncmp(stWorkData->szData, "quit", 4) ) {

        if (fgets(stWorkData->szData, 11, stdin) && strlen(stWorkData->szData) > 0) {
            pthread_cond_signal(&condWrite);
            pthread_cond_wait(&condMain, &mutexWrite);
        }
    }

    stWorkData->iQuit = 0;  // FOR EXIT..
    pthread_cond_signal(&condWrite);
    pthread_mutex_unlock(&mutexWrite);
    pthread_join(stWorkThread, NULL);
    pthread_mutex_destroy(&mutexWrite);
    pthread_cond_destroy(&condWrite);
    pthread_cond_destroy(&condMain);
    free(stWorkData);

    return 0;
}