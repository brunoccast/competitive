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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	int n,m;
	string s,t;

	cin >> n >> m >> s >> t;

	int pos = -1;
	FORN(i,n) if(s[i] == '*') { pos=i; break; }

	bool valid = true;
	
	if(pos == -1)
	{
		if(n!=m)
			valid = false;
		else
			FORN(i,n) if(s[i]!=t[i]) { valid = false; break; }
	}
	else
	{
		if(n-1>m)
			valid = false;
		else
		{
			for(int i=0; i!=pos; ++i)
				if(s[i]!=t[i]) { valid = false; break; }

			for(int i=n-1, j=m-1; i>pos; --i, --j)
				if(s[i]!=t[j]) { valid = false; break; }
		}
	}

	cout << (valid ? "YES" : "NO") << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
