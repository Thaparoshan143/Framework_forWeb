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
        // Clear the pointer used, but not working free don't know why?
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

    int Rstring::ToInt()
    {
        int temp;
        int val=0;
        for(int i=0;i<this->length;i++)
        {
            temp=this->s[i];
            temp=temp-48;
            val=val*10+temp;
        }
        return val;
    }

    // Helper methods in class

    
    // operator overloader
    char* Rstring::operator = (char* s)
    {
        free(this->s);
        this->SetString(s);
        return this->s;
    }

    Rstring Rstring::operator = (Rstring &rhs)
    {
        free(this->s);
        this->SetString(rhs.GetString());
        return *this;
    }

    Rstring Rstring::operator + (Rstring &rhs)
    {
        int tl=this->GetLength() + getStringLength(rhs.GetString());
        Rstring stemp;
        char *temp=getSAllocatedMemoryPointer(tl);
        copyString(this->s,temp,this->length);
        appendStringFT(rhs.GetString(),temp,this->length,tl);
        stemp=temp;
        return stemp;
    }

    char* Rstring::operator + (char* s)
    {
        int tl=this->GetLength() + getStringLength(s);
        char *temp=getSAllocatedMemoryPointer(tl);
        copyString(this->s,temp,this->length);
        appendStringFT(s,temp,this->length,tl);
        return temp;
    }

  

}