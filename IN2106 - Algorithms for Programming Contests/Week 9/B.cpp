#include <bits/stdc++.h>

#define MAX 1000
#define INF 0x4F4F4F4F
using namespace std;

long long Cap[MAX][MAX], CurFlow[MAX][MAX], used[MAX], d[MAX], q[MAX], ptr[MAX];
long long a, b, c, MaxFlow, n, Edges;


int bfs(int s)
{
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset (d, -1, sizeof(d));
    d[s] = 0;
    while (qh < qt)
    {
        int v = q[qh++];
        for (long long &to = ptr[v]; to <= n; to++)
            if ((d[to] == -1) && (CurFlow[v][to] < Cap[v][to]))
            {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
    }
    return d[n] != -1;
}

int dfs(int v, long long flow)
{
    if (!flow)  return 0;
    if (v == n)  return flow;
    for (int to = 1; to <= n; to++)
    {
        if (d[to] != d[v] + 1)  continue;
        long long pushed = dfs (to, min (flow, Cap[v][to] - CurFlow[v][to]));
        if (pushed)
        {
            CurFlow[v][to] += pushed;
            CurFlow[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

long long Dinic(int s)
{
    long long flow = 0;
    for (;;)
    {
        if (!bfs(s))  break;
        memset(ptr,0,sizeof(ptr));
        while (long long pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, l, m;
    cin>>t;
    for(int _t = 1; _t <= t; ++_t)
    {
        cin>>l>>n>>m;
        memset(used, 0, sizeof(used));
        memset(d, 0, sizeof(d));
        memset(q, 0, sizeof(q));
        memset(ptr, 0, sizeof(ptr));
        memset(Cap,0,sizeof(Cap));
        memset(CurFlow,0,sizeof(CurFlow));

        while (m--){
            cin>>a>>b>>c;
            Cap[a][b] += c, Cap[b][a] += c;
        }
        MaxFlow = Dinic(1);
        cout<<"Case #"<<_t<<": ";
        //cout<<MaxFlow<<endl;
        if(MaxFlow <= l)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
