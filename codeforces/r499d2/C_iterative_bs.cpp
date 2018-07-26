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
const ld EPS = 1e-6;

int n;
double m;
vector<int> a, b;

bool valid(double fuel)
{
	double mass = fuel+m;

	mass -= mass/a[0]; // earth take-off
	
	for(int i=1; i!=n && mass>=m; ++i)
	{
		mass -= mass/a[i];
		mass -= mass/b[i];
	}

	mass -= mass/b[0]; // earth landing
	
	return mass >= m;
}

double search(double lo, double hi, int reps=60)
{
	double ans = -1;

	FORN(i,reps)
	{
		double mid = lo + (hi-lo)/2;
		
		if(valid(mid))
			ans = mid, hi = mid;
		else
			lo = mid;
	}

	return ans;
}

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> m;

	a.resize(n);
	FORN(i,n) cin >> a[i];
	
	b.resize(n);
	FORN(i,n) cin >> b[i];

	cout << setprecision(10) << fixed << search(0, double(1e9)) << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
