/*
ID: brunocc1
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX_BSQR 250*250*2

using namespace std;

int N,M;
bool is_bsqr[MAX_BSQR+1];
vector< pair<int,int> > sols;

bool compare(const pair<int,int>& lhs, const pair<int,int>& rhs)
{
  if(lhs.second == rhs.second)
    return lhs.first < rhs.first;

  return lhs.second < rhs.second;
}
  
int main()
{
  ifstream fin("ariprog.in");
  fin >> N >> M;
  fin.close();

  for(int p=0; p!=M+1; ++p)
    for(int q=p; q!=M+1; ++q)
      is_bsqr[p*p+q*q] = true;

  for(int a=0; a!=MAX_BSQR+1; ++a)
  {
    if(!is_bsqr[a])
      continue;
    
    for(int b=1; a+b*(N-1)<=MAX_BSQR; ++b)
    {
      int n;
      for(n=0; n!=N; ++n)
	if(!is_bsqr[a+b*n])
	  break;
      
      if(n==N)
	sols.push_back(make_pair(a,b));
    }
  }

  ofstream fout("ariprog.out");
  if(sols.empty())
    fout << "NONE" << endl;
  else
  {
    sort(sols.begin(), sols.end(), compare);
    for(vector< pair<int,int> >::const_iterator it=sols.begin();
	it!=sols.end(); ++it)
      fout << it->first << " " << it->second << endl;
  }
  fout.close();
    
  return 0;
}
