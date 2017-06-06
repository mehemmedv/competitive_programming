#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main()
{
    cin>>t;
    long long c = 299792458;
    for(int i = 1; i<= t; ++i){
        long long m;
        cin>>m;

        cout<<"Case #"<<i<<": ";
        cout<<m*c*c<<endl;
    }
    return 0;
}