#pragma once

#include"iostream"
#include"Rutility.h"

namespace Roshan
{
    class Rstring
    {
        private:
        char* s;
        int length;

        public:
        Rstring();
        Rstring(char* s);
        ~Rstring();

        int GetLength();
        void PrintString();
        char* GetString();
        void SetString(char* s);

        // operator overloader
        char* operator + (char* s);
        Rstring operator + (Rstring rhs);
        char* operator = (char* s);
        Rstring operator = (Rstring rhs);

        // Helpers


    };
}