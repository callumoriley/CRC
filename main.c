/*
CRC remainder and checking program for an arbitrary polynomial length written in C
Based on this Wikipedia article: https://en.wikipedia.org/wiki/Cyclic_redundancy_check (verify.py is pulled straight from the article to ensure that the C program is working properly)
*/

#include "CRC.h"

int main(void) {
/*     int input = 0b11010011101100;
    int polynomial = 0b1011; */

    int input = 0b100101011;
    int polynomial = 0b110101;

    int result = getCRCRemainder(input, polynomial);

    printBinary(result);
    printf("%d\n", result);

    printf("%d\n", checkCRC(input, result, polynomial));

    int numsVerified = 0;

    for (int i = 0; i < 512; i++) {
        if (checkCRC(i, result, polynomial)) {
            printBinary(i);
            numsVerified++;
        }
    }

    printf("%d\n", numsVerified);

    return 0;
}