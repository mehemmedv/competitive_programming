#include <bits/stdc++.h>

using namespace std;

long double prob[1010][210];
int n,m, x,y;
char ch;
vector<int> e[1010][30];

string s;

int main()
{
    std::ios::sync_with_stdio(false);

    prob[1][0] = 100;

    cin>>n>>m;

    for(int i = 1; i <= m; ++i){
        cin>>x>>y>>ch;
        e[x][ch-'A'].push_back(y);
        e[y][ch-'A'].push_back(x);
    }

    cin>>s;

    int len = s.size();

    for(int i = 1; i <= len; ++i){
        ch = s[i-1];

        for(int j = 1; j < n; ++j){
            if(e[j][ch-'A'].size() > 0){
                long double prob_temp = 1.0 / (e[j][ch-'A'].size() * 1.0);
                for(int k : e[j][ch-'A']){
                    prob[k][i] += prob[j][i-1] * prob_temp;
                }
            } else{
                prob[j][i] += prob[j][i-1];
            }
        }

    }


    long double ans = 0;
    for(int i = 0; i <= len; ++i)
        ans += prob[n][i];

    cout.precision(6);
    cout<<fixed<<ans<<endl;



    return 0;
}
