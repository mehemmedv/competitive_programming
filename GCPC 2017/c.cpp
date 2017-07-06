#include <bits/stdc++.h>

using namespace std;

int x, n,m,t;

vector<int> e[1010];
int cost[1010][1010];
int ttt[1010], ccc[1010];

int a,b;

long long mincost[1010][1010];
bool pos[1010][1010];

int main() {
	cin>>x;
	cin>>n>>m>>t;

	for(int i = 0; i < m; ++i){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i)
		cin>>ttt[i]>>ccc[i];

	for(int i = 0; i < 1010; i++)
	for(int j = 0; j < 1010; j++)
		mincost[i][j] = LLONG_MAX;

	pos[1][0] = true;
	mincost[1][0] = 0;

	for(int i = 0; i <= x; ++i){
		for(int j = 1; j <= n; ++j)
		if(pos[j][i] == true){
			int len = e[j].size();
			for(int o = 0; o < len; ++o){
				int k = e[j][o];

				long long cur_c = ccc[j] + mincost[j][i];
				int ttime = i + t + ttt[j];
				if(ttime <= x){
					pos[k][ttime] = true;
					mincost[k][ttime] = min(mincost[k][ttime], cur_c);
				}
			}
			if(i + ttt[j] <= x){
				pos[j][i + ttt[j]] = true;
				mincost[j][i + ttt[j]] = min(mincost[j][i + ttt[j]], mincost[j][i] + ccc[j]);
			}
		}
	}



	if(pos[1][x-ttt[1]] == true)
		cout<<mincost[1][x-ttt[1]] + ccc[1]<<endl;
	else
		cout<<"It is a trap."<<endl;

	return 0;
}
