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

int n;
double m, mass;
vector<int> a, b;

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> m;

	a.resize(n);
	FORN(i,n)
	{
		cin >> a[i];
		
		if(a[i] <= 1)
		{
			// can't carry both cargo+fuel
			cout << -1 << endl;
			return 0;
		}
	}

	b.resize(n);
	FORN(i,n)
	{
		cin >> b[i];

		if(b[i] <= 1)
		{
			// can't carry both cargo+fuel
			cout << -1 << endl;
			return 0;
		}
	}

	/**
	 * cargo mass = s
	 * fuel = x
	 * a[i] or b[i] = t
	 *
	 * total rocket mass = total mass fuel can land/take-off
	 * <=> s + x = t * x
	 * <=> x = s / (t-1)
	 */
	
	mass = m;
	mass += mass/(a[0]-1); // earth take-off

	FORE(i,1,n)
	{
		mass += mass/(b[i]-1);
		mass += mass/(a[i]-1);
	}

	mass += mass/(b[0]-1); // earth landing

	cout << setprecision(10) << fixed << mass-m << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
