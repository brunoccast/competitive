/*
ID: brunocc1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int NP, amount, NG;
    string name;
    vector<string> groupNames;
    map< string, pair<int, int> > group;
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    fin >> NP;
    for(int i=0; i<NP; ++i)
    {
	fin >> name;

	groupNames.push_back(name);
	group.insert( make_pair(name, make_pair(0,0)) );
    }

    for(int i=0; i<NP; ++i)
    {
	fin >> name >> amount >> NG;

        map< string, pair<int, int> >::iterator it = group.find(name);
	it->second.first = amount;
	it->second.second += NG ? (amount%NG) : amount;

	for(int j=0; j<NG; ++j)
	{
	    fin >> name;
	    group[name].second += (amount/NG);
	}
    }

    for(size_t i=0; i<groupNames.size(); ++i)
    {
	map< string, pair<int, int> >::iterator it = group.find(groupNames[i]);
	fout << groupNames[i] << " " << (it->second.second - it->second.first) << endl;
    }

    fin.close();
    fout.close();
    
    return 0;
}
