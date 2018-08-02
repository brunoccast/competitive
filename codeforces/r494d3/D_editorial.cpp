#include <bits/stdc++.h>

using namespace std;

#define FORN(i,n) for(int i=0; i!=int(n); ++i)
#define FORE(i,l,r) for(int i=int(l); i!=int(r); ++i)
#define FORR(i,l,r) for(int i=int(l); i>=int(r); --i)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INF64 = 1e18;
const ld EPS = 1e-9;

int n, q, freq[31];

// instead of __builtin_ctz
int trailing_zeros(unsigned num)
{
	int ret = 0;
	while(num >>= 1)
		ret++;

	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> q;

	FORN(i,n)
	{
		int ni; cin >> ni;
		freq[trailing_zeros(ni)]++;
	}

	FORN(i,q)
	{
		int qi, ans=0;

		cin >> qi;
		
		for(int j=30; j>=0 && qi; --j)
		{
			int coins = min(qi>>j, freq[j]);
			ans += coins;
			qi -= coins*(1<<j);
		}

		if(qi) ans = -1;
		
		cout << ans << endl;
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif

	return 0;
}
