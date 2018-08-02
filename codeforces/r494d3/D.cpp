#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int n, q;
vector<int> uniq;
map<int,int> cnt;

int main()
{
	cin >> n >> q;
	
	for(int i=0; i!=n; ++i)
	{
		int ni; cin >> ni;
		if(!cnt.count(ni)) uniq.push_back(ni);
		cnt[ni]++;
	}
	
	sort(uniq.begin(), uniq.end(), greater<int>());
	
	for(int i=0; i!=q; ++i)
	{
		int qi; cin >> qi;
		
		int sum=0, ans=0;
		
		for(auto it=uniq.begin(); it!=uniq.end() && sum<qi; ++it)
		{
			int num = *it;
			if(num > qi-sum) continue;
			int mul = min(cnt[num], (qi-sum)/num);
			sum += mul*num;
			ans += mul;
		}
		
		if(sum == qi)
			cout << ans << endl;
		else 
			cout << "-1" << endl;
	}
	
	return 0;
}
