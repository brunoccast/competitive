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

#define MAXN 55

int n, n_moves, moves[1300];
char a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> a >> b;

	int pa, pb;
	pa = pb = n-1;

	while(true)
	{
		while(pa >= 0 && a[pa] == b[pb])
		{
			pa--;
			pb--;
		}

		if(pa < 0) break;

		int pos = pa-1;
		while(pos >= 0 && a[pos] != b[pb])
			pos--;
		
		if(pos < 0)
		{
			cout << -1 << endl;
			return 0;
		}

		FORE(i,pos,pb)
		{
			moves[n_moves++] = i+1;
			a[i] = a[i+1];
		}

		a[pa] = b[pb];
	}
	
	cout << n_moves << endl;
	FORN(i,n_moves)
		cout << moves[i] << (i+1==n_moves ? "\n" : " ");
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
