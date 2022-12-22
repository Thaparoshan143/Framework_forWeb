#include"Rstring.h"


namespace Roshan
{
    Rstring::Rstring()
    {
        this->s=nullptr;
        this->length=0;
    }

    Rstring::Rstring(char *s)
    {
        int temp=FindPointerLength(s);
        this->s= (char*) malloc(sizeof(char)*temp+1);
    }

    int Rstring::FindPointerLength(char *p)
    {
        
    }
}