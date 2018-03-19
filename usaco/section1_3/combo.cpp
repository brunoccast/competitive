/*
ID:brunocc1
LANG:C++11
TASK:combo
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool valid(int n1, int n2, int N)
{
    int diff = abs(n1-n2);
    return ( diff<=2 || N-diff<=2 );
}

bool close(int a1, int a2, int a3, int b1, int b2, int b3, int N)
{
    return ( valid(a1,b1,N) && valid(a2,b2,N) && valid(a3,b3,N) );
}

int main()
{
    int N, sol;
    int combo1[3], combo2[3];
    fstream fin, fout;

    fin.open("combo.in", fstream::in);
    fout.open("combo.out", fstream::out);

    fin >> N;
    fin >> combo1[0] >> combo1[1] >> combo1[2];
    fin >> combo2[0] >> combo2[1] >> combo2[2];

    sol = 0;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            for(int k=1; k<=N; ++k)
            {
                if( close(i,j,k,combo1[0],combo1[1],combo1[2],N) || 
                    close(i,j,k,combo2[0],combo2[1],combo2[2],N) )
                    sol++;
            }

    fout << sol << endl;

    fin.close();
    fout.close();

    return 0;
}