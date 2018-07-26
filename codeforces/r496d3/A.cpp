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

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	int n;

	cin >> n;

	vector<int> seq(n);

	for(int i=0; i!=n; ++i)
		cin >> seq[i];

	int ans=0, p=0;
	vector<int> sols;
	
	while(p < n)
	{
		int p2=p;
		while(p2+1 < n && seq[p2+1] != 1)
			p2++;

		ans++;
		sols.push_back(seq[p2]);

		p = p2+1;
	}

	cout << ans << endl;
	cout << sols[0];
	for(size_t i=1; i!=sols.size(); ++i)
		cout << " " << sols[i];
	cout << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
