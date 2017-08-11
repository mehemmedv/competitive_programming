#include <bits/stdc++.h>

using namespace std;

struct obj{
    int q, w;
} l[50010];

int dp[1000000];

bool f(obj lll, obj rrr){
    if(lll.q > rrr.q)
        return false;
    if(lll.q == rrr.q && lll.w < rrr.w)
        return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cost, n;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>n;
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; ++i){
            cin>>l[i].q>>l[i].w;
        }

        sort(l + 1, l + 1 + n, f);




        int ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = l[i].w + 1; j <= 20000; ++j)
                dp[l[i].w] = max(dp[l[i].w], 1 + dp[j]);
            ans = max(ans, dp[l[i].w]);
        }

        cout<<"Case #"<<c<<": "<<ans<<endl;

    }


    return 0;
}
