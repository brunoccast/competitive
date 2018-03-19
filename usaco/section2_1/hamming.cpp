/*
USER: brunocc1
TASK: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, B, D;
vector<int> ans;

int dist(int n1, int n2)
{
  int num=n1^n2, diff=0;

  for(int i=0; i<B; ++i)
    if(num&(1<<i))
      diff++;
  
  return diff;
}

bool valid(int num)
{
  for(size_t i=0; i!=ans.size(); ++i)
    if(dist(ans[i],num)<D)
      return false;

  return true;
}

int main()
{
  ifstream fin("hamming.in");
  fin >> N >> B >> D;
  fin.close();

  for(int i=0; N; ++i)
    if(valid(i))
    {
      ans.push_back(i);
      N--;
    }

  ofstream fout("hamming.out");
  for(size_t i=0; i!=ans.size(); ++i)
  {
    if(!(i%10))
      fout << ans[i];
    else
    {
      fout << " " << ans[i];
      if(!((i+1)%10))
	fout << endl;
    }
  }
  if(ans.size()%10)
    fout << endl;
  fout.close();
  
  return 0;
}
