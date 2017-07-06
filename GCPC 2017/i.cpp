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

int n, m, lis[300005], dp[300005], cul[300005];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  FOR (i, 1, n) cin >> lis[i];
  FOR (i, m + 1, n) {
    dp[i] = lis[i] + cul[i - m];
    cul[i] = max(cul[i - 1], dp[i]);
  }
  cout << cul[n];
}
