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

int a, b, x;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> a >> b >> x;

	if(x%2 == 0)
	{
		if(a > b)
		{
			FORN(i,x/2) cout << "01";
			cout << string(b-x/2, '1') << string(a-x/2, '0');
		}
		else
		{
			FORN(i,x/2) cout << "10";
			cout << string(a-x/2, '0') << string(b-x/2, '1');
		}
	}
	else
	{
		if(a > b)
		{
			FORN(i,x/2) cout << "01";
			cout << string(a-x/2, '0') << string(b-x/2, '1');
		}
		else
		{
			FORN(i,x/2) cout << "10";
			cout << string(b-x/2, '1') << string(a-x/2, '0');
		}
	}
	
	cout << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif

	return 0;
}
