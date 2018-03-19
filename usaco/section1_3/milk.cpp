/*
ID: brunocc1
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    fstream fin, fout;
    fin.open("milk.in", fstream::in);
    fout.open("milk.out", fstream::out);

    int N, M, mincost;
    vector< pair<int,int> > farmers;

    fin >> N >> M;
    for(int i=0; i<M; ++i)
    {
        pair<int,int> pi;
        fin >> pi.first >> pi.second;
        farmers.push_back(pi);
    }

    sort(farmers.begin(), farmers.end());

    mincost=0;
    for( pair<int,int> p : farmers )
    {
        if(p.second >= N)
        {
            mincost += N*p.first;
            break;
        }

        mincost += p.second*p.first;
        N -= p.second;
    }

    fout << mincost << endl;

    fin.close();
    fout.close();

    return 0;
}