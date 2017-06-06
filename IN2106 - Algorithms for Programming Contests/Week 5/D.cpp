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
    string str;

    for(int i = 1; i <= t; ++i){
        int cur = 1;
        cin>>str;
        int num = 3;
        int len = str.size();
        for(int i = len - 1; i > -1; --i){
            num += ((str[i] - '0') * cur);
            num = num % 13;
            cur *= 8;
            cur = cur % 13;
        }
        if(num == 0)
            num = 13;
        cout<<"Case #"<<i<<": "<<num<<endl;

    }
    return 0;
}