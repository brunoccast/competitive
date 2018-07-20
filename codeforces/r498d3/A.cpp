/*
 * A: Adjacent Replacements
 * - implementation
 */

#include <iostream>
#include <set>
#define MAXN 1005

using namespace std;

int n, maxi, seq[MAXN], n_even, even[MAXN];

int main()
{	
	cin >> n;
	
	for(int i=0; i!=n; ++i)
	{
		cin >> seq[i];
		if(seq[i]%2 == 0)
			even[n_even++] = seq[i];
	}
	
	for(int i=0; i!=n_even; ++i)
	{
		for(int j=0; j!=n; ++j)
		{
			if(seq[j] == even[i])
				seq[j] = even[i]-1;
		}
	}

	cout << seq[0];
	for(int i=1; i!=n; ++i)
		cout << " " << seq[i];
	cout << endl;
	
	return 0;
}
