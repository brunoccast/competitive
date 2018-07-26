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

char str1[MAXLEN], str2[MAXLEN];

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> str1 >> str2;

	int p1 = (int)strlen(str1)-1;
	int p2 = (int)strlen(str2)-1;

	while(str1[p1] == str2[p2] && p1 >= 0 && p2 >= 0)
	{
		p1--;
		p2--;
	}

	cout << (p1+1)+(p2+1) << endl;
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
