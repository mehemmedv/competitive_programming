#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, m, c;

long long expo(long long x, long long y) {
  long long ret = 1;
  FORD (i, 55, 0) {
    ret *= ret;
    ret %= mod;
    if ((1ll << i) & y) {
      ret *= x;
      ret %= mod;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> c;
  long long p = expo(c, n * n);
  long long ret = 0;
  FOR (i, 1, m) {
    ret += expo(p, __gcd(i, (int)m));
    ret %= mod;
  }
  ret *= expo(m, mod - 2);
  ret %= mod;
  if (ret < 0) ret += mod;
  cout << ret;
}
