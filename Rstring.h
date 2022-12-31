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

        int GetLength();
        void PrintString();
        char* GetString();

        // operator overloader

        char* operator = (char* s);
        Rstring operator = (Rstring rhs);

        // Helpers

        private:
        void AllocateAssignString(char* s, char* d);
        void HelperAssign(char* s, char* d);

    };
}