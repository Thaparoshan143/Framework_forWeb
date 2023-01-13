#include"Rutility.h"

namespace Roshan
{
    int getStringLength(char *s)
    {
        char temp=*s;
        int count=0;
        while(temp!='\0')
        {
            count++;
            temp=*(s+count);
        }
        return count;
    }

    int searchStringFIndex(char *s, char *sf)
    {
        char *sT=s, *sfT=sf;
        int fIndex=0;
        int sSize=getStringLength(s);
        int sfSize=getStringLength(sf);

        fIndex=searchStringHelper(sT,sfT,sT,sfT);
        
        return fIndex-1;
    }

    int searchStringHelper(char *s, char *sf,char *os,char *osf)
    {
        if(*s!='\0' && *sf!='\0')
        {
            if(*s==*sf)
            {
                std::cout<<sf<<std::endl;
                std::cout<<s<<std::endl;
                return searchStringHelper((s+1),(sf+1),os,osf);
            }
            else
            return 1 + searchStringHelper((os+1),osf,(os+1),osf);
        }
        else
        return 0;
    }

    void printString(char *s)
    {
        char temp = *s;
        while(temp!='\0')
        {
            std::cout << temp ;
            temp = *(++s);
        }
        std::cout << std::endl;
    }


    int searchStringFileFIndex(FILE *fp,char* fName, char* s)
    {
        fp=fopen(fName,"w");
        char temp=fgetc(fp);
        int indexCount=1;
        int sLength=getStringLength(s);
        char *tempPtr=(char*) malloc(sizeof(char)*sLength+1);
        while(temp!=EOF)
        {
            if(temp==*(s))
            {
                std::cout<<"File has : "<<temp<<", first char is : "<<*s<<std::endl;        
                fgets(tempPtr,sLength,fp);
                if(*(tempPtr+sLength-2)==*(s+sLength-1))
                {
                    if(compareString(s+1,tempPtr))
                    {
                        std::cout<<"All letter matched\n";
                        fclose(fp);
                        return indexCount;
                    }
                }
                else
                {
                    fseek(fp,-sLength+1,SEEK_CUR);
                }
            }

            indexCount++;
            temp=fgetc(fp);
        }
        fclose(fp);
        return -1;
    }

    bool compareString(char *s1, char *s2)
    {
        int tempSLength=getStringLength(s1);
        for(int i=0;i<tempSLength;i++)
        {
            if(*(s1+i)!=*(s2+i))
            {
                return false;
            }
        }
        return true;
    }

    void appendStringFileAtIndex(FILE *fp,char* fn, char *s,int fIndex)
    {
        FILE *fPtrTemp;

        fPtrTemp=fopen("temp.txt","w");
        copyFileContent(fp,fPtrTemp,fn,"temp.txt");
        fclose(fp);
        fp=fopen(fn,"w");
        int indexCounter=1;
        int sLength=getStringLength(s);
        char tempChar=fgetc(fPtrTemp);
        while(tempChar!=EOF)
        {
            if(indexCounter==fIndex)
            {
                for(int i=0;i<sLength;i++)
                {
                    fputc(*(s+i),fp);
                }
            }
            else
            {
                fputc(tempChar,fp);
                tempChar=fgetc(fPtrTemp);
            }
            indexCounter++;
        }
    }

    void copyFileContent(FILE *s, FILE *d,char* sn, char* dn)
    {
        s=fopen(sn,"r");
        d=fopen(dn,"w");
        char temp=fgetc(s);
        while(temp!=EOF)
        {
            fputc(temp,d);
            temp=fgetc(s);
        }
        fclose(s);
        fclose(d);
    }

    void copyString(char *s,char *d,int l)
    {
        for(int i=0;i<l;i++)
        {
            *(d+i)=*(s+i);
        }
    }


    char* getSAllocatedMemoryPointer(int n)
    {
        return new char[sizeof(char)*n];
        // return (char*) malloc(sizeof(char)*n);
    }

    void copyStringFT(char *s, char *d, int ds, int de)
    {
        for(int i=ds;i<de;i++)
        {
            *(d+i)=*(s++);
        }
    }

    char* toString(int n)
    {
        int l=getDigitLength(n);
        char* temp=getSAllocatedMemoryPointer(l+1);
        numToArrParser(n,temp,l);
        arrConstAddChar(temp,l,ZERO_START);

        //string terminator for safety  explicit//
        temp[l]='\0';
        return temp;
    }

    int getDigitLength(int n)
    {
        int count=0;
        while(n>0)
        {
            n/=10;
            count++;
        }
        return count;
    }

    void numToArrParser(int n, char* a, int aSize)
    {
        for(int i=aSize-1;i>=0;i--)
        {
            *(a+aSize-1-i)=getNumDigitOfIndex(n,i);
        }
    }

    int getNumDigitOfIndex(int n, int in)
    {
        int temp;
        for(int i=0;i<in;i++)
        {
            n/=10;
        }
        temp=n%10;
        return temp;
    }  

    void arrConstAddChar(char *a, int aSize, int c)
    {
        for(int i=0;i<aSize;i++)
        {
            *(a+i)+=c;
        }
    } 

}
