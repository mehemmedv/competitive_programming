#include <bits/stdc++.h>

#define MX 100100
typedef long long ll;

using namespace std;

vector < pair< int , int > > p[MX];
int n,m,fr,to,w,k, t, cnt[MX];
ll dist[MX];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    for(int c = 1; c <= t; ++c){
        cin>>n;

        for(int i = 1; i <= n; ++i)
            p[i].clear(), dist[i] = -1;
        dist[1]=0;
        for(int j = 1; j < n; ++j){
            cin>>w>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>to;
                p[j].push_back(make_pair(to,w));
                ++cnt[to];
            }
        }
        cin>>w>>to;
        set < pair < ll , int > > s;
        s.insert(make_pair(dist[1],1));

        while(!s.empty()){
            pair < ll , int > tmp; tmp=(*s.begin());s.erase(s.begin());
            for(ll i=0;i<p[tmp.second].size();i++)
            {
                int cost1=p[tmp.second][i].first;
                ll cost2=p[tmp.second][i].second;
                --cnt[cost1];
                if(tmp.first+cost2>dist[cost1]){
                    dist[cost1]=tmp.first+cost2;
                }
                if(cnt[cost1] == 0)
                    s.insert(make_pair(dist[cost1],cost1));
            }
        }
        cout<<"Case #"<<c<<": "<<dist[n]+w<<endl;
    }

    return 0;
}