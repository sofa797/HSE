#define TRACKBAKING 0

#if TRACKBAKING == 1
#include "backtraking.h"

#elif TRACKBAKING == 0
#include "notbracking.h"

#endif

int main() {
    bt();

    return 0;
}