#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;

int n, m;
bool used[MAX];
int cnt[MAX];
int value[MAX], ans;
vector<int> v[MAX];

void bfs(){
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(cnt[i] == 0)
            q.push(i), used[i] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans += value[cur];
        int len = v[cur].size();
        for(int i = 0; i < len; ++i){
            if(used[v[cur][i]] == false){
                --cnt[v[cur][i]];
                if(cnt[v[cur][i]] == 0)
                    q.push(v[cur][i]), used[v[cur][i]] = true;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, x, y;

    cin>>t;

    for(int c = 1; c <= t; c ++){
        ans = 0;
        memset(used, 0, sizeof(used));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++i)
            v[i].clear();
        cin>>n>>m;
        for(int i = 1; i <= n; ++i)
            cin>>value[i];
        for(int i = 0; i < m; ++i){
            cin>>x>>y;
            ++cnt[y];
            v[x].push_back(y);
        }
        bfs();
        cout<<fixed<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}