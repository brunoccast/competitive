/*
 * D2.cpp is a lot more decent but well, this
 * also worked out. Same strat but non-recursive
 * and also slower.
 */

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
vi costs, g;
bitset<200005> vis;

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

	FORE(i,1,n+1)
	{
		if(vis[i]) continue;

		vis.set(i);
		
		bitset<200005> seen;
		seen.set(i);
		
		stack<int> S;
		S.push(i);

		int cur = i;
		
		while(!vis[g[cur]] && !seen[g[cur]])
		{
			cur = g[cur];
			seen.set(cur);
			S.push(cur);
		}

		if(vis[g[cur]] && g[cur] != i)
		{
			while(!S.empty())
			{
				vis.set(S.top());
				S.pop();
			}

			continue;
		}
		
		int start_cycle = g[cur];
		int mi = costs[start_cycle];

		while(S.top() != start_cycle)
		{
			int next = S.top();
			mi = min(mi, costs[next]);
			vis.set(next);
			S.pop();
		}
		
		ans += mi;

		while(!S.empty())
		{
			vis.set(S.top());
			S.pop();
		}
	}

	cout << ans << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
