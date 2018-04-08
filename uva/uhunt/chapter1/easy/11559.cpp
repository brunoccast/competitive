#include <iostream>
#include <algorithm>

#define MAXW 15
#define MAXB 600000

using namespace std;

int main()
{
  int N, B, H, W, p, beds, min_cost;

  while( (cin >> N >> B >> H >> W) )
  {
    min_cost = MAXB;
    
    for(int h=0; h!=H; ++h)
    {
      cin >> p;
      for(int w=0; w!=W; ++w)
      {
	cin >> beds;
	if(beds >= N && N*p <= B)
	  min_cost = min(min_cost, N*p);
      }
    }

    if(min_cost == MAXB)
      cout << "stay home" << endl;
    else
      cout << min_cost << endl;
  }
  
  return 0;
}
