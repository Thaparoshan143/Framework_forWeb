#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

using namespace Roshan;

int main()
{
    Rstring s1("one"),s2(" two");
    Rstring sum=s1+s2;
    sum.PrintString();
    return 0;

}