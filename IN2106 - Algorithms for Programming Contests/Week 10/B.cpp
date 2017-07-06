#include <bits/stdc++.h>

using namespace std;

int p[10100], n, d, l;
int dp[1000100];

int main()
{
    int t;
    cin>>t;

    for(int c = 1; c <= t; ++c)
    {
        for(int i = 0; i <= 100100; ++i)
            dp[i] = 1000000000;
        cin>>l>>n>>d;

        for(int i = 1; i <= n; ++i)
            cin>>p[i];
        int last = 0;
        sort(p + 1, p + n + 1);

        for(int i = 1; i <= n; ++i)
        {
            if(p[i] - d <= 0)
            {
                for(int j = 0; j <= p[i] + d; ++j)
                    dp[j] = 1;
                last = p[i] + d;
            }
            else
            {
                if(last >= p[i] - d){
                    for(int j = last + 1; j <= p[i] + d; ++j)
                        dp[j] = dp[p[i]-d] + 1;
                    last = p[i] + d;
                }
            }
        }

        cout<<"Case #"<<c<<": ";
        if(dp[l] == 1000000000)
            cout<<"impossible"<<endl;
        else
            cout<<dp[l]<<endl;
    }

    return 0;
}
