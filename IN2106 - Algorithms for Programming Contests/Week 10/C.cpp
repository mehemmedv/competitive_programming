#include <bits/stdc++.h>

using namespace std;

string str1[210], str2[210];

int say[10][10];

int dp[600][20];
bool dppos[600][20];

int pos[6][6];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;

    for(int i = 1; i <= 4; ++i)
    for(int j = i; j <= 4; ++j)
        pos[i][j] = ++cnt;


    int t, n, m, idx1, idx2;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        memset(say, 0, sizeof(say));
        memset(dppos, 0, sizeof(dppos));

        cin>>n>>m;

        for(int i = 1; i <= n; ++i)
            cin>>str1[i];

        int len = str1[1].size();

        for(int i = 1; i <= m; ++i)
            cin>>str2[i];

        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            for(int k = 0; k < len; ++k){
                if(str1[i][k] == 'A')
                    idx1 = 1;
                if(str1[i][k] == 'C')
                    idx1 = 2;
                if(str1[i][k] == 'T')
                    idx1 = 3;
                if(str1[i][k] == 'G')
                    idx1 = 4;

                if(str2[j][k] == 'A')
                    idx2 = 1;
                if(str2[j][k] == 'C')
                    idx2 = 2;
                if(str2[j][k] == 'T')
                    idx2 = 3;
                if(str2[j][k] == 'G')
                    idx2 = 4;

                ++say[idx1][idx2];
                if(idx1 != idx2)
                    ++say[idx2][idx1];
            }
        }

        dppos[300][0] = true;

        for(int i = 0; i < 600; ++i)
            for(int j = 0; j < 20; ++j)
                dp[i][j] = -2000000000;

        dp[300][0] = 0;

        int idx;
        for(int i = 1; i <= 4; ++i)
        for(int j = i; j <= 4; ++j){
            idx = pos[i][j];
            for(int k = 0; k < 550; ++k){
                if(i == j){
                    for(int o = 0; o <= 10; ++o)
                        dp[k + o][idx] = max(dp[k + o][idx], dp[k][idx-1] + (o * say[i][j]));
                }
                else{
                    for(int o = -10; o <= 10; ++o)
                        dp[k + 2*o][idx] = max(dp[k + 2*o][idx], dp[k][idx-1] + (o * say[i][j]));
                }
            }
        }
        cout<<"Case #"<<c<<": "<<dp[300][cnt]<<endl;
    }

    return 0;
}
