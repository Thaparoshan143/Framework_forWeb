#pragma once

#include<iostream>

namespace Roshan
{
    int getStringLength(char *s);

    int searchStringFIndex(char *s,char *sf);

    int searchStringHelper(char *s, char *sf, char *os, char *osf);

    void printString(char *s);

    int searchStringFileFIndex(FILE *fp,char *s);

    bool compareString(char *s1, char *s2);

    void appendStringFileAtIndex(FILE *fp,char *s,int fIndex);

    void copyFileContent(FILE *s, FILE *d);


}