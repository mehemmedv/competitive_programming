#include <bits/stdc++.h>

using namespace std;

int nums[12][12], t;

vector<pair<int, int> > v;
vector<int> pos[100];
bool flag;

bool check(){
    bool used[10];

    for(int i = 1; i <= 9; ++i){
        memset(used, 0, sizeof(used));
        for(int j = 1; j <= 9; ++j)
            used[nums[i][j]] = true;
        for(int j = 1; j <= 9; ++j)
            if(used[j] == false)
                return false;

        memset(used, 0, sizeof(used));

        for(int j = 1; j <= 9; ++j)
            used[nums[j][i]] = true;
        for(int j = 1; j <= 9; ++j)
            if(used[j] == false)
                return false;
    }

    for(int i = 1; i <= 3; ++i)
        for(int j = 1; j <= 3; ++j){
            memset(used, 0, sizeof(used));

            for(int o = 3 * (i-1) + 1; o < 3 * i + 1; ++o){
                for(int p = 3 * (j-1) + 1; p < 3 * j + 1; ++p){
                    used[nums[o][p]] = true;
                }
            }

            for(int o = 1; o <= 9; ++o)
                if(used[o] == false)
                    return false;
        }

    return true;
}

void dfs(int cur, int last){
    if(cur > last){
        if(check() == true)
            flag = true;
        return;
    }
    int x = v[cur].first;
    int y = v[cur].second;
    for(int i : pos[cur]){
        nums[x][y] = i;
        dfs(cur + 1, last);
        if(flag == true)
            return;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    char ch;
    for(int c = 1; c <= t; ++c){
        flag = false;
        v.clear();

        for(int i = 1; i <= 9; ++i)
            for(int j = 1; j <= 9; ++j){
                cin>>ch;
                if(ch == '?'){
                    nums[i][j] = 0;
                    v.push_back(make_pair(i, j));
                }
                else{
                    nums[i][j] = ch - '0';

                }
            }
        int cnt = 0;
        for(int i = 0; i < v.size(); ++i){
            bool used[10];
            memset(used, 0, sizeof(used));
            pos[i].clear();
            int x = v[i].first;
            int y = v[i].second;
            for(int j = 1; j < 10; ++j)
                used[nums[x][j]] = true, used[nums[j][y]] = true;

            int x1, y1;
            if(x % 3 == 0)
                x1 = x/3;
            else
                x1 = x/3 + 1;
            if(y % 3 == 0)
                y1 = y/3;
            else
                y1 = y/3 + 1;
            for(int o = 3 * (x1-1) + 1; o < 3 * x1 + 1; ++o){
                for(int p = 3 * (y1-1) + 1; p < 3 * y1 + 1; ++p){
                    used[nums[o][p]] = true;
                }
            }
            for(int j = 1; j < 10; ++j)
                if(used[j] == false)
                    pos[i].push_back(j);
        }
        dfs(0, v.size() - 1);
        assert(flag != false);
        cout<<"Case #"<<c<<":"<<endl;
        for(int i = 1; i <= 9; ++i){
            for(int j = 1; j <= 9; ++j)
                cout<<nums[i][j];
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}