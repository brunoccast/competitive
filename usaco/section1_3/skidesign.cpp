/*
ID: brunocc1
TASK: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");

  int N;
  fin >> N;
  
  vector<int> hills(N);
  for(int i=0; i!=N; ++i)
    fin >> hills[i];
  
  int sol=INT_MAX;

  /*
   * test all elevations from range [0,17] to [83,100]
   * faster approach would be:
   *    for(int lh=min_height; lh!<=min(min_height,max_height-17); ++lh)
   */
  for(int lh=0; lh!=84; ++lh)
  {
    int cost=0;
    for(int i=0; i!=N; ++i)
    {
      if(hills[i] < lh)
	cost += (lh-hills[i])*(lh-hills[i]);
      else if(hills[i] > lh+17)
	cost += (hills[i]-lh-17)*(hills[i]-lh-17);
    }
    
    sol = min(sol,cost);
  }
  
  fout << sol << endl;

  fin.close();
  fout.close();

  return 0;
}
