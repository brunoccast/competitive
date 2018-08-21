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

struct st_node
{
	ii brck;
	bool valid;
};

int n, q, k;
char c;
vi in;
vector<st_node> st;

int st_size()
{
	int sz=1;
	for(; sz<n; sz<<=1);
	return sz<<1;
}

void merge(st_node& res, const st_node& lhs, const st_node& rhs)
{
	int mi = min(lhs.brck.first, rhs.brck.second);
	res.brck.first = lhs.brck.first + rhs.brck.first - mi;
	res.brck.second = lhs.brck.second + rhs.brck.second - mi;
	res.valid = (!res.brck.first && !res.brck.second);
}

void build(int node, int lo, int hi)
{
	st_node& nd = st[node];
	
	if(lo==hi)
	{
		nd.brck.first = !in[lo];
		nd.brck.second = in[lo];
		nd.valid = false;
	}
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;

		build(left,lo,mid);
		build(right,mid+1,hi);

		merge(nd,st[left],st[right]);
	}
}

void update(int node, int lo, int hi, int index)
{
	st_node& nd = st[node];
	
	if(lo == hi)
	{
		in[lo] = !in[lo];
		nd.brck.first = !in[lo];
		nd.brck.second = in[lo];
	}
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;

		if(index <= mid)
			update(left,lo,mid,index);
		else
			update(right,mid+1,hi,index);

		merge(nd,st[left],st[right]);
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	FORN(i,10)
	{
		cin >> n;

		in.assign(n+1,0);
		
		FORN(j,n)
		{
			cin >> c;
			if(c==')') in[j]=1;
		}

		st.resize(st_size());
		build(1,0,n-1);

		cin >> q;

		cout << "Test " << i+1 << ":" << endl;
		
		FORN(j,q)
		{
			cin >> k;

			if(k)
				update(1,0,n-1,k-1);
			else
				cout << ( st[1].valid ? "YES" : "NO" ) << endl;
		}
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
