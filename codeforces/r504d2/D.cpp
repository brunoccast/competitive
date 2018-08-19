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

int n, q, in[200010], freq[200010];
set<int> S;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> q;

	FORN(i,n)
	{
		cin >> in[i];

		if(!in[i])
		{
			in[i] = !i ? 1 : in[i-1];
			S.insert(i);
		}

		freq[in[i]]++;
	}

	if(!freq[q]) // q must be present in the final array
	{
		if(S.empty())
		{
			cout << "NO\n";
			return 0;
		}

		int pos = *S.begin();
		
		freq[in[pos]]--;
		in[pos] = q;
		freq[in[pos]]++;
	}

	S.clear();

	FORN(i,n)
	{
		freq[in[i]]--;

		if(!freq[in[i]])
		{
			if(S.count(in[i]))
				S.erase(in[i]);
		}
		else
		{
			if(!S.count(in[i]))
				S.insert(in[i]);
		}

		int biggest = S.empty() ? 0 : *S.rbegin();

		if(biggest > in[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES\n";
	
	FORN(i,n) cout << in[i] << " \n"[i==n-1];
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
