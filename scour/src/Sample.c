#include <stdlib.h>
#define MACRO_MALLOC malloc(1024)

int main(void){
    char* testCharPtr;
    void (*mallocPtr) (size_t) = malloc(1024);
    testCharPtr = (char *) (*malloc)(1024); 
    void (*mallocPtr2)() = &malloc;
    if(testCharPtr = (char *) malloc(1024)){}
    return 0;
}
