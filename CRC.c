#include "CRC.h"

int getCRCRemainderOffset(int input, int offset, int polynomial) { // note: this function isn't available outside this file intentionally (makes the interface cleaner)
    int numBits = getNumBits(polynomial) - 1;
    int result = (input << numBits) + offset;
    int currentXOR = polynomial << (getNumBits(result) - numBits - 1);
    int XORShiftBits = (getNumBits(result) - numBits - 1);

    while (result >> numBits) {
        while (!((1 << (XORShiftBits + numBits)) & result)) {
            XORShiftBits--;
            currentXOR >>= 1;
        }
        result ^= currentXOR;
    }
    result = result % (1 << numBits);

    return result;
}
int getCRCRemainder(int input, int polynomial) {
    return getCRCRemainderOffset(input, 0, polynomial);
}
// return true if input is error-free
int checkCRC(int input, int checkVal, int polynomial) {
    return getCRCRemainderOffset(input, checkVal, polynomial) == 0;
}