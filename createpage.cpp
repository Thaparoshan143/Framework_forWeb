#include"createpage.h"


namespace Roshan
{
    void NewPage::CreateNewPage(char* fName)
    {
        this->fptr=fopen(fName,"w");
        
    }

}