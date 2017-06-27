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

int str_to_int(int l, int r, string s)
{
    int num = 0;
    for(int i = l; i <= r; ++i)
        num = num * 10 + s[i] - '0';
    return num;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, l, m, n1;
    cin>>t;
    for(int _t = 1; _t <= t; ++_t)
    {
        string s;
        cin>>n1>>m;
        getline(cin, s);

        memset(used, 0, sizeof(used));
        memset(d, 0, sizeof(d));
        memset(q, 0, sizeof(q));
        memset(ptr, 0, sizeof(ptr));
        memset(Cap,0,sizeof(Cap));
        memset(CurFlow,0,sizeof(CurFlow));

        for(int i = 1; i <= n1; ++i)
            Cap[0][i] = Cap[i][0] = 1;
        for(int i = n1 + 1; i <= n1 + m; ++i)
            Cap[i][n1 + m + 1] = Cap[n1 + m + 1][i] = 1;

        n = n1 + m + 1;

        for(int i = 1; i <= n1; ++i)
        {
            getline(cin, s);
            int len = s.size();
            int j = 0;
            while(j < len)
            {
                int beg = j;
                for(; j < len; ++j)
                {
                    if(s[j] == ',' || s[j] == '-')
                        break;
                }
                if(j == len)
                {
                    int cur = str_to_int(beg, j-1, s);
                    Cap[i][cur+n1] = 1, Cap[cur+n1][i] = 1;
                }
                else if(s[j] == ',')
                {
                    int cur = str_to_int(beg, j-1, s);
                    Cap[i][cur+n1] = 1, Cap[cur+n1][i] = 1;
                    ++j;
                }
                else if(s[j] == '-')
                {
                    int cur = str_to_int(beg, j-1, s);
                    ++j;
                    beg = j;

                    for(; j < len; ++j)
                    {
                        if(s[j] == ',')
                            break;
                    }
                    int cur2 = str_to_int(beg, j-1, s);
                    for(int o = cur; o <= cur2; ++o)
                    {
                        Cap[i][o+n1] = 1, Cap[o+n1][i] = 1;
                    }

                    ++j;

                }
                else
                {
                    cout<<"xaaxxa"<<endl;
                }
            }

        }

        MaxFlow = Dinic(0);
        cout<<"Case #"<<_t<<": ";
        if(MaxFlow == n1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
