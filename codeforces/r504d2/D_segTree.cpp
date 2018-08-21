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

int n, q;
vi in, left_pos, right_pos, segtree;

int segtree_size(int N)
{
	int sz = 1;
	for(; sz<N; sz<<=1);
	return sz<<1;
}

void build(int node, int lo, int hi)
{
	if(lo==hi)
		segtree[node] = in[lo];
	else
	{
		int left=node<<1, right=left+1, mid=(lo+hi)/2;
		
		build(left, lo, mid);
		build(right, mid+1, hi);
		
		segtree[node] = min(segtree[left], segtree[right]);
	}
}

int query(int node, int lo, int hi, int qlo, int qhi)
{
	if(lo>qhi || hi<qlo)
		return INF;

	if(lo>=qlo && hi<=qhi)
		return segtree[node];

	int left=node<<1, right=left+1, mid=(lo+hi)/2;

	if(qhi <= mid)
		return query(left,lo,mid,qlo,qhi);
	else if(qlo > mid)
		return query(right,mid+1,hi,qlo,qhi);
	
	int res_left = query(left,lo,mid,qlo,mid);
	int res_right = query(right,mid+1,hi,mid+1,qhi);

	return min(res_left, res_right);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
    
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int tt = clock();
#endif

	cin >> n >> q;

	in.assign(n,0);
	
	int z_pos=-1, q_pos=-1;
	
	FORN(i,n)
	{
		cin >> in[i];
		if(!in[i]) z_pos = i;
		if(in[i]==q) q_pos = i;
	}

	if(q_pos==-1 && z_pos==-1)
	{
		cout << "NO" << endl;
		return 0;
	}
	else if(q_pos == -1)
		in[z_pos] = q; // fix no q

	left_pos.assign(q+1,-1);
	right_pos.assign(q+1,-1);
	
	FORN(i,n)
	{
		if(!in[i])
			in[i] = !i ? 1 : in[i-1]; // fix zeros

		right_pos[in[i]] = i;
		if(left_pos[in[i]] == -1)
			left_pos[in[i]] = i;
	}

	segtree.assign(segtree_size(n),0);
	build(1,0,n-1);
	
	FORE(i,1,q+1)
	{
		int mi = query(1,0,n-1,left_pos[i],right_pos[i]);

		if(mi < i)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	
	FORN(i,n)
		cout << in[i] << " \n"[i==n-1];
	
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
