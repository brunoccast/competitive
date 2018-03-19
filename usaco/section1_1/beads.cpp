/*
ID: brunocc1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    string necklace;
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    fin >> N >> necklace;
    necklace += necklace; // to easily handle the ends runaround

    int best=0, lastSeq=0, curSeq=0, w=0;
    char curColor = 'w';
    
    for(size_t i=0; i<necklace.length() && best<N; ++i)
    {
	char bead = necklace.at(i);

	if(bead == 'w' || bead == curColor)
	{
	    w = (bead == 'w') ? w+1 : 0;
	    curSeq++;
	}
	else
	{
	    best = max(best, curSeq+lastSeq);
	    lastSeq = curSeq-w;
	    curSeq = w+1;
	    w = 0;
	    curColor = bead;
	}
    }

    best = max(best, curSeq+lastSeq);
    if(best > N) best = N;
    fout << best << endl;
    
    fin.close();
    fout.close();
    
    return 0;
}
