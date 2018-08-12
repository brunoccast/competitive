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

int n, m, p, c, berland;
ll ans = 1e12;
vector<vi> party_votes;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> m;

	party_votes.resize(m+1);
	
	FORN(i,n)
	{
		cin >> p >> c;
		berland += (p==1);
		party_votes[p].push_back(c);
	}

	FORE(i,2,m+1) sort(party_votes[i].begin(), party_votes[i].end());

	FORE(i,1,n+1) // compute minimum cost to win elections with i votes
	{
		int cur = berland;
		ll cost = 0;
		priority_queue< int, vi, greater<int> > pq;
		
		FORE(j,2,m+1)
		{
			int sz = party_votes[j].size();

			/* pay cheapest votes from party j until it has i-1 votes */
			int k = 0;
			while(sz-k >= i && k != sz)
			{
				cost += party_votes[j][k++];
				cur++;
			}

			/* keep remaining votes of party j in increasing order of 
			   price (pq) for later use if needed */
			while(k != sz)
				pq.push(party_votes[j][k++]);
		}

		while(cur < i)
		{
			cost += pq.top();
			cur++;
			pq.pop();
		}

		ans = min(ans, cost);
	}

	cout << ans << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
