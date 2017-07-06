#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000];
int x, y;
bool used[1000];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        memset(used, 0, sizeof(used));

        cin>>n;
        for(int i = 0; i <= 1000; ++i)
            v[i].clear();
        for(int i = 1; i <= n; ++i){
            cin>>x;
            v[i].push_back(x);
            v[i].push_back(i);

            for(int j = 1; j <= x; ++j){
                cin>>y;
                v[i].push_back(y);

            }
        }

        sort(v + 1, v + 1 + n);

        int ans = 0;

        int len, len2;
        int cur;
        for(int i = n; i > 0; --i){
            int x = v[i][1];
            len = v[i].size();
            len2 = len - 2;
            cur = 0;
            for(int j = 2; j < len; ++j){
                if(used[v[i][j]] == true)
                    ++cur;
            }
            if(ans < ans - cur + len2 - cur){
                used[x] = true;
                ans = ans - cur + len2 - cur;
            }
        }
        vector<int> res;
        for(int i = 1; i <= n; ++i)
            if(used[i] == false)
                res.push_back(i);
        cout<<"Case #"<<c<<":"<<endl;
        cout<<res[0];
        for(int i = 1; i < res.size(); ++i)
            cout<<" "<<res[i];
        cout<<endl;
    }

    return 0;
}
