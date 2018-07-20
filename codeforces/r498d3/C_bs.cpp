/*
 * C: Three Parts of the Array
 * - Binary Search
 */

#include <iostream>
#define MAXN 200005
#define LL long long

using namespace std;

int n;
LL prefix_sum[MAXN], suffix_sum[MAXN];

int main()
{
	cin >> n;
	for(int i=0; i!=n; ++i)
	{
		cin >> prefix_sum[i];
		suffix_sum[n-i-1] = prefix_sum[i];
	}

	for(int i=1; i!=n; ++i)
	{
		prefix_sum[i] += prefix_sum[i-1];
		suffix_sum[i] += suffix_sum[i-1];
	}

	LL best = 0;
	
	for(int i=0; i!=n; ++i)
	{
		int lo=0, hi=n-1;
		
		while(lo <= hi)
		{
			int mid = lo + (hi-lo)/2;

			if(suffix_sum[mid] == prefix_sum[i] && i+mid < n-1)
			{
				best = prefix_sum[i];
				break;
			}
			else if(suffix_sum[mid] > prefix_sum[i])
				hi = mid-1;
			else
				lo = mid+1;
		}
	}

	cout << best << endl;
	
	return 0;
}
