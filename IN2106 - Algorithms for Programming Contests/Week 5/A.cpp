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

int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    eratosfen();

    cin>>t;

    for(int i = 1; i <= t; ++i){
        cin>>n;
        vector<int> res;
        if(n == 4){
            cout<<"Case #"<<i<<": 2 2"<<endl;
            continue;
        }
        if(n % 2 != 0){
            if(prime[n-4] == true){
                cout<<"Case #"<<i<<":";
                cout<<" 2 2 "<<n-4<<endl;
                continue;
            }
            res.push_back(3);
            n -= 3;
        }
        for(int i = 3; i <= n; i += 2){
            if(prime[i] == true && prime[n-i] == true){
                res.push_back(i);
                res.push_back(n-i);
                break;
            }
        }
        sort(res.begin(), res.end());
        cout<<"Case #"<<i<<":";
        for(int i : res)
            cout<<" "<<i;
        cout<<endl;
    }
    return 0;
}