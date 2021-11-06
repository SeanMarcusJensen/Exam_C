#include "httpReq.h"

/*
Date: Thu, 09 Dec 2004 12:07:48 GMT
Server: IBM_CICS_Transaction_Server/3.1.0(zOS)
Content-type: image/jpg
*/

MYHTTP* ProcessHttpHeader(char *pszHttp) {
    char* pszPtr;
    MYHTTP* pHttp = (MYHTTP*)malloc(sizeof(MYHTTP));

    printf("1\n");

    // if failed to malloc, we return null.
    if (!pHttp) {
        return NULL;
    }
    printf("2\n");


    // if we malloced right. we set all data to 0.
    memset(pHttp, 0, sizeof(MYHTTP));
    printf("3\n");


    // Setting pHttp->Code to int.
    // THINK MISTAKE IS HERE. NR 1.
    pHttp->iHttpCode = atoi(pszHttp + strlen("HTTP/1.x "));
    printf("4\n");

    printf("CODE: %i\n", pHttp->iHttpCode);
    printf("SUCCESS : %d\n", pHttp->bIsSuccess);

    if (pHttp->iHttpCode = 200) {
        printf("5\n");

        pHttp->bIsSuccess = true;
    }
    printf("SUCCESS : %d\n", pHttp->bIsSuccess);

    printf("6\n");


    pszPtr = strstr(pszHttp, "Server");
    printf("7\n");
    printf("pszPtr = %s\n", pszPtr);
    // ERROR AT WHERE THE string parse.
    if (pszPtr) {
        printf("8\n");
        pszPtr += 6; // server length = 6, skip to where data is.
        printf("9\n");

        while (!isalpha(pszPtr[0]))pszPtr++; // as long as pointer is not symbol.
        printf("10\n");
        printf(" WE GOT SERVER: %s 11111\n", pszPtr);

        // SEGMENT FAULT HERE!
        strchr(pszPtr, '\n')[0] = 0;
        printf("11\n");

        strcpy(pHttp->szServer, pszPtr);
        printf("12\n");
        
        pszPtr[strlen(pHttp->szServer)] = '\n';
        printf("13\n");

        printf("END OF IF - 1: pszPtr = %s\n", pszPtr);
    }

    pszPtr = strstr(pszHttp, "Content-Type");
    if (pszPtr) {
        pszPtr += 12; while (!isalpha(pszPtr[0]))pszPtr++;
        strchr(pszPtr, '\n')[0] = 0;
        strncpy(pHttp->szContentType, pszPtr, 15);
        pszPtr[strlen(pHttp->szContentType)] = '\n';
    }

    pszPtr = strstr(pszHttp, "Content-Length");
    if (pszPtr) {
        pszPtr += 14;
        while (!isdigit(pszPtr[0])) pszPtr++;
        pHttp->iContentLength = atoi(pszHttp);
    }

    return pHttp;
}