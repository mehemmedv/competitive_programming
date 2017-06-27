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

int pts[MAX], l[MAX], r[MAX];
int cnt[MAX];

int main(void)
{
    int t, n1, m;
    cin>>t;
    for(int _t = 1; _t <= t; ++_t)
    {
        int mxp = -1;
        cin>>n1>>m;
        for(int i = 1; i <= n1; ++i)
        {
            cin>>pts[i];
            mxp = max(mxp, pts[i]);
        }
        memset(cnt, 0, sizeof(cnt));

        for(int i = 1; i <= m; ++i)
        {
            cin>>l[i]>>r[i];
            ++cnt[l[i]];
            ++cnt[r[i]];
        }

        n = n1 + m + 1;

        cout<<"Case #"<<_t<<":";
        //cout<<n<<endl;
        for(int which = 1; which <= n1; ++which)
        {
            if(pts[which] + cnt[which] >= mxp)
            {
                memset(used, 0, sizeof(used));
                memset(d, 0, sizeof(d));
                memset(q, 0, sizeof(q));
                memset(ptr, 0, sizeof(ptr));
                memset(Cap,0,sizeof(Cap));
                memset(CurFlow,0,sizeof(CurFlow));

                int cur = pts[which] + cnt[which];

                for(int i = 1; i <= m; ++i){
                    if(l[i] != which && r[i] != which)
                        Cap[0][i] = Cap[i][0] = 1;
                }

                for(int i = 1; i <= m; ++i){
                    if(l[i] != which && r[i] != which){
                        Cap[i][l[i] + m] = Cap[l[i] + m][i] = 1;
                        Cap[i][r[i] + m] = Cap[r[i] + m][i] = 1;
                    }
                }

                for(int i = m + 1; i <= n1 + m; ++i){
                    if(i - m != which)
                        Cap[i][n] = Cap[n][i] = cur - pts[i-m];
                }

                /*for(int i = 0; i <= n; ++i)
                    for(int j = i + 1; j <= n; ++j)
                        if(Cap[i][j] == 1)
                            cout<<i<<" "<<j<<" 1"<<endl;
*/
                MaxFlow = Dinic(0);

                //cout<<" "<<MaxFlow<<" "<<cnt[which];
                if(MaxFlow == m - cnt[which])
                    cout<<" yes";
                else
                    cout<<" no";
            }
            else
                cout<<" no";
        }
        cout<<endl;
    }

    return 0;
}
