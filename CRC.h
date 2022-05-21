#include <stdio.h>
#include <windows.h>

int getCRCRemainder(int input, int polynomial);
int checkCRC(int input, int checkVal, int polynomial);
int getNumBits(int input);
void printBinary(int input);