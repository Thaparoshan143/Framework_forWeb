#pragma once

#include"iostream"
#include"Rutility.h"

namespace Roshan
{
    class Rstring
    {
        char *s;
        int length;

        void AllocateAndAssign(char *s,char *d,int l);
        void UpdatePointerAndLength(char *s);

        public:

        Rstring();
        Rstring(char *s);
        int GetLength();
        void SetString(char *s);
        void PrintString();

    };
}