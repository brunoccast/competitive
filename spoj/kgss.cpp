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

int n, q, a, b;
char c;
vi in;
vii st;

int st_size()
{
	int sz=1;
	for(; sz<n; sz<<=1);
	return sz<<1;
}

void merge(ii& res, const ii& lhs, const ii& rhs)
{
	res.first = max(lhs.first, rhs.first);
	res.second = max(lhs.second, max(rhs.second, lhs.first+rhs.first));
}

void build(int node, int lo, int hi)
{
	ii& nd = st[node];
	
	if(lo==hi)
		nd.first = nd.second = in[lo];
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;

		build(left,lo,mid);
		build(right,mid+1,hi);

		merge(nd,st[left],st[right]);
	}
}

void update(int node, int lo, int hi, int index, int val)
{
	ii& nd = st[node];
	
	if(lo == hi)
	{
		in[lo] = val;
		nd.first = nd.second = in[lo];
	}
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;

		if(index <= mid)
			update(left,lo,mid,index,val);
		else
			update(right,mid+1,hi,index,val);

		merge(nd,st[left],st[right]);
	}
}

ii query(int node, int lo, int hi, int qlo, int qhi)
{
	if(lo==qlo && hi==qhi)
		return st[node];

	int left=node<<1, right=left+1, mid=(lo+hi)/2;

	if(qhi <= mid)
		return query(left,lo,mid,qlo,qhi);
	else if(qlo > mid)
		return query(right,mid+1,hi,qlo,qhi);
	else
	{
		ii ret, l, r;
		
		l=query(left,lo,mid,qlo,mid);
		r=query(right,mid+1,hi,mid+1,qhi);

		merge(ret,l,r);

		return ret;
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

	cin >> n;

	in.assign(n,0);
		
	FORN(i,n) cin >> in[i];
	
	st.resize(st_size());
	build(1,0,n-1);
	
	cin >> q;

	while(q--)
	{
		cin >> c >> a >> b;

		if(c == 'U')
			update(1,0,n-1,a-1,b);
		else
			cout << query(1,0,n-1,a-1,b-1).second << endl;
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
