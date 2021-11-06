#include "httpReq.h"

int main(void){
    char *httpHeader = "Date: Thu, 09 Dec 2004 12:07:48 GMT\nServer: IBM_CICS_Transaction_Server/3.1.0(zOS)\nContent-type: image/jpg";
    ProcessHttpHeader(httpHeader);
    printf("%i", atoi(httpHeader + strlen("HTTP/1.x ")));
    return 0;
}