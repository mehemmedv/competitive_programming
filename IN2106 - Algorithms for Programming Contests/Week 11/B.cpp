#include <bits/stdc++.h>

using namespace std;

int dp[1001000], l[10010];
int par[1000100];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cost, n;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>n>>cost;

        for(int i = 1; i <= n; ++i)
            cin>>l[i];

        for(int i = 1; i <= 1000000; ++i)
            dp[i] = 100000000;

        dp[0] = 0;

        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= cost; ++j){
                if(dp[j] < 100000000)
                    if(dp[j+l[i]] > dp[j] + 1)
                        dp[j+l[i]] = dp[j] + 1, par[j+l[i]] = i;
            }
        }


        int ans[10010];
        memset(ans, 0, sizeof(ans));

        int idx = cost;

        while(idx != 0){
            //cout<<idx<<" "<<par[idx]<<endl;
            ans[par[idx]]++;
            idx = idx - l[par[idx]];
        }

        cout<<"Case #"<<c<<":";
        for(int i = 1; i <= n; ++i)
            cout<<" "<<ans[i];
        cout<<endl;
    }


    return 0;
}
