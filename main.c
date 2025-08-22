#include "test.h"
#include "ui.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
    run_tests();
    run();
#ifdef _WIN32 // Windows dependent leak detection
    if (_CrtDumpMemoryLeaks() == 1)
        printf("Memory leak");
    else
        printf("ok");
#endif
    return 0;
}