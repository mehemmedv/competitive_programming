#include <bits/stdc++.h>
#define MAX 1001000
#define MOD 1000000007
using namespace std;


int link[3000000][27], cnt;
int dp[3000000];

void recur(int cur, int player)
{

    int flag = false;

    for(int i = 0; i <= 26; ++i)
        if(link[cur][i] > 0)
        {
            flag = true;
            recur(link[cur][i], 3 - player);
        }

    if(flag == false)
    {
        //cout<<cur<<" xaxa"<<endl;
        dp[cur] = 3 - player;
        return;
    }

    if(cur != -1)
    {
        bool f1 = false, f2 = false, f3 = false, f4 = false;

        for(int i = 0; i <= 26; ++i)
            if(link[cur][i] > 0 )
            {
                if(dp[link[cur][i]] == 1)
                    f1 = true;

                if(dp[link[cur][i]] == 2)
                    f2 = true;

                if(dp[link[cur][i]] == 3)
                    f3 = true;

                if(dp[link[cur][i]] == 4)
                    f4 = true;
            }

        //cout<<cur<<" "<<player<<" "<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;

        if(player == 1)
        {
            //cout<<cur<<" "<<player<<" xaxa  xaxa"<<endl;
            if(f3 == true)
            {
                dp[cur] = 3;
            }
            else if(f1 == true && f2 == true)
            {
                dp[cur] = 3;
            }
            else if(f1 == true)
            {
                dp[cur] = 1;
            }
            else if(f2 == true)
            {
                dp[cur] = 2;
            }
            else
                dp[cur] = 4;
        }
        else
        {
            //cout<<cur<<" "<<player<<" xaxa  xaxa"<<endl;
            if(f4 == true)
            {
                dp[cur] = 4;
            }
            else if(f1 == true && f2 == true)
            {
                dp[cur] = 4;
            }
            else if(f1 == true)
            {
                dp[cur] = 1;
            }
            else if(f2 == true)
            {
                dp[cur] = 2;
            }
            else
                dp[cur] = 3;
        }
    }
    else
    {
        cout<<"xaxaxaax"<<endl;
        bool f1 = false, f2 = false, f3 = false, f4 = false;

        for(int i = 0; i <= 26; ++i)
            if(link[cur][i] > 0 )
            {
                if(dp[link[cur][i]] == 1)
                    f1 = true;

                if(dp[link[cur][i]] == 2)
                    f2 = true;

                if(dp[link[cur][i]] == 3)
                    f3 = true;

                if(dp[link[cur][i]] == 4)
                    f4 = true;
            }

        if(f3 == true)
        {
            dp[cur] = 3;
        }
        else if(f1 == true && f2 == true)
        {
            dp[cur] = 3;
        }
        else if(f1 == true)
        {
            dp[cur] = 1;
        }
        else if(f2 == true)
        {
            dp[cur] = 2;
        }
        else
            dp[cur] = 4;
    }
    //cout<<cur<<" "<<dp_win[cur]<<" "<<dp_lose[cur]<<endl;
}


void add(string s)
{
    int len = s.size();
    int cur = 0;
    int pos;
    for(int i = 0; i < len; ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            pos = s[i] - 'A';
        else
            pos = s[i] - 'a';

        if(link[cur][pos] == 0)
        {
            link[cur][pos] = ++cnt;
            cur = cnt;
        }
        else
            cur = link[cur][pos];
        //cout<<s[i]<<" "<<cur<<" "<<"indiki"<<endl;
    }

    link[cur][26] = ++cnt;
    //cout<<"$ "<<cnt<<" indiki\n";
    //cout<<cur<<" "<<cnt<<endl;

    //recur(s, len, 0, 0);

}

string s[100100];



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z, n, m;
    int t;
    cin>>t;

    for(int c = 1; c <= t; ++c)
    {
        memset(dp, 0, sizeof(dp));

        cnt = 0;
        cin>>n>>m;

        memset(link, 0, sizeof(link));

        for(int i = 1; i <= m; ++i)
        {
            cin>>s[i];
            add(s[i]);
        }

        recur(0, 1);

        cout<<"Case #"<<c<<":"<<endl;

        if(dp[0] == 3)
        {
            //cout<<"case 1"<<endl;
            cout<<"victory"<<endl<<"victory"<<endl<<"defeat"<<endl<<"defeat"<<endl;
        }
        else if(dp[0] == 1)
        {
            //cout<<"case 2"<<endl;
            cout<<"victory"<<endl;
            string ttt;
            if(n % 2 == 1)
                ttt = "victory";
            else
                ttt = "defeat";
            cout<<ttt<<endl;
            cout<<"defeat"<<endl;
            if(ttt == "victory")
                cout<<"defeat"<<endl;
            else
                cout<<"victory"<<endl;
        }
        else if(dp[0] == 2)
        {
            //cout<<"case 3"<<endl;
            string ttt = "";

            if(n % 2 == 0)
                ttt = "victory";
            else
                ttt = "defeat";


            cout<<ttt<<endl;
            cout<<"defeat"<<endl;

            if(ttt == "victory")
                cout<<"defeat"<<endl;
            else
                cout<<"victory"<<endl;
            cout<<"victory"<<endl;
        }
        else if(dp[0] == 4)
        {
            //cout<<"case 4"<<endl;
            cout<<"defeat"<<endl;
            cout<<"defeat"<<endl;
            cout<<"victory"<<endl;
            cout<<"victory"<<endl;
            //cout<<"_____________"<<endl;
        }

    }


    return 0;
}
