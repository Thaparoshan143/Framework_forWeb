#pragma once

#include<iostream>

#define ZERO_START 48

namespace Roshan
{
    int getStringLength(char *s);

    int searchStringFIndex(char *s,char *sf);

    int searchStringHelper(char *s, char *sf, char *os, char *osf);

    void printString(char *s);

    int searchStringFIndexFromFile(char* fn,char *s);

    char* getFileString(int n, FILE *fp);

    bool compareString(char *s1, char *s2);

    // Optimization required for heavy loads// current state too slow for some task//

    void appendStringInFileAt(char* fn,char *s,int fIndex);

    void appendStringInFileAfter(char* fn,char *s,char *aft);

    //Opt//

    void appendStringInFile(char* fn,char* s);

    void copyFileContent(char* sn, char* dn);

    void appendFileContent(char* sn, char * dn);
    
    void copyString(char *s,char *d, int l);
    
    char* getSAllocatedMemoryPointer(int s);

    char* reallocStringBlock(char* p,int s);

    void appendStringFT(char *s, char *d, int ds, int de);

    void appendString(char *s, char *d);

    char* appendStringR(char *s, char *d);

    char* sliceString(char* s, int i, int n);

    char* toString(int n);

    int getDigitLength(int n);

    void numDigitToArr(int n, char *a, int aSize);

    int getNumDigitOfIndex(int n, int in);

    void arrConstAddChar(char* a, int aSize, int c);

    void printInt(char *t, int n);

    char* getStringFromFile(FILE* fp,int sl);
}