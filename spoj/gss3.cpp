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
	int range_sum;
	int max_prefix_sum;
	int max_suffix_sum;
	int max_sum;
};

int n, m, a, b, c;
vi in;
vector<st_node> st;

int st_size()
{
	int sz = 1;
	for(; sz<n; sz<<=1);
	return sz<<1;
}

void merge(st_node& res, const st_node& lhs, const st_node& rhs)
{
	res.range_sum = lhs.range_sum + rhs.range_sum;
	res.max_prefix_sum = max(lhs.max_prefix_sum, lhs.range_sum + rhs.max_prefix_sum);
	res.max_suffix_sum = max(rhs.max_suffix_sum, lhs.max_suffix_sum + rhs.range_sum);
	res.max_sum = max(res.max_prefix_sum, max(res.max_suffix_sum, max(lhs.max_sum, max(rhs.max_sum, lhs.max_suffix_sum + rhs.max_prefix_sum))));
}

void build(int node, int lo, int hi)
{
	st_node& nd=st[node];
	
	if(lo == hi)
		nd.range_sum = nd.max_prefix_sum = nd.max_suffix_sum = nd.max_sum = in[lo];
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
	st_node& nd = st[node];

	if(lo==hi)
	{
		in[lo] = val;
		nd.range_sum = nd.max_prefix_sum = nd.max_suffix_sum = nd.max_sum = in[lo];
		return;
	}

	int left=node<<1, right=left+1, mid=(lo+hi)/2;

	if(index <= mid)
		update(left,lo,mid,index,val);
	else
		update(right,mid+1,hi,index,val);

	merge(nd,st[left],st[right]);
}

st_node query(int node, int lo, int hi, int glo, int ghi)
{
	if(lo==glo && hi==ghi)
		return st[node];

	int mid = (lo+hi)/2;

	if(glo>mid)
		return query((node<<1)+1,mid+1,hi,glo,ghi);
	else if(ghi <= mid)
		return query(node<<1,lo,mid,glo,ghi);

	st_node res;
	st_node l = query(node<<1,lo,mid,glo,mid);
	st_node r = query((node<<1)+1,mid+1,hi,mid+1,ghi);
	
	merge(res,l,r);
	
	return res;
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
	
	cin >> m;

	while(m--)
	{
		cin >> a >> b >> c;

		if(!a)
			update(1,0,n-1,b-1,c);
		else
			cout << query(1,0,n-1,b-1,c-1).max_sum << endl;
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
