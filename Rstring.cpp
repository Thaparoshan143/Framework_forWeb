#include"Rstring.h"

namespace Roshan
{
    Rstring::Rstring()
    {
        this->s=nullptr;
        this->length=0;
    }

    Rstring::Rstring(char* s)
    {
        this->SetString(s);
    }

    Rstring::~Rstring()
    {
        // free(this->s);
    }
    
    int Rstring::GetLength()
    {
        return this->length;
    }

    void Rstring::PrintString()
    {
        printString(this->s);
    }

    char* Rstring::GetString()
    {
        char* temp=getSAllocatedMemoryPointer(this->length);
        copyString(this->s,temp,this->length);
        return temp;
    }
    
    void Rstring::SetString(char* s)
    {
        this->length=getStringLength(s);
        this->s=getSAllocatedMemoryPointer(this->length);
        copyString(s,this->s,this->length);
    }

    // Helper methods in class

    
    // operator overloader
    char* Rstring::operator = (char* s)
    {
        free(this->s);
        this->SetString(s);
        return this->s;
    }

    Rstring Rstring::operator = (Rstring rhs)
    {
        free(this->s);
        this->SetString(rhs.GetString());
        return *this;
    }

}