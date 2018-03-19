/*
ID: brunocc1
TASK: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#define MAX 10000
using namespace std;

unsigned p[(MAX>>5)+1];
int prime[MAX], nprime;
ofstream fout;

void sieve()
{
  for(int i=0; i<=MAX>>5; ++i)
    p[i] = 0xffffffff;
  
  prime[0] &= ~(1<<(1%32));

  for(int i=2; i!=MAX; ++i)
    if(p[i/32]&(1<<(i%32)))
    {
      prime[nprime++] = i;
      for(int j=i*i; j<=MAX; j+=i)
	p[j/32] &= ~(1<<(j%32));
    }
}

bool is_prime(int num)
{
  for(int i=0; prime[i]<num && i<nprime; ++i)
    if(!(num%prime[i]))
       return false;

  return true;
}

void dfs(int num, int ndigit)
{
  if(!is_prime(num))
    return;
  
  if(!ndigit)
  {
    fout << num << endl;
    return;
  }

  num *= 10;
  
  dfs(num+1,ndigit-1);
  dfs(num+3,ndigit-1);
  dfs(num+7,ndigit-1);
  dfs(num+9,ndigit-1);
}

int main()
{
  ifstream fin("sprime.in");
  int N;
  fin >> N;
  fin.close();

  sieve();

  fout.open("sprime.out");
  N--;
  dfs(2,N);
  dfs(3,N);
  dfs(5,N);
  dfs(7,N);
  fout.close();
  
  return 0;
}
