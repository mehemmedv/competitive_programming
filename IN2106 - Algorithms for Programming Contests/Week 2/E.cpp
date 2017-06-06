#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;

int val[MAX], w[MAX], par[MAX];
bool used[MAX];

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void join(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)
        return;
    if(w[fx] > w[fy])
        par[fy] = fx, w[fx] += w[fy];
    else
        par[fx] = fy, w[fy] += w[fx];
}

int enemy[MAX][2];
int cnt;

vector<int> v[MAX];

void dfs(int cur, int root, int step){
    if(step % 2 == 0){
        if(cur != root)
            w[root] += w[cur];
    }
    used[cur] = true;
    int len = v[cur].size();
    for(int i = 0; i < len; ++i){
        if(used[v[cur][i]] == false)
            dfs(v[cur][i], root, step + 1);
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m, x ,y;
    cin >> t;
    char ch;

    for(int c = 1; c <= t; c ++){
        memset(w, 0, sizeof(w));
        memset(used, 0, sizeof(used));
        cin>>n>>m;
        cnt = 0;

        for(int i = 1; i <= n; ++i)
            par[i] = i, w[i] = 1, v[i].clear();

        for(int i = 0; i < m; ++i){
            cin>>ch>>x>>y;
            if(ch == 'F')
                join(x, y);
            else
                enemy[++cnt][0] = x, enemy[cnt][1] = y;
        }

        for(int i = 1; i <= cnt; ++i){
            int fir = find(enemy[i][0]);
            int sec = find(enemy[i][1]);
            v[fir].push_back(sec);
            v[sec].push_back(fir);
        }

        dfs(find(1), find(1), 0);


        cout<<"Case #"<<c<<": ";
        if(w[find(1)] > n / 2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}