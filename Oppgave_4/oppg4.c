#include "httpReq.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define iPORT 80

int main(void){
    struct sockaddr_in saAddr = {0};
    MYHTTP *http;
    char szResvBuffer[BUFFER_SIZE];
    char request[1024];

    int fdSocket;
    fdSocket = socket(AF_INET, SOCK_STREAM, 0);

    if ( fdSocket < 0 ) {
        perror("ERROR in opening socket..\n");
    }

    saAddr.sin_family = AF_INET;
    saAddr.sin_port = htons(iPORT);
    if ( inet_pton(AF_INET, "77.111.240.75", &saAddr.sin_addr) <= 0 ) {
        printf("Error in opening..\n");
    }
    
    if (connect(fdSocket, (struct sockaddr*) &saAddr, sizeof(saAddr)) < 0 ) {
        printf("ERROR in connect\n");
        exit(1);
    }

    int iWrite;
    sprintf(request, "GET /pg3401/test.html HTTP/1.1\r\nHost: www.eastwillsecurity.com\r\nAccept: text/html\r\n\r\n");
    printf("%s", request);
    iWrite = write(fdSocket, request, strlen(request));
    bzero(szResvBuffer, BUFFER_SIZE);

    while(read(fdSocket, szResvBuffer, BUFFER_SIZE - 1) > 0) {
        fprintf(stderr, "%s", szResvBuffer);
        http = ProcessHttpHeader(szResvBuffer);
        bzero(szResvBuffer, BUFFER_SIZE);
    }
    
    printf("\n\nSuccess: \t%s\n", http->iHttpCode ? "True" : "False");
    printf("Code: \t\t%i\n", http->iHttpCode);
    printf("Server: \t%s\n", http->szServer);
    printf("Content-Length: %i\n", http->iContentLength);
    printf("Content-Type: \t%s\n", http->szContentType);
    printf("Last-Modified: \t%s\n", http->szLastModified);

    close(fdSocket);
    free(http);

    return 0;
}