#ifndef HTTPREQ_H
#define HTTPREQ_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _MYHTTP {
    int iHttpCode;
    int iContentLength;
    bool bIsSuccess;
    char szServer[16];
    char szContentType[16];
    char szLastModified[32];
} MYHTTP;

MYHTTP* ProcessHttpHeader(char *pszHttp);


#endif