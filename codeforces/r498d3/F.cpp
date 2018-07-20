/*
 * F: Xor-Paths
 * - Meet in the middle
 */

#include <iostream>
#include <map>

#define MAXN 20
#define ll long long

using namespace std;

int n, m, mid;
ll sol, k, board[MAXN][MAXN];
map<ll,int> xors[MAXN][MAXN];

// bottom right
void calcbr(int i, int j, ll sum, int times)
{
	sum ^= board[i][j];
	
	if(times == mid)
	{
		xors[i][j][sum]++;
		return;
	}

	if(i+1 < n)
		calcbr(i+1, j, sum, times+1);
	if(j+1 < m)
		calcbr(i, j+1, sum, times+1);
}

// top left
void calctl(int i, int j, ll sum, int times)
{
	if(times == n+m-2-mid)
	{
		if(xors[i][j].count(k^sum))
			sol += xors[i][j][k^sum];
		return;
	}

	if(i > 0)
		calctl(i-1, j, sum^board[i][j], times+1);
	if(j > 0)
		calctl(i, j-1, sum^board[i][j], times+1);
}

int main()
{
	cin >> n >> m >> k;

	for(int i=0; i!=n; ++i)
		for(int j=0; j!=m; ++j)
			cin >> board[i][j];

	mid = (n+m-2)/2;

	calcbr(0, 0, 0, 0);
	calctl(n-1, m-1, 0, 0);

	cout << sol << endl;
	
	return 0;
}
