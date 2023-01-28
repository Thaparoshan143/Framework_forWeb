#pragma once

#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

namespace Roshan
{
    class Rfile
    {
        FILE *fPtr;
        Rstring fileName;

        public:
        Rfile();
        Rfile(FILE* fp);
        Rfile(Rstring fn);

        char* GetFileName();
        FILE* GetFilePtr();
        void SetFileName(char *fn);
        void SetExtFilePtr(FILE *fp);

        void WriteContentInFile(char *s);
        void AppendFile(char *s);
        void CopyFileTo(char *dfn);
        void InsertAfter(Rstring s,Rstring a);
        void InsertAfter(char *s, char *a);
        
        int GetStringIndex(char *s);

        private:
        void OpenMode(char *m);
    };
}