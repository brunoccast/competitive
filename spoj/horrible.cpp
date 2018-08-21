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
	int lo, hi;
	ll total, pending_sum;

	st_node() : lo(-1), hi(-1), total(0), pending_sum(0) {}
	
	int range() const { return hi-lo+1; }
	bool has_update() const { return pending_sum>0; }
	void update() { total+=pending_sum*range(); pending_sum=0; } // DONT FORGET CLEAR UPDATE!
};

int t, n, q, a, b, c, d;
vector<st_node> st;

int st_size()
{
	int sz=1;
	for(;sz<n;sz<<=1);
	return sz<<1;
}

void merge(st_node& res, const st_node& lhs, const st_node& rhs)
{
	res.total = lhs.total+rhs.total;
	if(lhs.has_update())
		res.total += lhs.pending_sum*lhs.range();
	if(rhs.has_update())
		res.total += rhs.pending_sum*rhs.range();
}

void build(int node, int lo, int hi)
{
	st_node& nd = st[node];
	nd.lo=lo; nd.hi=hi;
	
	if(lo==hi)
		nd.total = nd.pending_sum = 0;
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;

		build(left,lo,mid);
		build(right,mid+1,hi);

		merge(nd,st[left],st[right]);
	}
}

void update(int node, int qlo, int qhi, int val)
{
	st_node& nd=st[node];
		
	if(nd.lo==qlo && nd.hi==qhi)
	{
		// lazy, pending propagation on range
		nd.pending_sum += val;
		return;
	}

	int left=node<<1, right=left+1, mid=(nd.lo+nd.hi)/2;

	if(qhi<=mid)
		update(left,qlo,qhi,val);
	else if(qlo>mid)
		update(right,qlo,qhi,val);
	else
	{
		update(left,qlo,mid,val);
		update(right,mid+1,qhi,val);
	}

	merge(nd,st[left],st[right]);
}

st_node query(int node, int qlo, int qhi)
{
	st_node& nd=st[node];
	st_node ret;
	
	if(nd.lo==qlo && nd.hi==qhi)
	{
		ret = nd;
		
		if(ret.has_update())
			ret.update();	

		return ret;
	}
	
	int left=node<<1, right=left+1, mid=(nd.lo+nd.hi)/2;

	if(qhi<=mid)
		ret = query(left,qlo,qhi);
	else if(qlo>mid)
		ret = query(right,qlo,qhi);
	else
	{
		st_node l, r;

		l=query(left,qlo,mid);
		r=query(right,mid+1,qhi);

		ret.lo=l.lo;
		ret.hi=r.hi;
		
		merge(ret,l,r);
	}

	if(nd.has_update())
	{
		ret.pending_sum += nd.pending_sum;
		ret.update();
	}

	return ret;
}

int main()
{   
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int tt = clock();
#endif

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&n,&q);

		st.clear();
		st.resize(st_size());
		build(1,0,n-1);
		
		while(q--)
		{
			scanf("%d %d %d",&a,&b,&c);

			if(!a)
			{
				scanf("%d",&d);
				update(1,b-1,c-1,d);
			}
			else
				printf("%lld\n",query(1,b-1,c-1).total);
		}
	}
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
