#pragma once

#include"iostream"
#include"Rutility.h"

namespace Roshan
{
    class Rstring
    {
        char *s;
        int length;

        Rstring();
        Rstring(char *s);

        void AllocateAndAssign(char *s,char *d,int l);
        void UpdatePointerAndLength(char *s);

        public:
        int GetLength();
        void SetString(char *s);
        void PrintString();

    };
}