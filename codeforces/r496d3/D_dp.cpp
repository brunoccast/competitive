#include <bits/stdc++.h>

using namespace std;

#define FORN(i,n) for(int i=0; i!=int(n); ++i)
#define FORE(i,l,r) for(int i=int(l); i!=int(r); ++i)
#define FORR(i,l,r) for(int i=int(l); i>=int(r); --i)

#define MAXN 200005

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INF64 = 1e18;
const ld EPS = 1e-9;

char s[MAXN];
int pre[MAXN], dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> s;

	size_t len = strlen(s);

	FORN(i,len)
	{
		int j=i, sum=0;
		for(; j>=0; --j)
		{
			sum += (int)(s[j]-'0');
			if(sum%3 == 0) break;
		}

		if(j>=0) pre[i] = i-j+1;
	}

	dp[0] = pre[0];
	
	FORE(i,1,len)
	{
		if(!pre[i])
			dp[i] = dp[i-1];
		else
		{
			int div3 = (int)(s[i]-'0')%3 == 0;
			dp[i] = max(dp[i-pre[i]]+1, dp[i-1]+div3);
		}
	}

	cout << dp[len-1] << endl;

#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif

	return 0;
}
