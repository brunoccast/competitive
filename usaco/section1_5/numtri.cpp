/*
USER: brunocc1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX_R 1000

using namespace std;

int r, input[MAX_R][MAX_R], best[MAX_R];

int main()
{
  ifstream fin("numtri.in");
  fin >> r;
  for(int i=0; i!=r; ++i)
    for(int j=0; j<=i; ++j)
      fin >> input[i][j];
  fin.close();

  for(int i=0; i!=r; ++i)
    best[i] = input[r-1][i];

  // DP - using the optimal path from row 'i' to the bottom
  // to calculate the optimal path from row 'i-1'
  for(int i=r-2; i>=0; --i)
    for(int j=0; j<=i; ++j)
      best[j] = input[i][j] + max(best[j],best[j+1]);

  ofstream fout("numtri.out");
  fout << best[0] << endl;
  fout.close();

  return 0;
}
