/*
ID: brunocc1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

inline bool isLeap(int year)
{
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

int main()
{
    int N;
    int _13freq[7];
    int monthDays[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    fin >> N;
    memset(_13freq, 0, 7*sizeof(int));
    
    for(int y=1900, dayCount=13; y<1900+N; ++y)
    {
        monthDays[2] = isLeap(y) ? 29 : 28;
	for(int m=1; m<=12; ++m)
	{
	    _13freq[dayCount%7]++;
	    dayCount += monthDays[m];
	}
    }

    // January 13, 1900 was on a Saturday.
    // Saturday is the last in our frequencies array
    // because 13%7 = 6, so we start to print this position.
    fout << _13freq[6];
    for(int m=0; m<6; ++m)
	fout << " " << _13freq[m];
    fout << endl;
    
    fin.close();
    fout.close();
    
    return 0;
}
