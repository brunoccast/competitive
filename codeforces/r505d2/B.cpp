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

int n;
ll a, b;
vector< pair<ll,ll> > pairs;
set<int> fac;

bool is_prime(int num)
{
	if(num < 2) return false;

	for(int i=2; i<=(int)sqrt(num); ++i)
		if(num%i == 0) return false;

	return true;
}

void factors(ll num)
{
	for(int i=2; i*i <= num; ++i)
	{
		if(num%i==0 && is_prime(i))
		{
			fac.insert(i);
			while(i*i <= num && num%i == 0)
				num /= i;
		}
	}

	if(num != 1) fac.insert(num);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n;

	pairs.resize(n);

	FORN(i,n) cin >> pairs[i].first >> pairs[i].second;

	factors(pairs[0].first);
	factors(pairs[0].second);

	FORE(i,1,n)
	{
		set<int> r;

		for(int p: fac)
			if(pairs[i].first%p != 0 && pairs[i].second%p != 0) r.insert(p);

		for(int p: r)
			fac.erase(p);
	}

	cout << (fac.empty() ? -1 : *fac.begin()) << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
