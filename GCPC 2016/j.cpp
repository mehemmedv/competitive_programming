#include <bits/stdc++.h>

using namespace std;

int c, m;
int p[110][110];

int dp[110][110];

int main()
{
    std::ios::sync_with_stdio(false);

    cin>>c>>m;
    for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= c; ++j)
        cin>>p[i][j];

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= c; ++j){
            for(int k = 0; k <= j; ++k)
                dp[i][j] = max(dp[i][j], p[i][k] + dp[i-1][j-k]);
        }
    }

    cout<<dp[m][c]<<endl;


    return 0;
}
