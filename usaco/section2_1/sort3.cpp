/*
ID: brunocc1
TASK: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 1000
using namespace std;

int N, seq[MAXN], freq[4];

int main()
{
  ifstream fin("sort3.in");
  fin >> N;
  for(int i=0; i<N; ++i)
  {
    fin >> seq[i];
    freq[seq[i]]++;
  }
  fin.close();

  int ans = 0;

  // 1-swap 1's with 2's
  for(int i=0; i<freq[1]; ++i)
    for(int j=freq[1]; j<N-freq[3]; ++j)
      if(seq[i]==2 && seq[j]==1)
	seq[i]=1, seq[j]=2, ans++;

  // 1-swap 1's with 3's
  for(int i=0; i<freq[1]; ++i)
    for(int j=N-freq[3]; j<N; ++j)
      if(seq[i]==3 && seq[j]==1)
	seq[i]=1, seq[j]=3, ans++;

  // 1-swap 2's with 3's
  for(int i=freq[1]; i<N-freq[3]; ++i)
    for(int j=N-freq[3]; j<N; ++j)
      if(seq[i]==3 && seq[j]==2)
	seq[i]=2, seq[j]=3, ans++;

  // correct unplaced 1's
  for(int i=0; i<freq[1]; ++i)
    if(seq[i]!=1)
    {
      int j;
      for(j=N-1; seq[j]!=1; --j){}
      seq[j] = seq[i];
      seq[i] = 1;
      ans++;
    }

  // correct unplaced 2's
  for(int i=freq[1]; i<N-freq[3]; ++i)
    if(seq[i]!=2)
    {
      int j;
      for(j=N-1; seq[j]!=2; --j){}
      seq[j] = seq[i];
      seq[i] = 2;
      ans++;
    }
      
  ofstream fout("sort3.out");
  fout << ans << endl;
  fout.close();
  
  return 0;
}
