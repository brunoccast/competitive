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

int n, k;
string s;
vector< vii > degree(100010);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> k >> s;

	stack< pair<int, ii> > bk;
	int level=0, maxl=0;
	
	FORN(i,n)
	{
		if(s[i] == '(')
		{
			bk.push( make_pair(level++, make_pair(i,-1)) );
			maxl = max(maxl,level);
		}
		else
		{
			pair<int,ii> top = bk.top();
			top.second.second = i;
			degree[top.first].push_back(top.second);
			level = top.first;
			bk.pop();
		}
	}

	int removal = (n-k)/2;

	/* not sure what "maintaining the order" mean so 
	   just remove pairs with lower nest level */
    FORN(i,maxl+1)
	{
		if(!removal) break;

		FORN(j,degree[i].size())
		{
			if(!removal) break;

			s[degree[i][j].first] = 'x';
			s[degree[i][j].second] = 'x';

			removal--;
		}
	}

	FORN(i,n) if(s[i]!='x') cout << s[i];
	cout << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
