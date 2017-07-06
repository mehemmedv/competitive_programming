#include <bits/stdc++.h>

using namespace std;

int n,m;

int l[1010], s[1010], score[100010], par[100010];

int elem[100010];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>m>>n;

        memset(score, 0, sizeof(score));
        memset(par, 0, sizeof(par));

        for(int i = 1; i <= n; ++i)
            cin>>l[i]>>s[i];

        for(int i = 0; i <= m; ++i){
            if(score[i] > 0 || i == 0){
                for(int j = 1; j <= n; ++j){
                    if(i + l[j] <= m)
                        if(score[i+l[j]] < score[i] + s[j])
                            score[i+l[j]] = score[i] + s[j], par[i+l[j]] = j;
                }
            }
        }

        int idx = 0;

        for(int i = 1; i <= m; ++i)
            if(score[i] > score[idx])
                idx = i;
        int cnt = 0;

        while(idx != 0){
            elem[++cnt] = par[idx];
            idx = idx - l[par[idx]];
        }

        sort(elem+1, elem+1+cnt);

        cout<<"Case #"<<c<<":";
        for(int i = 1; i <= cnt; ++i)
            cout<<" "<<elem[i];
        cout<<endl;

    }


    return 0;
}
