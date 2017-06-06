#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;

int val[MAX], rankk[MAX], par[MAX];
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
    if(rankk[fx] > rankk[fy])
        par[fy] = fx;
    else if(rankk[fy] > rankk[fx])
        par[fx] = fy;
    else
        par[fx] = fy, ++rankk[fy];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, a, b, x, y;
    cin >> t;

    for(int c = 1; c <= t; c ++){
        memset(rankk, 0, sizeof(rankk));
        memset(used, 0, sizeof(used));

        cin>>n>>a>>b;

        for(int i = 1; i <= n; ++i)
            par[i] = i, rankk[i] = 1;

        int ans = -1;



        for(int i = 1; i < n; ++i)
            cin>>val[i];
        for(int i = 0; i < a; ++i){
            cin>>x>>y;
            join(x, y);
        }
        for(int i = 0; i < b; ++i){
            cin>>x>>y;
            join(x, y);
            used[x] = used[y] = true;
        }
        for(int i = 1; i < n; ++i){
            if(used[i] == false && find(i) != find(n))
                ans = max(ans, val[i]);
        }

        cout<<"Case #"<<c<<": ";
        if(ans == -1)
            cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}