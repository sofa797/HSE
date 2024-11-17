#include <stdio.h>
#define SYSTEM 10

#if SYSTEM == 10
#include "calc10.h"

#elif SYSTEM == 2
#include "calc2.h"

#else
#include "er.h"

#endif

int main() {
    culc();


    return 0;
}