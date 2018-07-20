/*
 * E: Military Problem
 * - Graphs, DFS
 */
#include <iostream>
#include <vector>

using namespace std;

int n, q, order;
vector< vector<int> > g;
vector<int> visit_order, first, second;

/**
 * Save, for each node, the start & end time of the DFS visit.
 * Also store node visit order.
 *
 * With this info its easy to check which node was
 * visited k steps after node u and if it belongs
 * to the subtree of u.
 */
void dfs(int node = 0)
{
	visit_order[order] = node;
	// cout << "visit[" << order << "] = " << node << endl;
	
	first[node] = order++;
	// cout << "first[" << node << "] = " << order-1 << endl;

	auto it = g[node].begin();
	for(; it != g[node].end(); ++it)
		dfs(*it);
	
	second[node] = order-1;
	// cout << "second[" << node << "] = " << order-1 << endl;
}

int main()
{
	cin >> n >> q;

	g.resize(n);
	visit_order.resize(n);
	first.resize(n);
	second.resize(n);
	
	for(int i=1; i!=n; ++i)
	{
		int ni; cin >> ni;
		g[ni-1].push_back(i);
	}

	dfs();

	while(q--)
	{
		int u, k;

		cin >> u >> k;
		u--;
		
		int target_pos = first[u]+k-1;
		
		if(target_pos >= n)
			cout << -1;
		else
		{
			int target_node = visit_order[target_pos];

			if(first[target_node] >= first[u] && second[target_node] <= second[u])
				cout << target_node+1;
			else
				cout << -1;
		}

		cout << endl;
	}
			
	return 0;
}
