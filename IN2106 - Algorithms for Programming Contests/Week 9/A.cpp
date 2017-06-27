#include <bits/stdc++.h>

#define MAX 1000
#define INF 0x3F3F3F3F
using namespace std;

int Cap[MAX][MAX], CurFlow[MAX][MAX], used[MAX], d[MAX], q[MAX], ptr[MAX];
int a, b, c, MaxFlow, n, Edges;


int bfs(int s)
{
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset (d, -1, sizeof(d));
    d[s] = 0;
    while (qh < qt)
    {
        int v = q[qh++];
        for (int &to = ptr[v]; to <= n; to++)
            if ((d[to] == -1) && (CurFlow[v][to] < Cap[v][to]))
            {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
    }
    return d[n] != -1;
}

int dfs(int v, int flow)
{
    if (!flow)  return 0;
    if (v == n)  return flow;
    for (int to = 1; to <= n; to++)
    {
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, Cap[v][to] - CurFlow[v][to]));
        if (pushed)
        {
            CurFlow[v][to] += pushed;
            CurFlow[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int Dinic(int s)
{
    int flow = 0;
    for (;;)
    {
        if (!bfs(s))  break;
        memset(ptr,0,sizeof(ptr));
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main(void)
{
    int t, n1, k1, m1, l1;
    cin>>t;
    for(int _t = 1; _t <= t; ++_t)
    {
        cin>>n1>>k1>>m1>>l1;
        memset(used, 0, sizeof(used));
        memset(d, 0, sizeof(d));
        memset(q, 0, sizeof(q));
        memset(ptr, 0, sizeof(ptr));


        memset(Cap,0,sizeof(Cap));
        memset(CurFlow,0,sizeof(CurFlow));

        for(int i = 1; i <= n1; ++i)
            Cap[0][i] = Cap[i][0] = INF;
        for(int i = n1 + k1 + 1; i <= n1 + k1 + m1; ++i)
            Cap[i][n1 + k1 + m1 + 1] = Cap[n1 + k1 + m1 + 1][i] = INF;
        n = n1 + k1 + m1 + 1;

        while (l1--){
            cin>>a>>b>>c;
            Cap[a][b] += c, Cap[b][a] += c;
        }
        MaxFlow = Dinic(0);
        cout<<"Case #"<<_t<<": ";
        cout<<MaxFlow<<endl;
    }
    return 0;
}
