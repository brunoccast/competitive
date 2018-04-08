#include <iostream>
#include <cstring>
#include <cmath>

#define MAXP 35

using namespace std;

int T, D, damage, charges[MAXP], n_charge;
char P[MAXP];

int main()
{
  cin >> T;

  for(int i=1; i!=T+1; ++i)
  {
    cin >> D >> P;

    damage = n_charge = 0;
    int beam = 1, cur_shoot = 0;

    for(int i=0; i!=strlen(P); ++i)
    {
      if(P[i] == 'C')
      {
	beam *= 2;
	charges[n_charge++] = cur_shoot; // number of S at n_charge C
	cur_shoot = 0;
      }
      else
      {
	damage += beam;
	cur_shoot++;
      }
    }

    charges[n_charge] = cur_shoot;

    int swaps = 0;
    while(damage > D)
    {
      while(n_charge && !charges[n_charge])
	n_charge--;

      if(n_charge == 0)
	break; // S before first charge doesnt matter
      
      for(int j=0; j!=charges[n_charge] && damage>D; ++j)
      {
	damage = (damage-(int)pow(2.0,n_charge)) + (int)pow(2.0,n_charge-1);
	swaps++;
	charges[n_charge-1]++;
      }

      n_charge--;
    }

    if(damage > D)
      cout << "Case #" << i << ": IMPOSSIBLE" << endl;
    else
      cout << "Case #" << i << ": " << swaps << endl;
  }
  
  return 0;
}
