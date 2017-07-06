#include <bits/stdc++.h>

using namespace std;

#define forr(A,B,C) for(int A = (B);A<(C);A++)
#define contains(A,B) (A.find(B) != A.end())
typedef tuple<int,int,int> iii;

int lastcon = 0;
map<string, int> cons;
const int MAXN = 300;

vector<int> G[MAXN];
int N,M;

bool dfs(int from, int to)
{
	vector<bool> vis(MAXN);
	stack<int> ms;
	ms.push(from);
	
	while(!ms.empty())
	{
		int cur = ms.top();
		ms.pop();
		if (vis[cur])
			continue;
		vis[cur] = true;
		
		if (cur == to)
			return true;
		
		for (int to : G[cur])
		{
			if (vis[to])
				continue;
			ms.push(to);
		}
	}
	return false;
}

int main()
{
	cin>>N>>M;
	
	forr(i,0,N)
	{
		string sa,sb,temp;
		cin>>sa>>temp>>temp>>temp>>sb;
		int a,b;
		
		if (!contains(cons, sa))
		{
			a = cons[sa] = lastcon;
			lastcon++;
		}
		else
			a = cons[sa];
		
		if (!contains(cons, sb))
		{
			b = cons[sb] = lastcon;
			lastcon++;
		}
		else
			b = cons[sb];
		
		G[a].push_back(b);
	}
	
	
	forr(i,0,M)
	{
		string sa,sb,temp;
		cin>>sa>>temp>>temp>>temp>>sb;
		int a,b;
		
		if (!contains(cons, sa))
		{
			a = -1;
		}
		else
			a = cons[sa];
		
		if (!contains(cons, sb))
		{
			b = -1;
		}
		else
			b = cons[sb];
		
		if (a == -1 || b == -1)
		{
			cout << "Pants on Fire" << endl;
			continue;
		}
		
		if (dfs(a,b))
		{
			cout << "Fact" << endl;
		}
		else if (dfs(b,a))
		{
			cout << "Alternative Fact" << endl;
		}
		else
		{
			cout << "Pants on Fire" << endl;
		}
	}
}


















