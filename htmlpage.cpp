
#include"htmlpage.h"

namespace Roshan
{
    BasicHTMLPage::BasicHTMLPage()
    {
        pName="newpage";
        // this->name="newHTMLPage.html";
    }

    BasicHTMLPage::BasicHTMLPage(Rstring pn)
    {
        this->pName=pn;
    }

    BasicHTMLPage::BasicHTMLPage(char* pn)
    {
        this->pName.SetString(pn);
    }
}