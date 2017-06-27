#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

//https://github.com/jaehyunp/stanfordacm

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, int cap) {
        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
        if (from == to) {
            adj[from].back().index++;
        }
        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T> &e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
            Enqueue(e.to);
        }
    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
            count[dist[v]]--;
            dist[v] = max(dist[v], n);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto e: adj[v]) if (e.cap - e.flow > 0) {
            dist[v] = min(dist[v], dist[e.to] + 1);
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]);
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;

        for (auto &e: adj[s]) {
            excess[s] += e.cap;
        }

        count[0] = n;
        Enqueue(s);
        active[t] = true;

        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }
        return excess[t];
    }

    T GetMinCut (int s, int t, vector <int> &cut);
};


#define MAX 10100
long long x[MAX], y[MAX], z[MAX];
int l[1000010], r[1000100];
long long mxfl[MAX];

long long inf = 10000000;

long long dis(int lll, int rrr){
    return (x[lll]-x[rrr])*(x[lll]-x[rrr]) + (y[lll]-y[rrr])*(y[lll]-y[rrr]) + (z[lll]-z[rrr])*(z[lll]-z[rrr]);
}

long double dis_dob(int lll, int rrr){
    return sqrt((long double)((x[lll]-x[rrr])*(x[lll]-x[rrr]) + (y[lll]-y[rrr])*(y[lll]-y[rrr]) + (z[lll]-z[rrr])*(z[lll]-z[rrr])));
}

vector < pair< int , long double > > p[MAX];
int fr,to;
int par[MAX];
long double w;
long double dist[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N1, M1, n1, m1, t, n, a, b;
    long long c, MaxFlow;

    cin>>t;
    for(int _t = 1; _t <= t; ++_t)
    {
        cin>>N1>>M1>>n1>>m1;
        for(int i = 1; i <= N1; ++i)
            cin>>x[i]>>y[i]>>z[i];

        for(int i = 1; i <= M1; ++i)
            cin>>l[i]>>r[i];

        for(int i = 0; i < MAX; ++i)
            par[i] = 0, p[i].clear();

        //memset(dist,63,sizeof(dist));
        for(int i = 0; i < MAX; ++i)
            dist[i] = 1000000005.0;
        //cout<<dist[0]<<endl;

        dist[1]=0.0;
        for(int i=1;i<=M1;i++)
            {
                long double w = dis_dob(l[i], r[i]);
                fr = l[i];
                to = r[i];
                p[fr].push_back(make_pair(to,w));
            }
        set < pair < long double , int > > s;

        s.insert(make_pair(dist[1],1));

        while(!s.empty()){

            pair < long double , int > tmp; tmp=(*s.begin());s.erase(s.begin());
            for(int i=0;i<p[tmp.second].size();i++)
                {
                    int cost1=p[tmp.second][i].first;
                    long double cost2=p[tmp.second][i].second;
                    if(tmp.first+cost2<dist[cost1]){
                        dist[cost1]=tmp.first+cost2;
                        s.insert(make_pair(dist[cost1],cost1));
                        par[cost1]=tmp.second;
                    }
                }
            }
        n = N1;

        for(int i = 1; i <= N1; ++i){
            n = n1;
            PushRelabel<LL> pr(n);
            for(int j = 1; j <= m1; ++j){
                cin>>a>>b>>c;
                a = a - (i-1)*n1;
                b = b - (i-1)*n1;
                pr.AddEdge(a-1, b-1, c);
                pr.AddEdge(b-1, a-1, c);
            }
            mxfl[i] = pr.GetMaxFlow(0, n-1);
            //cout<<mxfl[i]<<endl;
        }
        if(n1 == 1){
            for(int i = 1; i <= N1; ++i)
                mxfl[i] = 1000000000;
        }

        int cur_dis = dist[N1];
        bool valid = true;
        int ans = INT_MAX;
        if(cur_dis >= 1000000000){
            valid = false;
        } else{
            int cur = N1;
            while(cur != 0){
                int ata = par[cur];
                ans = min((LL)ans, mxfl[cur]);
                if(ata != 0)
                    ans = min((LL)ans, dis(cur, ata));
                cur = ata;
            }
            if(ans == 0)
                valid = false;
        }
        cout<<"Case #"<<_t<<": ";
        if(valid == false){
            cout<<"impossible"<<endl;
        } else
            cout<<ans<<endl;
    }

    return 0;
}
