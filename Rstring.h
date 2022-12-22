#pragma once

#include"iostream"

namespace Roshan
{
    class Rstring
    {
       char *s;
       int length;

       Rstring();
       Rstring(char *s);

       int FindPointerLength(char *p);


    };
}