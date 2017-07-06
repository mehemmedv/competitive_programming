#include <bits/stdc++.h>

using namespace std;

int N,D,K;

int main()
{
	cin>>N>>D>>K;
	
	vector<pair<int,string>> mv;
	
	for(int i = 0;i<N;i++)
	{
		string s; int val; cin>>s>>val;
		
		mv.push_back(make_pair(val, s));
	}
	
	sort(mv.begin(), mv.end(), greater<pair<int,string>>());
	
	int msum = 0;
	int fc = 0;
	for(int i = 0;i<K;i++)
	{
		if (msum >= D)
			break;
		msum += mv[i].first;
		fc += 1;
	}
	
	if (msum < D)
	{
		cout << "impossible" << endl;
	}
	else
	{
		cout<<fc << endl;
		for(int i = 0;i<fc;i++)
			cout << mv[i].second << ", YOU ARE FIRED!" << endl;
	}
	
	return 0;
}
