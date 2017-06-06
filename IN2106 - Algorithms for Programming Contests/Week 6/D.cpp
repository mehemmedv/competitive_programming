#include <bits/stdc++.h>

using namespace std;

int w[10][10], t, n;

int perm[10];

vector<int> res;

int main()
{
    cin>>t;

    for(int c = 1; c <= t; ++c){
        res.clear();
        int ans = 1000000000;
        cin>>n;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin>>w[i][j];

        for(int i = 1; i <= n; ++i)
            perm[i-1] = i;
        do{
            int cur = 0;
            perm[n] = perm[0];
            for(int i = 0; i < n; ++i)
                cur += w[perm[i]][perm[i+1]];
            if(cur < ans){
                ans = cur;
                res.clear();
                for(int i = 0; i < n; ++i)
                    res.push_back(perm[i]);
            }
        } while(std::next_permutation(perm,perm+n));

        cout<<"Case #"<<c<<":";
        for(int i : res)
            cout<<" "<<i;
        cout<<endl;
    }

    return 0;
}