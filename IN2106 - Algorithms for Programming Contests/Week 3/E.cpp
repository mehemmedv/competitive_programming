#include <bits/stdc++.h>
#define MAX 250

using namespace std;


int t, n;
int dist[MAX][MAX];

vector<int> GetPath(int start, int finish){
    if(start == finish)
        return vector<int>({start});
    int pos=-1;
    for(int i=1; i<=n; i ++){
        if(i == start || i == finish)
            continue;
        if(dist[start][i]+dist[i][finish] == dist[start][finish]){
            pos=i;
            break;
        }
    }
    if(pos == -1)
        return vector<int>({start, finish});
    vector<int> p1=GetPath(start, pos);
    vector<int> p2=GetPath(pos, finish);
    p1.pop_back();
    p1.insert(p1.end(), p2.begin(), p2.end());
    return p1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    for(int cases=0; cases<t; cases ++){
        cin>>n;
        for(int i=1; i<=n; i ++)
            for(int j=1; j<=n; j ++)
                cin>>dist[i][j];
        cout<<"Case #"<<cases+1<<":";
        vector<int> path=GetPath(1, n);
        for(int j = 0; j < path.size(); j++)
            cout<<" "<<path[j];
        cout<<endl;
    }

    return 0;
}