#include <bits/stdc++.h>

using namespace std;

long long x[100100], y[100100];
int n;

int main()
{
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>x[i]>>y[i];
    x[n] = x[0];
    y[n] = y[0];
    long long A = 0;
    for(int i = 0; i < n; ++i)
         A = A + x[i] * y[i+1] - y[i] * x[i+1];
    A = llabs(A);
    long long cnt = 0;
    for(int i = 0; i < n; ++i){
        int d1 = abs(x[i]-x[i+1]);
        int d2 = abs(y[i]-y[i+1]);
        int gcdd = __gcd(d1, d2);
        if(d1 == 0)
            cnt += d2;
        else if(d2 == 0)
            cnt += d1;
        else
            cnt += gcdd;
    }
    A -= cnt;
    A += 2;
    A /= 2;
    cout<<A<<endl;

    return 0;
}
