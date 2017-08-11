#include <bits/stdc++.h>

using namespace std;

int n,m, p[10010], l[10100], s[10100];

int score[50010][110];
bool pos[50010][110];
int say[50010][110];
int par[50010][110];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>m>>n;


        memset(pos, 0, sizeof(pos));
        memset(score, 0, sizeof(score));
        memset(par, 0, sizeof(par));
        memset(say, 0, sizeof(say));



        pos[0][0] = true;

        for(int i = 1; i <= n; ++i){
            cin>>p[i]>>l[i]>>s[i];
        }


        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                pos[j][i] = pos[j][i-1];
                say[j][i] = say[j][i-1];
                par[j][i] = par[j][i-1];
                score[j][i] = score[j][i-1];
            }

            for(int j = 0; j <= m; ++j){
                if(pos[j][i-1] == true){
                    for(int k = 1; k <= p[i]; ++k){
                        if(score[j + k * l[i]][i] < score[j][i-1] + k * s[i]){
                            score[j + k * l[i]][i] = score[j][i-1] + k * s[i];
                            par[j + k * l[i]][i] = i;
                            say[j + k * l[i]][i] = k;
                            pos[j + k * l[i]][i] = true;
                        }
                    }
                }
            }
        }

        int cur = 0, idx;
        for(int i = 0; i <= m; ++i)
            if(score[i][n] > cur)
                cur = score[i][n], idx = i;

        int ans[10010];
        int cnt = 0;
        int vvv = n;
        while(idx != 0){
            for(int i = 1; i <= say[idx][vvv]; ++i)
                ans[++cnt] = par[idx][vvv];
            int temp = idx;
            idx = idx - l[par[idx][vvv]] * say[idx][vvv];
            vvv = par[temp][vvv] - 1;
            if(idx < 0)
                while(true);
        }

        sort(ans + 1, ans + 1 + cnt);

        cout<<"Case #"<<c<<":";
        for(int i = 1; i <= cnt; ++i)
            cout<<" "<<ans[i];
        cout<<endl;
    }


    return 0;
}
