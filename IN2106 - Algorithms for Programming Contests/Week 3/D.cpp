#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int t, n;
int trust[MAX][MAX], dp[MAX], used[MAX], can[MAX];
vector<int> edges[MAX];

void dfs1(int node){
    can[node]=1;
    for(int i = 0; i < edges[node].size(); i++)
        if(!can[edges[node][i]])
            dfs1(edges[node][i]);
}
void dfs2(int node, int root){
    used[node]=1;
    dp[node]=max(dp[node], trust[node][root]);
    for(int i = 0; i < edges[node].size(); i++)
        if(!used[edges[node][i]])
            dfs2(edges[node][i], root);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    for(int c=0; c<t; c ++){
        cin>>n;
        for(int i=1; i<=n; i ++)
            for(int j=1; j<=n; j ++)
                cin>>trust[i][j];

        fill(dp, dp+n+1, 0);
        fill(can, can+n+1, 0);
        for(int i=1; i<=n; i ++)
            edges[i].clear();
        for(int i=1; i<=n; i ++)
            for(int j=1; j<=n; j ++)
                if(trust[i][j] > 0)
                    edges[j].push_back(i);
        dfs1(1);
        for(int i=1; i<=n; i ++){
            if(!can[i])
                continue;
            fill(used, used+n+1, 0);
            dfs2(i, i);
        }
        int sum = 0;
        for(int i = 2; i < n+1; ++i)
            sum += dp[i];
        cout<<"Case #"<<c+1<<": "<<sum<<endl;
    }
    return 0;
}