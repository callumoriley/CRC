#include "CRC.h"

int getNumBits(int input) {
    int numBits = 0;
    while (input > 0) {
        input >>= 1;
        numBits++;
    }
    return numBits;
}
void printBinary(int input) {
    int compare = 1 << (getNumBits(input) - 1);
    while (compare > 0) {
        printf("%d", (input & compare) > 0);
        compare >>= 1;
    }
    puts("");
}