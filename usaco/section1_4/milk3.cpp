/*
ID: brunocc1
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX_C 20
using namespace std;

int A, B, C, visited[MAX_C+1][MAX_C+1][MAX_C+1];
vector<int> solutions;

void search(int curA, int curB, int curC)
{
  if(visited[curA][curB][curC])
    return;
  
  visited[curA][curB][curC] = 1;
  if(!curA)
    solutions.push_back(curC);

  search(curA-min(curA,B-curB),curB+min(curA,B-curB),curC); // A->B
  search(curA-min(curA,C-curC),curB,curC+min(curA,C-curC)); // A->C
  search(curA+min(curB,A-curA),curB-min(curB,A-curA),curC); // B->A
  search(curA,curB-min(curB,C-curC),curC+min(curB,C-curC)); // B->C
  search(curA+min(curC,A-curA),curB,curC-min(curC,A-curA)); // C->A
  search(curA,curB+min(curC,B-curB),curC-min(curC,B-curB)); // C->B
}

int main()
{
  ifstream fin("milk3.in");
  fin >> A >> B >> C;
  fin.close();

  search(0,0,C);
  sort(solutions.begin(),solutions.end());

  ofstream fout("milk3.out");
  fout << solutions[0];
  for(size_t i=1; i!=solutions.size(); ++i)
    fout << " " << solutions[i];
  fout << endl;
  fout.close();
}
