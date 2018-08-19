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

ll n, q, l, c;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> q;
	
	while(q--)
	{
		cin >> l >> c;

		ll x = l-1;
		ll ans;
		
		if((l+c)%2 == 0)
		{
			ans = (x-(x/2))*(n-(n/2)) + (x/2)*(n/2);
			ans += (l%2 == 0) ? c/2 : c-(c/2);
			cout << ans << endl;
		}
		else
		{
			ans = (x-(x/2))*(n/2) + (x/2)*(n-(n/2));
			ans += (l%2 == 0) ? c-(c/2) : c/2;
			cout << ((n*n+1)/2)+ans << endl;
		}
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
