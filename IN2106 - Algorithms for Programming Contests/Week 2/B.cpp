#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;

double ans, d,p,u,v, l, r, mid;

bool check_fit(double mid){
    int say1 = u / mid;
    double mes1 = say1 * mid;
    say1++;
    int newd = p;
    newd -= say1;
    newd -= 1;
    double mes2 = mid * newd;
    double curmes = d - mes2;
    if(curmes > u && curmes < v)
        return false;
    if(curmes - mes1 >= mid)
        return true;
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int c = 1; c <= t; c ++){
        ans = 0;
        cin>>d>>p>>u>>v;

        l = 0, r = d;

        for(int i = 0; i < 100; ++i){
            mid = (l + r) / 2.0;
            if(check_fit(mid))
                ans = mid, l = mid;
            else
                r = mid;
        }
        cout.precision(12);
        cout<<fixed<<"Case #"<<c<<": "<<ans<<endl;
    }

    return 0;
}