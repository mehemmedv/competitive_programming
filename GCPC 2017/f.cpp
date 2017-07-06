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

int m, n, k, u, v;
vector<int> adj[3333];
int cnt, res, matchx[3333], matchy[3333], fre[3333];
int ad[3333];
int edge[3333][3333];

bool find(int u) {
  if (fre[u] == cnt) return false;
  fre[u] = cnt;
  for (int v: adj[u]) {
    if (matchy[v] == 0 || find(matchy[v])) {
      matchx[u] = v;
      matchy[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> m >> n >> k;
  REP (i, k) {
    cin >> u >> v;
    adj[v].pb(u + n);
    adj[u + n].pb(v);
    edge[u + n][v] = 1;
  }
  FOR (i, 1, n) {
    cnt++;
    if (find(i)) res++;
  }
  int addon = 0;
  FOR (i, 1, m) {
    v = n + i;
    int tmp = 0;
    for (int j: adj[v]) if (!matchx[j]) tmp++;
    tmp = min(tmp, 2);
    ad[i] = tmp;
    addon = max(addon, tmp);
  }
  FOR (i, 1, m) FOR (j, i + 1, m) {
    if (!ad[i] || !ad[j]) continue;
    u = i + n;
    v = j + n;
    if (edge[u][matchy[v]] || edge[v][matchy[u]]) {
      cout << res + 2;
      return 0;
    }
  }
  cout << res + addon;
}
