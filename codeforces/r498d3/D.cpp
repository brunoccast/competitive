/*
 * D: Two String Swaps
 * - implementation
 */

#include <iostream>
#include <map>
#define MAXN 100005

using namespace std;

int main()
{
	int n;
	char a[MAXN], b[MAXN];
	map<char,int> ch;
	
	cin >> n >> a >> b;

	int sol=0;

	for(int i=0; i<n/2; ++i)
	{
		ch[a[i]]++; ch[a[n-i-1]]++;
		ch[b[i]]++; ch[b[n-i-1]]++;

		if(ch.size() == 4)
			sol += 2;
		else if(ch.size() == 3)
			sol += 1 + (a[i] == a[n-i-1]); // preprocess before changes
		else if(ch.size() == 2)
			sol += (ch[a[i]] != 2);

		ch.clear();
	}

	if(n%2 && a[n/2] != b[n/2])
		sol++;

	cout << sol << endl;
	
	return 0;
}
