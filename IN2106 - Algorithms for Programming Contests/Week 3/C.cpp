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

int t, n;
int x[MAX], y[MAX], cap[MAX], par[MAX], rk[MAX];
vector<edge> E;

int find(int x){
    if(x == par[x])
        return x;
    return par[x]=find(par[x]);
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
        cin>>n;
        for(int i=1; i<=n; i ++)
            cin>>x[i]>>y[i]>>cap[i];

        for(int i=0; i<=n; i ++){
            par[i]=i;
            rk[i]=0;
        }
        x[0]=0;
        y[0]=0;
        cap[0]=1<<30;

        E.clear();
        for(int i=0; i<=n; i ++)
            for(int j=0; j<=n; j ++){
                if(i == j)
                    continue;
                int cost=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(cost<=min(cap[i], cap[j])){
                    E.push_back(edge(i, j, cost));
                }
            }
        sort(E.begin(), E.end());
        int mst=0, added=1;
        //for(edge i : E){
        for(int j=0; j<E.size(); j++){
            int x=E[j].from;
            int y=E[j].to;

            if(find(x) == find(y))
                continue;
            mst += E[j].length;
            added ++;
            join(x, y);
        }
        cout<<"Case #"<<c+1<<": ";
        if(added == n+1)
            cout<<mst*2<<endl;
        else cout<<"impossible"<<endl;
    }

    return 0;
}