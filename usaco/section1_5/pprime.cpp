/*
USER: brunocc1
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a,b;
ofstream fout;

bool prime(int num)
{
  // 2 is prime, but in this problem its not a considered number
  if(num%2 == 0)
    return false;

  for(int i=3; i*i<=num; i+=2)
    if(num%i == 0)
      return false;

  return true;
}

/*
 * convert num to its odd|even palindrome
 * and verify if its part of the solution
 */
void gen_pal(int num, bool gen_odd=true)
{
  char str[10];
  int i, j;

  j = sprintf(str,"%d",num); // sprintf returns the string length
  i = j-1-gen_odd;           // -1 to adjust to the last character in the string

  while(i>=0)
    str[j++] = str[i--];
  str[j] = '\0';

  int n = atoi(str);
  if(n>=a && n<=b && prime(n))
    fout << n << endl;
}

/*
 * generate odd and even palidromes
 * for every number in the range [start,end]
 */
void gen_pal(int start, int end)
{
  for(int i=start; i<=end; ++i)
    gen_pal(i);

  for(int i=start; i<=end; ++i)
    gen_pal(i,false);
}

int main()
{
  ifstream fin("pprime.in");
  fin >> a >> b;
  fin.close();

  fout.open("pprime.out");
  gen_pal(1,9);
  gen_pal(10,99);
  gen_pal(100,999);
  gen_pal(1000,9999);
  fout.close();

  return 0;
}
