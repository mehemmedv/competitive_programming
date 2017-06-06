#include <bits/stdc++.h>
#define MAXN 100000600
using namespace std;

array<bool,MAXN> prime;

void eratosfen(){
    prime[0] = prime[1] = false;
    prime.fill(true);
    for (int i=2; i<=MAXN; ++i)
        if (prime[i])
            if (i * 1ll * i <= MAXN)
                for (int j=i*i; j<=MAXN; j+=i)
                    prime[j] = false;
}

int gcd(int x, int y){
    return (y == 0) ? x : gcd(y, x%y);
}

int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n, x, y;

    cin>>t;

    for(int i = 1; i <= t; ++i){
        cin>>n;
        int x = 0;
        for(int i = 0; i < n; ++i){
            cin>>y;
            x = gcd(x, y);
        }
        cout<<"Case #"<<i<<": "<<x<<endl;

    }
    return 0;
}