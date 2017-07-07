#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

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

int sss[10010];
int qqq[10010];

int x[100100], y[100100];
int n, m;

bool check(int mid){
    int N = n + m + 1;
    PushRelabel <int> pr(N + 1);

    for(int i = 1; i <= m; ++i)
        pr.AddEdge(0, i, 1), pr.AddEdge(i, 0, 1);

    for(int i = 1; i <= m; ++i){
        pr.AddEdge(i, x[i] + m, 1);
        pr.AddEdge(i, y[i] + m, 1);
        pr.AddEdge(x[i] + m, i, 1);
        pr.AddEdge(y[i] + m, i, 1);
    }

    for(int i = 1; i <= n; ++i)
        pr.AddEdge(i + m, N, mid), pr.AddEdge(N, i + m, mid);
    if(pr.GetMaxFlow(0, N) == m)
        return true;
    return false;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>n>>m;
    for(int i = 1; i <= m; ++i)
        cin>>x[i]>>y[i];

    int l = 0, r = m;

    int ans = 0;

    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid) == true)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout<<ans<<endl;

    return 0;
}
