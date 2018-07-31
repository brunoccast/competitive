#include <bits/stdc++.h>

using namespace std;

#define FORN(i,n) for(int i=0; i!=int(n); ++i)
#define FORE(i,l,r) for(int i=int(l); i!=int(r); ++i)

#define MAXLEN 200005

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
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	char input[MAXLEN];
	int ans = 0;

	cin >> input;

	int one = 0, two = 0;
	size_t len = strlen(input);
	
	FORN(i,len)
	{
		int x = (int)(input[i]-'0');
		bool valid = false;
		
		if(x%3 == 0)
			valid = true;
		else if(x%3 == 1)
		{
			if(one >= 2 || two >= 1)
			   valid = true;

			one++;
		}
		else
		{
			if(two >= 2 || one >= 1)
				valid = true;
			
			two++;
		}

		if(valid)
		{
			ans++;
			one = two = 0;
		}
	}

	cout << ans << endl;
	
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
