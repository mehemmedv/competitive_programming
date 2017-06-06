#include <bits/stdc++.h>
#define MAX 10030

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

int t, n, m;
int par[MAX], rk[MAX];
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    for(int c=0; c<t; c ++){
        cin>>n>>m;

        for(int i=1; i<=n; i ++){
            par[i]=i;
            rk[i]=0;
        }
        E.clear();
        while(m --){
            int a, b, l;
            cin>>a>>b>>l;
            E.push_back(edge(a, b, l));
        }

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

        cout<<"Case #"<<c+1<<": ";
        if(added == n)
            cout<<mst<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}