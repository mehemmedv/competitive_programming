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
        lazy[idx] += k;
        sum[idx] += ((long long)(r-l+1)) * k;
        sum[idx] = sum[idx] % MOD;
        lazy[idx] = lazy[idx] % MOD;
        return;
    }
    int mid = (l + r) >> 1;
    if(lazy[idx] != 0)
    {
        //cout<<l<<" "<<r<<" girdi "<<lazy[idx]<<endl;
        sum[2*idx] += (((long long)(mid-l+1))*lazy[idx]) % MOD;
        sum[2*idx+1] += ((long long)(r-(mid+1) + 1)*lazy[idx]) % MOD;

        sum[2*idx] = sum[2*idx] % MOD;
        sum[2*idx+1] = sum[2*idx+1] % MOD;
        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];

        lazy[2*idx] = lazy[2*idx] % MOD;
        lazy[2*idx+1] = lazy[2*idx+1] % MOD;

        lazy[idx] = 0;
    }

    if(lll <= mid)
        update(l, mid, 2 * idx, lll, rrr, k);
    if(rrr > mid)
        update(mid + 1, r, 2 * idx + 1, lll, rrr, k);

    sum[idx] = (sum[idx * 2] + sum[idx * 2 + 1]) % MOD;
    return;
}

long long calc(int l, int r, int idx, int lll)
{
    //cout<<l<<" "<<r<<" axtarir "<<lll<<endl;
    if(l == r)
        return sum[idx];

    int mid = (l + r) >> 1;
    if(lazy[idx] != 0)
    {
        //cout<<l<<" "<<r<<" girdi "<<lazy[idx]<<endl;
        sum[2*idx] += (((long long)(mid-l+1))*lazy[idx]) % MOD;
        sum[2*idx+1] += ((long long)(r-(mid+1) + 1)*lazy[idx]) % MOD;

        sum[2*idx] = sum[2*idx] % MOD;
        sum[2*idx+1] = sum[2*idx+1] % MOD;
        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];

        lazy[2*idx] = lazy[2*idx] % MOD;
        lazy[2*idx+1] = lazy[2*idx+1] % MOD;

        lazy[idx] = 0;
    }

    if(lll <= mid)
        return calc(l, mid, 2*idx, lll);
    return calc(mid + 1, r, 2*idx + 1, lll);

}


int main()
{

    char ch;
    int t, n, q, l, r, k;
    cin>>t;

    for(int c = 1; c <= t; ++c)
    {
        cin>>n>>q;

        memset(lazy, 0, sizeof(lazy));
        memset(sum, 0, sizeof(sum));


        long long ans = 0;
        for(int i = 1; i <= q; ++i)
        {
            cin>>ch;
            if(ch == 'i')
            {
                cin>>l>>r>>k;
                update(1, n, 1, l, r, k);
            }
            else
            {
                cin>>k;
                long long v = calc(1, n, 1, k);
                //cout<<v<<endl;
                ans = (ans + v) % MOD;
            }

        }


        cout<<"Case #"<<c<<": "<<ans<<endl;

    }


    return 0;
}
