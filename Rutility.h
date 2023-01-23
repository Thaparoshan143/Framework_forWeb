#pragma once

#include<iostream>

#define ZERO_START 48

namespace Roshan
{
    int getStringLength(char *s);

    int searchStringFIndex(char *s,char *sf);

    int searchStringHelper(char *s, char *sf, char *os, char *osf);

    void printString(char *s);

    int searchStringFileFIndex(char* fn,char *s);

    bool compareString(char *s1, char *s2);

    // void appendStringFileAtIndex(FILE *fp,char *s,int fIndex);

    void copyFileContent(char* sn, char* dn);
    
    void copyString(char *s,char *d, int l);
    
    char* getSAllocatedMemoryPointer(int s);

    char* reallocStringBlock(char* p,int s);

    void appendStringFT(char *s, char *d, int ds, int de);

    char* sliceString(char* s, int i, int n);

    char* toString(int n);

    int getDigitLength(int n);

    void numDigitToArr(int n, char *a, int aSize);

    int getNumDigitOfIndex(int n, int in);

    void arrConstAddChar(char* a, int aSize, int c);
}