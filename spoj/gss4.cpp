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
 
int n, q, a, b, c, t;
vll in(100005), st(262144);
 
/*
int st_size()
{
    int sz=1;
    for(; sz<n; sz<<=1);
    return sz<<1;
}
*/
 
inline void merge(ll& res, ll lhs, ll rhs)
{
    res = lhs+rhs;
}
 
void build(int node, int lo, int hi)
{
    if(lo==hi)
        st[node] = in[lo];
    else
    {
        int left=node<<1, right=left+1, mid=(lo+hi)/2;
 
        build(left,lo,mid);
        build(right,mid+1,hi);
 
        merge(st[node],st[left],st[right]);
    }
}
 
/* discard update if useless (no change)
   - in this case if node sum equals range size,
   - meaning that every child is value 1. Sqrt
   - operation won't do anything to nodes with
   - value 1, so sum won't change.
*/
void lazy_update(int node, int lo, int hi)
{
    if(st[node] == hi-lo+1)
        return; // no need to update
 
    if(lo==hi)
        st[node] = sqrt(st[node]);
    else
    {
        int left=node<<1, right=left+1, mid=(lo+hi)/2;
 
        lazy_update(left,lo,mid);
        lazy_update(right,mid+1,hi);
 
        merge(st[node],st[left],st[right]);
    }
}
 
void update(int node, int lo, int hi, int qlo, int qhi)
{
    if(lo==qlo && hi==qhi)
        lazy_update(node,lo,hi);
    else
    {
        int left=node<<1, right=left+1, mid=(lo+hi)/2;
 
        if(qhi<=mid)
            update(left,lo,mid,qlo,qhi);
        else if(qlo>mid)
            update(right,mid+1,hi,qlo,qhi);
        else
        {
            update(left,lo,mid,qlo,mid);
            update(right,mid+1,hi,mid+1,qhi);
 
            merge(st[node],st[left],st[right]);
        }
    }
}
 
ll query(int node, int lo, int hi, int qlo, int qhi)
{
    if(lo==hi)
        return st[node];
 
    int left=node<<1, right=left+1, mid=(lo+hi)/2;
 
    if(qhi<=mid)
        return query(left,lo,mid,qlo,qhi);
    else if(qlo>mid)
        return query(right,mid+1,hi,qlo,qhi);
    else
    {
        ll ret, l, r;
 
        l = query(left,lo,mid,qlo,mid);
        r = query(right,mid+1,hi,mid+1,qhi);
 
        merge(ret,l,r);
 
        return ret;
    }
}
 
int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(0); // turn on for C IO
   
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
 
    int tt = clock();
#endif
   
    while(scanf("%d",&n) != EOF)
    {
        // in.assign(n,0);
       
        FORN(i,n) scanf("%lld",&in[i]);
 
        // st.assign(st_size(),0);
        build(1,0,n-1);
 
        scanf("%d",&q);
        printf("Case #%d:\n", ++t);
       
        while(q--)
        {
            scanf("%d %d %d", &a, &b, &c);
 
            if(!a)
                update(1,0,n-1,b-1,c-1);
            else
                printf("%lld\n", query(1,0,n-1,b-1,c-1));
        }
 
        putchar('\n');
    }
 
#ifdef DEBUG
    tt = clock() - tt;
    cerr << (double)tt/CLOCKS_PER_SEC << " seconds!" << endl;
#endif
}
