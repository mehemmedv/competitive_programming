#include <bits/stdc++.h>

#define MX 100100
typedef long long ll;

using namespace std;

vector < pair< int , int > > p[MX];
int n,m,fr,to,w,k, t;
ll dist[MX];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    for(int c = 1; c <= t; ++c){

        cin>>n>>m;

        for(int i = 1; i <= n; ++i)
            p[i].clear(), dist[i] = 2000000000;
        dist[1]=0;
        for(int i=1;i<=m;i++)
        {
            cin>>fr>>to>>w;
            p[fr].push_back(make_pair(to,w));
            p[to].push_back(make_pair(fr,w));
        }
        set < pair < ll , int > > s;

        s.insert(make_pair(dist[1],1));

        while(!s.empty()){

            pair < ll , int > tmp; tmp=(*s.begin());s.erase(s.begin());

            for(ll i=0;i<p[tmp.second].size();i++)
            {
                int cost1=p[tmp.second][i].first;
                ll cost2=p[tmp.second][i].second;
                if(tmp.first+cost2<dist[cost1]){
                    dist[cost1]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1],cost1));
                }
            }
        }
        cout<<"Case #"<<c<<": "<<dist[n]<<endl;
    }

    return 0;
}