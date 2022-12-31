#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

using namespace Roshan;

int main()
{
    Rstring temp;

    printString(temp.GetString());
    int l=temp.GetLength();
    temp.PrintString();
    std::cout << "The length of string is  : " << l << std::endl;

    return 0;
}