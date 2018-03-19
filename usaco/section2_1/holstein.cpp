/*
USER: brunocc1
TASK: holstein
LANG: C++ 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXV 25
#define MAXG 15
using namespace std;

int V, G, vit[MAXV], feed[MAXG][MAXV]; // input
int vit_amnt[MAXV], scoop_ans=MAXG+1, feed_tmp[MAXG], feed_ans[MAXG];

bool reached_solution()
{
  for(int i=0; i<V; ++i)
    if(vit_amnt[i] > 0)
      return false;

  return true;
}

void search(int cur_feed, int scoop)
{
  if(scoop >= scoop_ans)
    return;

  if(reached_solution())
  { 
    scoop_ans = scoop;
    for(int i=0; i<scoop; ++i)
      feed_ans[i] = feed_tmp[i];
    
    return;
  }

  for(int i=cur_feed; i<G; ++i)
  {
    feed_tmp[scoop] = i+1;
    for(int j=0; j<V; ++j)
      vit_amnt[j] -= feed[i][j];

    search(i+1,scoop+1);

    for(int j=0; j<V; ++j)
      vit_amnt[j] += feed[i][j];
  }
}

int main()
{
  ifstream fin("holstein.in");
  fin >> V;
  for(int i=0; i<V; ++i)
  {
    fin >> vit[i];
    vit_amnt[i] = vit[i];
  }
  fin >> G;
  for(int i=0; i<G; ++i)
    for(int j=0; j<V; ++j)
      fin >> feed[i][j];
  fin.close();

  search(0,0);
  
  ofstream fout("holstein.out");
  fout << scoop_ans;
  for(int i=0; i<scoop_ans; ++i)
    fout << " " << feed_ans[i];
  fout << endl;
  fout.close();
  
  return 0;
}
