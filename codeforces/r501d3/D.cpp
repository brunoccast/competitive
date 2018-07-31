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

ll n, k, s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> k >> s;

	if(s < k || k*(n-1) < s)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	
	int pos=1;
	while(k)
	{
		k--;
		int mv = min(s-k, n-1); // max we can travel with 1 move

		s -= mv;

		if(pos+mv <= n)
			pos += mv;
		else
			pos -= mv;

		cout << pos << " ";
	}

	cout << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif

	return 0;
}
