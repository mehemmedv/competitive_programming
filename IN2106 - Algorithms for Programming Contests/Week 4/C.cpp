#include <bits/stdc++.h>

#define MX 100100
typedef long long ll;

using namespace std;

vector < pair< int , int > > p[MX];
int n,m, to[MX],w,k, t, typ[MX], x, y, cnt1, cnt2;

ll dist[MX];
vector<int> ans;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    for(int c = 1; c <= t; ++c){
        ans.clear();
        int genans = 2000000010;
        cin>>n>>cnt1>>cnt2;
        memset(typ, 0, sizeof(typ));
        memset(to, 0, sizeof(typ));
        for(int j = 0; j < cnt1; ++j){
            cin>>x>>y;
            typ[x] = 1;
            to[x] = y;
        }

        for(int j = 0; j < cnt2; ++j){
            cin>>x>>y;
            typ[x] = 2;
            to[x] = y;
        }

        for(int o = 1; o <= 6; ++o){
            for(int i = 1; i <= n; ++i)
                dist[i] = 2000000100;
            dist[1]=0;

            set < pair < ll , int > > s;
            s.insert(make_pair(dist[1],1));

            while(!s.empty()){
                pair < ll , int > tmp; tmp=(*s.begin());s.erase(s.begin());
                if(typ[tmp.second] == 1){
                    int cost1=to[tmp.second];
                    ll cost2=0;
                    if(tmp.first+cost2<dist[cost1]){
                        dist[cost1]=tmp.first+cost2;
                        s.insert(make_pair(dist[cost1],cost1));
                    }
                } else{
                    if(typ[tmp.second] == 2){
                        int cost1=to[tmp.second];
                        ll cost2=0;
                        if(tmp.first+cost2<dist[cost1]){
                            dist[cost1]=tmp.first+cost2;
                            s.insert(make_pair(dist[cost1],cost1));
                        }
                    }
                    int cost1=tmp.second + o;
                    if(cost1 > n)
                        cost1 = n;
                    ll cost2=1;
                    if(tmp.first+cost2<dist[cost1]){
                        dist[cost1]=tmp.first+cost2;
                        s.insert(make_pair(dist[cost1],cost1));
                    }
                }

            }
            if(dist[n] < genans){
                genans = dist[n];
                ans.clear();
                ans.push_back(o);
            } else if(dist[n] == genans){
                ans.push_back(o);
            }
        }


        cout<<"Case #"<<c<<":";
        if(ans.size() == 0){
            cout<<" impossible"<<endl;
        } else{
            for(int i : ans)
                cout<<" "<<i;
            cout<<endl;
        }
    }

    return 0;
}