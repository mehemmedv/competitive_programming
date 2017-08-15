#include <bits/stdc++.h>
#define MAX 1001000
#define MOD 1000000007
using namespace std;

long long sum[4*MAX], lazy[4*MAX];

void update(int l, int r, int idx, int lll, int rrr, long long k)
{
    //cout<<l<<" "<<r<<" add "<<k<<endl;
    if(lll <= l && rrr >= r)
    {
        lazy[idx] = k;
        sum[idx] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if(lazy[idx] != 0)
    {
        //cout<<l<<" "<<r<<" girdi "<<lazy[idx]<<endl;
        sum[2*idx] = lazy[idx];
        sum[2*idx+1] = lazy[idx];

        lazy[idx*2] = lazy[idx];
        lazy[idx*2+1] = lazy[idx];

        lazy[idx] = 0;
    }

    if(lll <= mid)
        update(l, mid, 2 * idx, lll, rrr, k);
    if(rrr > mid)
        update(mid + 1, r, 2 * idx + 1, lll, rrr, k);

    sum[idx] = max(sum[idx * 2], sum[idx * 2 + 1]);
    return;
}

long long calc(int l, int r, int idx, int lll, int rrr)
{
    //cout<<l<<" "<<r<<" axtarir "<<lll<<endl;
    if(lll <= l && rrr >= r)
        return sum[idx];

    int mid = (l + r) >> 1;

    if(lazy[idx] != 0)
    {
        //cout<<l<<" "<<r<<" girdi "<<lazy[idx]<<endl;
        sum[2*idx] = lazy[idx];
        sum[2*idx+1] = lazy[idx];

        lazy[idx*2] = lazy[idx];
        lazy[idx*2+1] = lazy[idx];

        lazy[idx] = 0;
    }
    int sol = -1, sag = -1;

    if(lll <= mid)
        sol = calc(l, mid, 2 * idx, lll, rrr);
    if(rrr > mid)
        sag = calc(mid + 1, r, 2 * idx + 1, lll, rrr);

    return max(sol, sag);

}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    char ch;
    int t, n, q, l, r, k, w, h, p;
    cin>>t;

    for(int c = 1; c <= t; ++c)
    {
        cin>>n>>q;

        memset(lazy, 0, sizeof(lazy));
        memset(sum, 0, sizeof(sum));

        cout<<"Case #"<<c<<":";
        long long ans = 0;
        for(int i = 1; i <= q; ++i)
        {
            cin>>w>>h>>p;
            l = p + 1;
            r = l + w - 1;
            int maxi = calc(1, n, 1, l, r);
            update(1, n, 1, l, r, maxi + h);
            cout<<" "<<calc(1, n, 1, 1, n);
        }
        cout<<endl;



    }


    return 0;
}
