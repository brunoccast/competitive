/*
 * B: Polycarp's Practice
 * - Greedy
 */

#include <iostream>
#include <algorithm>
#define MAXN 2005

using namespace std;

int n, k, seq[MAXN], _seq[MAXN], best[MAXN], sum;

int main()
{
	cin >> n >> k;
	for(int i=0; i!=n; ++i)
	{
		cin >> seq[i];
		_seq[i] = seq[i];
	}

	sort(_seq, _seq+n, greater<int>());

	for(int i=0; i!=k; ++i)
	{
		sum += _seq[i];
		best[_seq[i]]++;
	}

	cout << sum << endl;

	int i=0, _i=0, days=0;
	while(i!=n)
	{
		if(best[seq[i]])
		{
			best[seq[i]]--;
			
			days++;
			if(days == k)
			{
				cout << (n-_i) << endl;
				break;
			}
			
			cout << (i-_i)+1 << " ";
			_i = i+1;
		}
		
		i++;
	}
	
	return 0;
}
