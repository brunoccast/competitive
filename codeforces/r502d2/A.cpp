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
vii input;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n;
	
	input.resize(n);
	
	FORN(i,n)
	{
		int a,b,c,d;

		cin >> a >> b >> c >> d;
		
		input[i].first = (a+b+c+d)*-1;
		input[i].second = i;
	}

	sort(input.begin(), input.end());
	
	int i=0;
	while(input[i].second != 0) i++;

	cout << i+1 << endl;

#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
