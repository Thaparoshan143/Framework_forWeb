#pragma once

#include"Rstring.h"
#include<iostream>

namespace Roshan
{
    class NewPage
    {
        private:
        Rstring pageName;

        public:
        NewPage();
        NewPage(char* pn);
        NewPage(Rstring pn);
    };
}