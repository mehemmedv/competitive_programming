#include <bits/stdc++.h>
#define MAX 1001000
#define MOD 1000000007
using namespace std;

int n, m, k, l, cur, last;
vector<pair<int, int> > e[10010];
vector<int> d[10010];
int lev[10010];


bool used[10010];

void dfs(int v, int mid){
    used[v] = true;

    cur = max(mid, min(lev[v], cur));

    int len = e[v].size();

    for(int i = 0; i < len; ++i){
        int to = e[v][i].first;
        int level = e[v][i].second;

        if(used[to] == false){
            if(level >= cur){
                dfs(to, mid);
            } else{
                d[level].push_back(to);
            }
        }
    }
}


bool check(int mid){

    dfs(1, mid);
    bool flag;
    while(cur >= mid){
        flag = false;
        for(int i = last; i >= cur; --i){
            for(int j : d[i]){
                if(used[j] == false){
                    dfs(j, mid);
                    flag = true;
                }
            }
        }

        last = cur - 1;
        if(flag == false)
            break;
    }


    for(int i = 1; i <= n; ++i)
        if(used[i] == false)
            return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;
    int t;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>n>>m>>k>>l;

        for(int i = 0; i < 10005; ++i)
            e[i].clear();

        for(int i = 1; i <= m; ++i){
            cin>>x>>y>>z;
            e[x].push_back(make_pair(y, z));
            e[y].push_back(make_pair(x, z));
        }

        for(int i = 0; i <= 10005; ++i)
            lev[i] = 1000000000;

        for(int i = 1; i <= k; ++i){
            cin>>x>>y;
            lev[x] = y;
        }

        int lll = 0, rrr = l;
        int ans = 1000000000;
        while(lll <= rrr){
            for(int i = 0; i <= 10003; ++i)
                d[i].clear();

            memset(used, 0, sizeof(used));

            cur = l;
            last = 10000;

            int mid = (lll + rrr) >> 1;

            if(check(mid) == true){
                ans = mid;
                lll = mid + 1;
            } else
                rrr = mid - 1;
        }
        if(ans == 1000000000)
            cout<<"Case #"<<c<<": impossible"<<endl;
        else
            cout<<"Case #"<<c<<": "<<ans<<endl;
    }


    return 0;
}
