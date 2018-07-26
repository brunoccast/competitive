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

int n, ans;
vector<int> seq;
map<int,int> ocurr;

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n;

	for(int i=0; i!=n; ++i)
	{
		int ni; cin >> ni;

		seq.push_back(ni);
		ocurr[ni]++;
	}

	for(int i=0; i!=n; ++i)
	{
		int acc=1, j;
		for(j=1; j<=30; ++j)
		{
			acc *= 2;
			int x = acc-seq[i];
			
			if(ocurr.count(x) && (ocurr[x] > 1 || x != seq[i]) )
				break;
		}

		if(j > 30)
			ans++;
	}

	cout << ans << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
