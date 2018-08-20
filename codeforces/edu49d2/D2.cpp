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

int n, ans;
vi costs, g, path, color;
vector<vi> cycles;

void dfs(int v)
{
	color[v] = 1; // seen during search
	path.push_back(v);

	int next = g[v];

	if(color[next] != 2)
	{
		if(color[next] == 1)
		{
			cycles.emplace_back();
			
			int sz = path.size() - 1;
			while(path[sz] != next)
				cycles.back().push_back(path[sz--]);

			cycles.back().push_back(next);
		}
		else
			dfs(next);
	}

	path.pop_back();
	color[v] = 2; // search complete
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

	costs.resize(n+1);
	FORE(i,1,n+1) cin >> costs[i];

	g.resize(n+1);
	FORE(i,1,n+1) cin >> g[i];

	color.assign(n+1,0);
	
	FORE(i,1,n+1)
		if(!color[i]) dfs(i);

	for(auto const &cycle: cycles)
	{
		int mi = 1e5;
		for(auto room: cycle)
			mi = min(mi, costs[room]);

		ans += mi;
	}

	cout << ans << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
