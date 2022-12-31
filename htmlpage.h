#pragma once

#include"Rstring.h"


namespace Roshan
{
    class BasicHTMLPage
    {
        private:
        Rstring pName;

        // char name[100];use string template after making

        BasicHTMLPage();
        BasicHTMLPage(char* pn);
        BasicHTMLPage(Rstring pn);
    };

}