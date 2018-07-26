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

int n, m, n_diff, seen[105], freq[105], max_freq, ans;

void search(int lo, int hi)
{
	if(lo > hi)
		return;

	int mid = lo + (hi-lo)/2;

	int k = 0;
	for(int i=1; i<=n_diff && k<n; ++i)
		k += freq[i]/mid;

	if(k >= n)
	{
		ans = max(ans, mid);
		search(mid+1, hi);
	}
	else
		search(lo, mid-1);
}

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> m;

	if(n > m)
	{
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=0; i!=m; ++i)
	{
		int ni; cin >> ni;

		if(!seen[ni])
			seen[ni] = ++n_diff;

		freq[seen[ni]]++;
		max_freq = max(max_freq, freq[seen[ni]]);
	}

	search(1, max_freq);

	cout << ans << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
