#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

using namespace Roshan;

int main()
{   
    appendStringInFileAfter("temphtml.html","black","background-color:");

    appendStringInFileAfter("temphtml.html","white",";color:");
}