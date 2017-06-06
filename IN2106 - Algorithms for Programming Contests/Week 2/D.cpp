#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;

vector<pair<int, int> > v[MAX];
bool used[MAX];
int timee[MAX], lowest[MAX];
vector<int> ans;
int cnt;

void dfs(int cur, int par){
    used[cur] = true;
    timee[cur] = lowest[cur] = ++cnt;
    int len = v[cur].size();
    for(int i = 0; i < len; ++i){
        int to = v[cur][i].first, idx = v[cur][i].second;
        if(used[to] == false){
            dfs(to, cur);
            lowest[cur] = min(lowest[cur], lowest[to]);
            if(lowest[to] > timee[cur])
                ans.push_back(idx);

        } else{
            if(to != par)
                lowest[cur] = min(lowest[cur], timee[to]);
        }
    }
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t,n,m,x,y;
    cin>>t;

    for(int c = 1; c <= t; c ++){
        ans.clear();
        memset(used, 0, sizeof(used));
        cin>>n>>m;
        cnt = 0;
        for(int i = 1; i <= n; ++i)
            v[i].clear();
        for(int i = 0; i < m; ++i){
            cin>>x>>y;
            v[x].push_back(make_pair(y, i+1));
            v[y].push_back(make_pair(x, i+1));
        }
        for(int i = 1; i <= n; ++i)
            if(used[i] == false)
                dfs(i, 0);

        cout.precision(12);
        cout<<fixed<<"Case #"<<c<<":";
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
            cout<<" "<<ans[i];
        cout<<endl;

    }

    return 0;
}