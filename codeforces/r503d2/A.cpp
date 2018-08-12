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

int n, h, a, b, k, ta, fa, tb, fb;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> h >> a >> b >> k;

	while(k--)
	{
		cin >> ta >> fa >> tb >> fb;

		ll ans;
		
		if(ta == tb)
			ans = fabs(fb-fa);
		else
		{
			if( (fa >= a && fa <= b) || (fb >= a && fb <= b) )
				ans = fabs(tb-ta) + fabs(fb-fa);
			else
			{
				if(fa < a)
					ans = (a-fa) + fabs(tb-ta) + fabs(fb-a);
				else
					ans = (fa-b) + fabs(tb-ta) + fabs(fb-b);

				ll ans_b;

				if(fb < a)
					ans_b = (a-fb) + fabs(tb-ta) + fabs(fa-a);
				else
					ans_b = (fb-b) + fabs(tb-ta) + fabs(fa-b);

				ans = min(ans,ans_b);
			}
		}

		cout << ans << endl;
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
