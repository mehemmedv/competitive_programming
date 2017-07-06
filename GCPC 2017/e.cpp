#include <bits/stdc++.h>

using namespace std;

#define forr(A,B,C) for(int A = (B);A<(C);A++)
#define contains(A,B) (A.find(B) != A.end())
typedef tuple<int,int,int> iii;
typedef pair<int,int> ii;
typedef long double ld;

const int MAXN = 1000;
const ld EPS = 0.0000001;

vector<pair<int,ld>> G[MAXN];
int N,M;

vector<char> vis;
vector<ld> vsav;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

bool dfsrec(int cur, ld val);

bool dfs(int start)
{
	vis = vector<char>(N+20);
	vsav = vector<ld>(N+20);
	
	return dfsrec(start, 1);
}

bool dfsrec(int cur, ld val)
{
	//printf("%d %d %lf\n",cur, vis[cur], (double)val);
	if (vis[cur] == BLACK)
		return true;
	if (vis[cur] == GRAY)
	{
		if (vsav[cur] < val)
		{
			return false;
		}
		return true;
	}
	vis[cur] = GRAY;
	vsav[cur] = val;
	
	for (auto mii : G[cur])
	{
		int to = mii.first;
		ld cval = mii.second;
		bool res = dfsrec(to, val * cval);
		if (!res)
		{
			vis[cur] = BLACK;
			return false;
		}
	}
	
	vis[cur] = BLACK;
	return true;
}

int main()
{
	cin>>N>>M;
	
	forr(i,0,M)
	{
		int a,b;
		ld c;
		cin>>a>>b>>c;a--;b--;
		G[a].push_back(make_pair(b,c));
	}
	
	bool myres = true;
	
	forr(i,0,N)
	{
		bool res = dfs(i);
		if (!res)
		{
			myres = false;
			break;
		}
	}
	
	if (myres)
		cout << "admissible" << endl;
	else
		cout << "inadmissible" << endl;
}
