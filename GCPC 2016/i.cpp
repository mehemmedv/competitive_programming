#include <bits/stdc++.h>

using namespace std;

long long ans = 1;
int n;
int main()
{
    std::ios::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; ++i){
        ans = ans * 4LL;
        ans = ans * 2LL;
    }

    cout<<ans<<endl;

    return 0;
}
