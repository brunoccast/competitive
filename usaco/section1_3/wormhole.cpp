/*
ID: brunocc1
TASK: wormhole
LANG: C++11
*/

#include <iostream>
#include <fstream>
#define MAXN 12
using namespace std;

int N, nsol;
int next_hole[MAXN+1], pair_hole[MAXN+1];
int holes[MAXN+1][2];

bool find_cycle()
{
  for(int start_hole=1; start_hole<=N; ++start_hole)
  {
    int pos = start_hole;
    for(int i=0; i!=MAXN; ++i)
      pos = next_hole[ pair_hole[pos] ];

    if(pos)
      return true;
  }
  
  return false;
}

void find_solutions()
{
  // find first unpaired hole
  int ih;
  for(ih=1; ih<=N; ++ih)
    if(!pair_hole[ih])
      break;

  // check for solution if all holes are paired
  if(ih > N)
  {
    if(find_cycle())
      nsol++;
    
    return;
  }

  // find pair for ih hole
  for(int jh=ih+1; jh<=N; ++jh)
    if(!pair_hole[jh])
    {
      pair_hole[ih] = jh;
      pair_hole[jh] = ih;
      find_solutions();
      pair_hole[ih] = 0;
      pair_hole[jh] = 0;
    }
}

int main()
{
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  // read input
  fin >> N;
  for(int i=1; i<=N; ++i)
    fin >> holes[i][0] >> holes[i][1];

  // for every hole, verify which hole is
  // the closest to the right (if any)
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
      if(holes[j][0] > holes[i][0] && holes[j][1] == holes[i][1])
	if(next_hole[i] == 0 || holes[j][0]-holes[i][0] < holes[next_hole[i]][0]-holes[i][0])
	  next_hole[i] = j;

  // process and ouput
  find_solutions();
  fout << nsol << endl;

  fin.close();
  fout.close();
  
  return 0;
}
