#include <bits/stdc++.h>

using namespace std;

#define FORN(i,n) for(int i=0; i!=int(n); ++i)
#define FORE(i,l,r) for(int i=int(l); i!=int(r); ++i)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INF64 = 1e18;
const ld EPS = 1e-9;

int n, k, n_diff, seq[30];
bool seen[30];

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> k;

	for(int i=0; i!=n; ++i)
	{
		char c; cin >> c;
		
		if(!seen[c-'a'+1])
		{
			seen[c-'a'+1] = true;
			seq[n_diff++] = c-'a'+1;
		}
	}

	sort(seq, seq+n_diff);
	
	for(int i=0; i!=n_diff; ++i)
	{	
		if(i+k-1 >= n_diff)
		{
			cout << -1 << endl;
			break;
		}

		int amnt = 1, last = i, sum = seq[i];

		for(int j=i+1; j!=n_diff && amnt!=k; ++j)
		{
			if(seq[j] - seq[last] >= 2)
			{
				amnt++;
				last = j;
				sum += seq[j];
			}
		}

		if(amnt == k)
		{
			cout << sum << endl;
			break;
		}
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
