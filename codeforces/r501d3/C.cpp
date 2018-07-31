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
ll m, sum;
vector< pair<ll,ll> > songs;

bool compare(const pair<ll,ll>& lhs, const pair<ll,ll>& rhs)
{
	return (lhs.first-lhs.second) > (rhs.first-rhs.second);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> m;

	FORN(i,n)
	{
		pair<ll,ll> p;
		cin >> p.first >> p.second;
		songs.push_back(p);
		sum += p.first;
	}

	sort(songs.begin(), songs.end(), compare);

	int p=0;
	while(p < n && sum > m)
	{
		sum -= (songs[p].first-songs[p].second);
		p++;
	}

	cout << (sum <= m ? p : -1) << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
