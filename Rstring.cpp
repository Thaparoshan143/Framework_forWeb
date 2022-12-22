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
        UpdatePointerAndLength(s);
    }

    // Public Method
    int Rstring::GetLength()
    {
        return this->length;
    }

    void Rstring::SetString(char *s)
    {
        UpdatePointerAndLength(s);
    }

    void Rstring::PrintString()
    {
        printString(this->s);
    }



    // Helper Methods
    void Rstring::UpdatePointerAndLength(char *s)
    {
        int temp=getStringLength(s);
        AllocateAndAssign(s,this->s,temp);
        this->length=temp;
    }

    void AllocateAndAssign(char *s,char *d, int l)
    {
        d = getSAllocatedMemoryPointer(l+1);
        copyString(s,d,l);
    }


}