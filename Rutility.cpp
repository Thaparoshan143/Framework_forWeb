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
        
        return fIndex;
    }

    int searchStringHelper(char *s, char *sf,char *os,char *osf)
    {
        if(*s!='\0' && *sf!='\0')
        {
            if(*s==*sf)
            {
                // std::cout<<sf<<std::endl;
                // std::cout<<s<<std::endl;
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

    int searchStringFIndexFromFile(char* fn, char* s)
    {
        FILE* fp=fopen(fn,"r");
        int index=0;
        int sLength=getStringLength(s);
        char temp=getc(fp);
        char *stemp;
        while(temp!=EOF)
        {
            index++;
            if(temp==s[0])
            {
                stemp=getFileString(sLength-1,fp);
                if(compareString(s+1,stemp))
                {
                    return index;
                }
                else
                {
                    fseek(fp,-(sLength-1),SEEK_CUR);
                }
            }
            temp=fgetc(fp);
        }
        fclose(fp);
        return -1;
    }

    char* getFileString(int n, FILE *fp)
    {
        char *temp=getSAllocatedMemoryPointer(n+1);
        for(int i=0;i<n;i++)
        {
            *(temp+i)=getc(fp);
        }
        *(temp+n)='\0';
        return temp;
    }

    bool compareString(char *s1, char *s2)
    {
        int tempS1Length=getStringLength(s1);
        int tempS2Length=getStringLength(s2);
        if(tempS1Length==tempS2Length)
        {
            for(int i=0;i<tempS1Length;i++)
            {
                if(*(s1+i)!=*(s2+i))
                {
                    return false;
                }
            }
            return true; 
        }
        else
        return false;

    }

    //method to see and update //
    void appendStringInFileAt(char* fn, char *s,int fIndex)
    {
        char tempright[]="tempright.txt";
        char templeft[]="templeft.txt";

        // Reading from source and spliting in index
        char tempChar=' ';
        FILE *temp=fopen(templeft,"w");
        FILE *source=fopen(fn,"r");

        for(int i=0;i<fIndex && tempChar!=EOF;i++)
        {
            tempChar=fgetc(source);
            fputc(tempChar,temp);
        }
        fclose(temp);
        temp=fopen(tempright,"w");
        while(tempChar!=EOF)
        {
            tempChar=fgetc(source);
            fputc(tempChar,temp);
        }
        fclose(temp);
        fclose(source);

        //Reading from splitter and combining in source//
        copyFileContent(templeft,fn);
        appendStringInFile(fn,s);
        appendFileContent(tempright,fn);
    }

    void appendStringInFileAfter(char* fn,char *s,char *aft)
    {
        int aIndex=searchStringFIndexFromFile(fn,aft);
        int aftLength=getStringLength(aft);
        // Reusing the above method for now
        appendStringInFileAt(fn,s,aIndex+aftLength-1);
    }

    void appendStringInFile(char* fn,char* s)
    {
        FILE* fptr=fopen(fn,"a");
        fprintf(fptr,"%s",s);
        fclose(fptr);
    }

    void appendFileContent(char* sn, char * dn)
    {
        FILE* fptrs=fopen(sn,"r");
        FILE* fptrd=fopen(dn,"a");
        char temp=getc(fptrs);
        while(temp!=EOF)
        {
            putc(temp,fptrd);
            temp=getc(fptrs);
        }
        fclose(fptrs);
        fclose(fptrd);
    }

    void copyFileContent(char* sn, char* dn)
    {
        FILE *s=fopen(sn,"r");
        FILE* d=fopen(dn,"w");
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


    char* getSAllocatedMemoryPointer(int s)
    {
        return new char[sizeof(char)*s];
        // if c style needed
        // return (char*) malloc(sizeof(char)*n);
    }

    char* reallocStringBlock(char* p,int s)
    {
        int pSize=getStringLength(p);
        char* temp=new char[sizeof(char)*s];
        if(pSize<s)
        {
            copyString(p,temp,pSize);    
        }
        else
        {
            copyString(p,temp,s-1);
            temp[s]='\0';
        }
        delete(p);
        return temp;
    }

    void appendStringFT(char *s, char *d, int ds, int de)
    {
        for(int i=ds;i<de;i++)
        {
            *(d+i)=*(s++);
        }
        *(d+de)='\0';
    }

    void appendString(char *s, char *d)
    {
        int sLength=getStringLength(s);
        int dLength=getStringLength(d);
        for(int i=0;i<dLength;i++)
        {
            *(s+i+sLength)=*(d+i);
        }
        *(s+sLength+dLength)='\0';
    }

    char* appendStringR(char *s, char *d)
    {
        int sLength=getStringLength(s);
        int dLength=getStringLength(d);
        char* tempS=getSAllocatedMemoryPointer(sLength+dLength);
        for(int i=0;i<sLength;i++)
        {
            *(tempS+i)=*(s+i);
        }
        for(int i=0;i<dLength;i++)
        {
            *(tempS+i+sLength)=*(d+i);
        }
        *(s+sLength+dLength)='\0';
        return tempS;
    }
    
    char* sliceString(char* s, int i, int n)
    {
        char* temp=getSAllocatedMemoryPointer(n);
        copyString(s+i,temp,n);
        return temp;
    }

    char* toString(int n)
    {
        int l=getDigitLength(n);
        char* temp=getSAllocatedMemoryPointer(l);
        numDigitToArr(n,temp,l-1);

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

    void numDigitToArr(int n, char* a, int aSize)
    {
        int rem=0;
        while(aSize>=0)
        {
            rem=n%10;
            n=n/10;
            a[aSize]=rem+ZERO_START;
            aSize--;
        }
    }

    int getNumDigitOfIndex(int n, int in)
    {
        int temp=0;
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

    void printInt(char *t, int n)
    {
        std::cout<< t << " : " << n <<std::endl;
    }

    //need minor update to work flawlessley
    char* getStringFromFile(FILE* fp,int sl)
    {
        char* tempPtr=getSAllocatedMemoryPointer(sl+1);
        char temp;
        for(int i=0;i<sl;i++)
        {
            *(tempPtr+i)=fgetc(fp);
        }
        *(tempPtr+sl)='\0';
        return tempPtr;
    }
}
