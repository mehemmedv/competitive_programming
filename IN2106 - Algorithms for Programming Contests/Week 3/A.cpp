#include <bits/stdc++.h>
#define MAX 1030

using namespace std;

int T, N;
int x[MAX], y[MAX], z[MAX], dist[MAX], used[MAX];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;
    for(int c=0; c<T; c ++){
        cin>>N;
        for(int i=0; i<N; i ++)
            cin>>x[i]>>y[i]>>z[i];

        fill(dist, dist+N, 1<<30);
        fill(used, used+N, 0);

        int mst=0;
        dist[0]=0;

        for(int i=0; i<N; i ++){
            int pos=-1;
            for(int j=0; j<N; j ++)
                if(!used[j] && (pos == -1 || dist[j]<dist[pos]))
                    pos=j;
            used[pos]=1;
            mst += dist[pos];
            for(int j=0; j<N; j ++)
                if(!used[j])
                    dist[j]=min(dist[j], abs(x[j]-x[pos])+abs(y[j]-y[pos])+abs(z[j]-z[pos]));
        }
        cout<<"Case #"<<c+1<<": "<<mst<<endl;
    }
    return 0;
}