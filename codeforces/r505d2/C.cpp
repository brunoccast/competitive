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

	string s; cin >> s;

	size_t sz = s.length();
	
    if(s[0] != s[sz-1])
	{
		size_t p=1;
		for(; p!=sz; ++p) if(s[p]==s[p-1]) break;

		for(size_t i=0,j=(p-1); i<j; ++i, --j)
		{
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}

		for(size_t i=p,j=sz-1; i<j; ++i, --j)
		{
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
	}

	char color = s[0];
	int mx=0, cur=1;
	
	FORE(i,1,sz)
	{
		if(s[i] != color)
			cur++;
		else
		{
			mx = max(mx,cur);
			cur = 1;
		}

		color = s[i];
	}

	mx = max(mx,cur);
	cout << mx << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
