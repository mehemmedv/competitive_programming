#include <bits/stdc++.h>

using namespace std;

int link[1000000][27], cnt;

void add(string s){
    int len = s.size();
    int cur = 0;
    int pos;
    for(int i = 0; i < len; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z')
            pos = s[i] - 'A';
        else
            pos = s[i] - 'a';

        if(link[cur][pos] == 0){
            link[cur][pos] = ++cnt;
            cur = cnt;
        } else
            cur = link[cur][pos];
    }
}

string s[100100];

int main()
{


    int t, n;
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cnt = 0;

        memset(link, 0, sizeof(link));
        cin>>n;

        for(int i = 1; i <= n; ++i){
            cin>>s[i];
            add(s[i]);
        }
        string temp;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            temp = s[i];

            int len = temp.size();
            int cur = 0;
            int pos;
            for(int i = 0; i < len; ++i){
                if(temp[i] >= 'A' && temp[i] <= 'Z')
                    pos = temp[i] - 'A';
                else
                    pos = temp[i] - 'a';

                cur = link[cur][pos];
            }
            for(int i = 0; i < 27; ++i)
            if(link[cur][i] > 0){
                ans++;
                break;
            }

        }
        cout<<"Case #"<<c<<": "<<ans<<endl;

    }


    return 0;
}
