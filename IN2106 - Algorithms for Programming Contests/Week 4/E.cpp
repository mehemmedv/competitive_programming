#include <bits/stdc++.h>

#define MX 505
using namespace std;

struct edge{
    int from;
    int to;
    int length;

    edge() {}
    edge(int from, int to, int length): from(from), to(to), length(length) {}
    bool operator<(const edge other) const{
        return length<other.length;
    }
};

int par[MX], rk[MX];
vector<edge> E;

int find(int x){
    if(x == par[x])
        return x;
    return par[x] = find(par[x]);
}
void join(int x, int y){
    int rx=find(x);
    int ry=find(y);

    if(rx == ry)
        throw;
    if(rk[rx] > rk[ry])
        swap(rx, ry);
    if(rk[rx] == rk[ry])
        rk[ry] ++;
    par[rx]=ry;
}




bool dun[MX];

int d, n, m, x, fr, to, w;
long long dist[MX][MX];
vector < pair< int , int > > p[MX];


int weights[MX][MX];
vector<int> mst_edges[MX];

bool used[MX];
int cur_ans = 0;

int dfs(int cur, int mes){
    used[cur] = true;
    bool flag = false;
    for(int i : mst_edges[cur]){
        if(used[i] == false){
            int x = dfs(i, mes + weights[cur][i]);
            if(x != 0){
                if(flag == false){
                    flag = true;
                } else{
                    cur_ans -= mes;
                }
            }
        }
    }
    if(dun[cur] == true){
        if(flag == false)
            cur_ans += mes;
        return mes;
    }
    if(flag == true)
        return 1;
    return 0;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int c = 1; c <= t; ++c){

        vector<int> dungeon;
        long long ans = 2000000000;
        memset(dun, 0, sizeof(dun));
        cin>>n>>m>>d;
        for(int i = 1; i <= n; ++i)
            p[i].clear();
        dungeon.push_back(1);
        for(int i = 0; i < d; ++i){
            cin>>x;
            dun[x] = true;
            dungeon.push_back(x);
        }
        for(int i=1;i<=m;i++)
        {
            cin>>fr>>to>>w;
            p[fr].push_back(make_pair(to,w));
            p[to].push_back(make_pair(fr,w));

        }
        for(int i=1; i<=n; i ++){
            par[i]=i;
            rk[i]=0;
        }
        E.clear();


        memset(dist,63,sizeof(dist));

        for(int j : dungeon){

            dist[j][j] = 0;

            set < pair < long long , int > > s;

            s.insert(make_pair(dist[j][j],j));

            while(!s.empty()){

                pair < long long , int > tmp; tmp=(*s.begin());s.erase(s.begin());

                for(long long i=0;i<p[tmp.second].size();i++)
                {
                    int cost1=p[tmp.second][i].first;
                    long long cost2=p[tmp.second][i].second;
                    if(tmp.first+cost2<dist[j][cost1]){
                        dist[j][cost1]=tmp.first+cost2;
                        s.insert(make_pair(dist[j][cost1],cost1));
                    }
                }
            }

        }

        for(int i = 1; i < dungeon.size(); ++i)
            for(int j = i + 1; j < dungeon.size(); ++j)
                E.push_back(edge(dungeon[i], dungeon[j], dist[dungeon[i]][dungeon[j]]));
        sort(E.begin(), E.end());


        int mst=0, added=1;
        for(int j=0; j<E.size(); ++j){
            int x=E[j].from;
            int y=E[j].to;
            if(find(x) == find(y))
                continue;
            mst += E[j].length;
            added ++;
            join(x, y);
        }


        long long cur_ans = 2000000000;
        for(int i = 1; i < dungeon.size(); ++i){
            cur_ans = min(cur_ans, dist[1][dungeon[i]]);

        }


        cout<<"Case #"<<c<<": "<<cur_ans + mst<<endl;;
    }
    return 0;
}