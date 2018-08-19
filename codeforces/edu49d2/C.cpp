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

int t, n, a, s, sticks[1000005], freq[10005];
set<int> used;

inline double fx(int a, int b)
{
	return (a*1.0)/b + (b*1.0)/a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> t;

	while(t--)
	{
		cin >> n;
		
		s=0;

		if(!used.empty())
		{
			for(auto x: used)
				freq[x] = 0;

			used.clear();
		}
		
		FORN(i,n)
		{
			cin >> a;
			++freq[a];
			if(freq[a]==2 || freq[a]==4)
				sticks[s++] = a;
			if(!used.count(a))
				used.insert(a);
		}
		
		sort(sticks,sticks+s);

		int s1=-1, s2=-1;
		double min = 10000000000000.0;
		
		FORN(i,s-1)
		{
			double r = fx(sticks[i], sticks[i+1]);

			if(r < min)
			{
				min = r;
				s1 = sticks[i];
				s2 = sticks[i+1];
			}
		}
		
		cout << s1 << " " << s1 << " " << s2 << " " << s2 << endl;
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
