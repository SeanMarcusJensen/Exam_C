#include "MyList.h"

int main(void) {
    struct Product* head = {0};
    struct Product* tail = {0};

    if ( test() == 0 )  {
        printf("OK!");
        return OK;
    }
    else {
        printf("ERROR!");
    }

    return OK;
}