#include"Rfile.h"

namespace Roshan
{
    Rfile::Rfile()
    {
        this->fPtr=nullptr;
    }

    Rfile::Rfile(FILE* fp)
    {
        this->fPtr=fp;
    }

    Rfile::Rfile(Rstring fn)
    {
        this->fileName=fn;
    }

    char* Rfile::GetFileName()
    {
        return this->fileName.GetString();
    }

    FILE* Rfile::GetFilePtr()
    {
        return this->fPtr;
    }

    void Rfile::SetFileName(char *fn)
    {
        this->fileName=fn;
    }

    void Rfile::SetExtFilePtr(FILE *fp)
    {
        this->fPtr=fp;
    }

    void Rfile::WriteContentInFile(char *s)
    {
        OpenMode("w");
        if(this->fPtr==nullptr)
        {
            std::cout << "Object not pointed to file" << std::endl;
        }
        else
        {
            fprintf(this->fPtr,"%s",s);
        }
        fclose(this->fPtr);
    }

    void Rfile::AppendFile(char *s)
    {
        OpenMode("a");
        fprintf(fPtr,"%s",s);
        fclose(this->fPtr);
    }

    void Rfile::CopyFileTo(char *dfn)
    {
        copyFileContent(this->fileName.GetString(),dfn);
    }

    void Rfile::InsertAfter(Rstring s,Rstring a)
    {
        appendStringInFileAfter(this->fileName.GetString(),s.GetString(),a.GetString());
    }

    void Rfile::InsertAfter(char *s, char *aft)
    {
        appendStringInFileAfter(this->fileName.GetString(),s,aft);
    }

    int Rfile::GetStringIndex(char *s)
    {
        return searchStringFileFIndex(this->fileName.GetString(),s);
    }


    //Helper method
    void Rfile::OpenMode(char *m)
    {
        this->fPtr=fopen(this->fileName.GetString(),m);
    }


}