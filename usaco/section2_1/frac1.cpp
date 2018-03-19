/*
ID: brunocc1
TASK: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 161
using namespace std;

struct Frac
{
  int n;
  int d;
  double r;
};

int N, nfrac;
bool used[MAXN][MAXN];
Frac f[MAXN*MAXN];

bool compare(const Frac& lhs, const Frac& rhs)
{
  return lhs.r < rhs.r;
}

int gcd(int a, int b)
{
  return !b ? a : gcd(b, a%b);
}

int main()
{
  ifstream fin("frac1.in");
  fin >> N;
  fin.close();
  
  for(int i=1; i<=N; ++i)
    for(int j=0; j<=i; ++j)
    {
      int div = gcd(j,i);
      if(!used[j/div][i/div])
      {
	f[nfrac].n=j, f[nfrac].d=i, f[nfrac++].r=(double)j/i;
	used[j/div][i/div] = true;
      }
    }

  sort(f,f+nfrac,compare);

  ofstream fout("frac1.out");
  for(int i=0; i<nfrac; ++i)
    fout << f[i].n << "/" << f[i].d << endl;
  fout.close();
}
