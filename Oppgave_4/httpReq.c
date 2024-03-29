#include "httpReq.h"

MYHTTP* ProcessHttpHeader(char *pszHttp) {
    char* pszPtr;
    MYHTTP* pHttp = (MYHTTP*)malloc(sizeof(MYHTTP));
    if (!pHttp) return NULL;
    memset(pHttp, 0, sizeof(MYHTTP));
    
    pHttp->iHttpCode = atoi(pszHttp + strlen("HTTP/1.x "));
    
    if (pHttp->iHttpCode == 200) { // Mistake nr 2? == not =.
        pHttp->bIsSuccess = true;
    }

    pszPtr = strstr(pszHttp, "Server");
    if (pszPtr) {
        pszPtr += 6;
        while (!isalpha(pszPtr[0]))pszPtr++;
        strchr(pszPtr, '\n')[0] = 0;
        strcpy(pHttp->szServer, pszPtr);
        pszPtr[strlen(pHttp->szServer)] = '\n';
    }

    pszPtr = strstr(pszHttp, "Content-Type");
    if (pszPtr) {
        pszPtr += 12;
        while (!isalpha(pszPtr[0]))pszPtr++;
        strchr(pszPtr, '\n')[0] = 0;
        strncpy(pHttp->szContentType, pszPtr, 15);
        pszPtr[strlen(pHttp->szContentType)] = '\n';
    }

    pszPtr = strstr(pszHttp, "Content-Length");
    if (pszPtr) {
        pszPtr += 14; 
        while (!isdigit(pszPtr[0])) pszPtr++;
        pHttp->iContentLength = atoi(pszPtr); // Mistake nr 3? - atoi pszPtr.
    }

    pszPtr = strstr(pszHttp, "Last-Modified");
    if ( pszPtr ) {
        pszPtr += 13;
        while(!isalpha(pszPtr[0])) pszPtr++;
        strncpy(pHttp->szLastModified, pszPtr, 31);
    }

    return pHttp;
}