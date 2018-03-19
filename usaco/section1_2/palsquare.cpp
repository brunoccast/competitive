/*
ID: brunocc1
PROG: palsquare
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>

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

/*
FIRST VERSION

string toBase(int number, int base)
{
    string index("0123456789ABCDEFGHIJ");
    string result;

    while(number)
    {
        result.push_back(index.at(number%base));
        number /= base;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}
*/

bool isPal(const string& number)
{
    for(int i=0, j=number.length()-1; i<j; i++, j--)
        if(number[i] != number[j])
            return false;

    return true;
}

int main()
{
    fstream fin, fout;
    fin.open("palsquare.in", fstream::in);
    fout.open("palsquare.out", fstream::out);

    string istr, squarestr;

    int B;
    fin >> B;

    for(int i=1; i<=300; ++i)
    {
        toBase(i*i,B,squarestr);

        if(isPal(squarestr))
        {  
            toBase(i,B,istr);
            fout << istr << " " << squarestr << endl;
        }
    }
    
    fin.close();
    fout.close();

    return 0;
}