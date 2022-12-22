#include<iostream>
#include"Rstring.h"
#include"Rutility.h"

using namespace Roshan;

int main()
{
    FILE *fp;
    fp=fopen("test.txt","rb");

    int temp=searchStringFileFIndex(fp,"you");

    std::cout <<temp<<std::endl;

    std::cout <<"Hello there\n";
    fclose(fp);

    fp=fopen("test.txt","rb");

    appendStringFileAtIndex(fp,"this is appened",temp);

    fclose(fp);

    return 0;
}