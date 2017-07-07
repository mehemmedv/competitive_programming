#include <bits/stdc++.h>

using namespace std;
int len = 20000;
bool dp[10100000];
int n;
long long k;

int a[100];

int main()
{
    dp[0] = true;
    cin>>n>>k;
    for(int i = 0; i < n; ++i)
        cin>>a[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < len; ++j)
            dp[j + a[i]] |= dp[j];
    }

    for(int i = 1; i <= len; ++i){
        if(dp[i] == true){
            long long rem = k / i;
            long long qal = k - rem * (long long)i;
            if(dp[qal] == true){
                cout<<"possible"<<endl;
                return 0;
            }
        }
    }

    cout<<"impossible"<<endl;

    return 0;
}
