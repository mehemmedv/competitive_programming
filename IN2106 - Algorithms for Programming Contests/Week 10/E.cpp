#include <bits/stdc++.h>

using namespace std;

bool used[2500];
int ans;
vector<pair<int, int> > v[2500];
int x, y, z;
int val[2500], dis[2500];

void bfs(int ver){
    queue<int> q;

    q.push(ver);

    while(!q.empty()){
        int cur_ver = q.front();
        q.pop();
        int cost = val[cur_ver];
        used[cur_ver] = true;

        for(int i = 0; i < v[cur_ver].size(); ++i){

            int fut_ver = v[cur_ver][i].first;
            int cost_move = v[cur_ver][i].second;
            if(used[fut_ver] == false){
                used[fut_ver] = true;
                val[fut_ver] = cost + cost_move;
                dis[fut_ver] = dis[cur_ver] + 1;
                q.push(fut_ver);
            } else{
                if(val[fut_ver] != cost+cost_move){
                    ans = min(dis[fut_ver] + dis[cur_ver] + 1, ans);
                }
            }
        }

    }
}

int main()
{
    int t, n, m, s;
    cin>>t;

    for(int c = 1; c <= t; ++c)
    {
        ans = 2000000000;
        memset(used, 0, sizeof(used));
        memset(val, 0, sizeof(val));
        memset(dis, 0, sizeof(dis));

        for(int i = 0; i <= 2300; ++i)
            v[i].clear();

        cin>>n>>m>>s;

        for(int i = 1; i <= m; ++i){
            cin>>x>>y>>z;
            v[x].push_back(make_pair(y, z));
            if(x != y)
                v[y].push_back(make_pair(x, -z));
        }
        bfs(s);
        if(ans == 2000000000){
            cout<<"Case #"<<c<<": possible"<<endl;
        }
        else
            cout<<"Case #"<<c<<": "<<ans<<endl;
    }

    return 0;
}
