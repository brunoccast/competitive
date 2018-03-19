/*
ID: brunocc1
TASK: barn1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    fstream fin, fout;
    fin.open("barn1.in", fstream::in);
    fout.open("barn1.out", fstream::out);

    int M, S, C;
    vector<int> stalls;
    vector<int> gaps;

    fin >> M >> S >> C;
    for(int i=0; i<C; ++i)
    {
        int nthcow; fin >> nthcow;
        stalls.push_back(nthcow);
    }
    
    sort(stalls.begin(), stalls.end());

    for(size_t s=1; s<stalls.size(); ++s)
    {
        int gapsize = stalls[s]-stalls[s-1]-1;
        if(gapsize > 0)
            gaps.push_back(gapsize);
    }
      
    sort(gaps.begin(), gaps.end(), greater<int>());

    int result = stalls[stalls.size()-1]-stalls[0]+1;
    for(size_t g=0; g<gaps.size() && (int)g<(M-1); ++g)
    {
        //cout << "gap " << g << ": " << gaps[g] << endl;
        result -= gaps[g];
    }

    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}