/*
ID: brunocc1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>

#define MAXLEN 10
using namespace std;

int prod(char *s)
{
    if(*s == '\0')
	return 1;

    return ((*s)-'A'+1) * prod(s+1); 
}

int main()
{
    char comet[MAXLEN], group[MAXLEN];
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    
    fin >> comet >> group;

    if( prod(comet)%47 == prod(group)%47 )
	fout << "GO" << endl;
    else
	fout << "STAY" << endl;

    return 0;
}
