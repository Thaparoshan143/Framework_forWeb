#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

using namespace Roshan;

int main()
{
    Rstring temp;
    int fl=temp.GetLength();

    temp="This is the second assignment construct";
    int l=temp.GetLength();
    std::cout << "The length of string is  : " << fl <<"," << l<< std::endl;

    return 0;
}