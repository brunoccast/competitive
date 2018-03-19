/*
USER: brunocc1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXMN 51
using namespace std;

int M, N, castle[MAXMN][MAXMN], rooms[MAXMN][MAXMN], room_size[MAXMN*MAXMN], nroom, max_room;

void flood_fill(int x, int y)
{
  rooms[x][y] = nroom;
  room_size[nroom]++;

  int w = castle[x][y];
  
  if( !(w&1) && !rooms[x][y-1] ) // W
    flood_fill(x,y-1);
  if( !(w&2) && !rooms[x-1][y] ) // N
    flood_fill(x-1,y);
  if( !(w&4) && !rooms[x][y+1] ) // E
    flood_fill(x,y+1);
  if( !(w&8) && !rooms[x+1][y] ) // S
    flood_fill(x+1,y);
}

void find_rooms()
{
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=M; ++j)
      if(!rooms[i][j])
      {
	nroom++;
	flood_fill(i,j);
	max_room = max(max_room,room_size[nroom]);
      }
}

int main()
{
  ifstream fin("castle.in");
  fin >> M >> N;
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=M; ++j)
      fin >> castle[i][j];
  fin.close();
  
  find_rooms();
  
  ofstream fout("castle.out");
  fout << nroom << endl << max_room << endl;
  
  int px=-1, py=-1, pw=-1;
  for(int j=1; j<=M; ++j)
    for(int i=1; i<=N; ++i)
    {
      if(i!=1 && castle[i][j]&2 && rooms[i-1][j]!=rooms[i][j])
      {
	// can open north wall
	int new_size = room_size[rooms[i][j]] + room_size[rooms[i-1][j]];
	if(new_size > max_room || (new_size == max_room && px == j) )
	{
	  //cout << "found N at " << i << " " << j << endl;
	  max_room = new_size;
	  px=j, py=i, pw=2;
	}
      }

      if(j!=M && castle[i][j]&4 && rooms[i][j+1]!=rooms[i][j])
      {
	// can open east wall
	int new_size = room_size[rooms[i][j]] + room_size[rooms[i][j+1]];
	if(new_size > max_room || (new_size == max_room && px == j && pw != 2) )
	{
	  //cout << "found E at " << i << " " << j << endl;
	  max_room = new_size;
	  px=j, py=i, pw=4;
	}
      }
    }
  
  fout << max_room << endl 
       << py << " " << px << " " << (pw&2 ? "N" : "E") << endl; 
  fout.close();

  return 0;
}
