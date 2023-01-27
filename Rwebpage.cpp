#include"Rwebpage.h"

namespace Roshan
{
    NewPage::NewPage()
    {
        this->pageName="NewPage";
    }

    NewPage::NewPage(char* pn)
    {
        this->pageName=pn;
    }

    NewPage::NewPage(Rstring pn)
    {
        this->pageName=pn;
    }
}