/*
USER: brunocc1
LANG: C++11
PROG: crypt1
*/

#include <iostream>
#include <fstream>

using namespace std;

int validNumbers[10];

/*
 check if all digits of num are valid (must be set in validNumbers[])
 and test if the number of digits is the desired one
 */
bool testNum(int num, int digitCount)
{
    int nDigits = 0;

    while(num)
    {
        if( !validNumbers[num%10] )
            return false;

        nDigits++;
        num /= 10;
    }

    return nDigits == digitCount;
}

/* 
 check if an abc*de combination is a valid cryptarithm 
 */
bool valid(int abc, int de)
{
    if( !testNum(abc,3) || !testNum(de,2) || !testNum(abc*de,4) )
        return false;

    while(de)
    {
        if( !testNum(abc*(de%10),3) )
            return false;
        
        de /= 10;
    }
    
    return true;
}

int main()
{
    fstream fin, fout;
    int N, nSols;

    fin.open("crypt1.in", fstream::in);
    fout.open("crypt1.out", fstream::out);

    fin >> N;
    for(int i=0; i<N; ++i)
    {
        int num; fin >> num;
        validNumbers[num] = 1;
    }

    nSols = 0;
    for(int abc=111; abc<=999; ++abc)
        for(int de=11; de<=99; ++de)
        {
            if( valid(abc,de) )
            {
                //cout << "found solution:\nabc=" << abc << "\nde=" << de << endl;
                nSols++;
            }
        }
    
    fout << nSols << endl;

    fin.close();
    fout.close();

    return 0;
}