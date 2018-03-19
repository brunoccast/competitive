/*
ID: brunocc1
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void toBase(int number, int base, string& ref)
{
    if(!number)
    {
        ref = "";
        return;
    }

    int mod = number%base;
    toBase(number/base, base, ref);
    ref += "0123456789ABCDEFGHIJ"[mod];
}

bool isPal(const string& number)
{
    for(int i=0, j=number.length()-1; i<j; i++, j--)
        if(number[i] != number[j])
            return false;

    return true;
}

bool isValid(int number)
{
    string pal;
    int count = 0;

    for(int i=2; i<=10 && count<2; ++i)
    {
        toBase(number,i,pal);
        if(isPal(pal))
            count++;
    }

    return (count==2);
}

int main()
{
    fstream fin, fout;
    fin.open("dualpal.in", fstream::in);
    fout.open("dualpal.out", fstream::out);

    string istr;

    int N,S;
    fin >> N >> S;

    for(int i=S+1; N>0; ++i)
        if(isValid(i))
        {  
            toBase(i,10,istr);
            fout << istr << endl;
            N--;
        }
    
    fin.close();
    fout.close();

    return 0;
}