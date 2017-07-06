#include <bits/stdc++.h>

#define MX 100100
typedef long long ll;

using namespace std;

int m, fr,to ,w , t, h;
ll dist[205*205][4];
vector<int> nodes[205*205][5];
int basx, basy, sonx, sony;
bool used[205][205];

pair<int, int> con_to_2d(int x){
    int l = x / w;
    int r = x - l * w;
    if(r > 0)
        ++l;
    else
        r = 2;
    return make_pair(l, r);
}

int con_to_num(int l, int r){
    return (l-1)*w + r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    char ch;
    for(int c = 1; c <= t; ++c){
        memset(used, 0, sizeof(used));

        cin>>w>>h;
        for(int i = 1; i <= h; ++i)
            for(int j = 1; j <= w; ++j){
                cin>>ch;
                if(ch == '@'){
                    continue;
                } else if(ch == '*'){
                    basx = i;
                    basy = j;
                    used[i][j] = true;
                    continue;
                } else{
                    used[i][j] = true;
                    if(i == 1 || j == 1 || i == h || j == w){
                        sonx = i, sony = j;
                        continue;
                    }
                }
            }

        memset(dist,63,sizeof(dist));
        for(int i = 1; i <= 204*204; ++i)
            for(int j = 0; j < 5; ++j)
                nodes[i][j].clear();
        int bas = con_to_num(basx, basy);
        dist[bas][0]=0;

        set < pair < ll , int > > s;
        set < pair < ll , int > > s1;
        set < pair < ll , int > > s2;
        set < pair < ll , int > > s3;

        s.insert(make_pair(dist[bas][0],bas));

        while(!s.empty()){
            pair < ll , int > tmp; tmp=(*s.begin());s.erase(s.begin());
            pair<int, int> temp = con_to_2d(tmp.second);
            int curx = temp.first, cury = temp.second;
            if(used[curx-1][cury] == true){
                int cost1 = con_to_num(curx-1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][0]){
                    dist[cost1][0]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1][0],cost1));
                }
            }
            if(used[curx+1][cury] == true){
                int cost1 = con_to_num(curx+1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][0]){
                    dist[cost1][0]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1][0],cost1));
                }
            }
            if(used[curx][cury-1] == true){
                int cost1 = con_to_num(curx, cury-1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][0]){
                    dist[cost1][0]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1][0],cost1));
                }
            }
            if(used[curx][cury+1] == true){
                int cost1 = con_to_num(curx, cury+1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][0]){
                    dist[cost1][0]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1][0],cost1));
                }
            }

            if(used[curx-1][cury] == false && used[curx-2][cury] == true){
                int cost1 = con_to_num(curx-2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][0];
                    nodes[cost1][1].push_back(con_to_num(curx-1, cury));
                }
            }

            if(used[curx+1][cury] == false && used[curx+2][cury] == true){
                int cost1 = con_to_num(curx+2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][0];
                    nodes[cost1][1].push_back(con_to_num(curx+1, cury));
                }
            }
            if(used[curx][cury-1] == false && used[curx][cury-2] == true){
                int cost1 = con_to_num(curx, cury-2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][0];
                    nodes[cost1][1].push_back(con_to_num(curx, cury-1));
                }
            }
            if(used[curx][cury+1] == false && used[curx][cury+2] == true){
                int cost1 = con_to_num(curx, cury+2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][0];
                    nodes[cost1][1].push_back(con_to_num(curx, cury+1));
                }
            }
        }

        while(!s1.empty()){
            pair < ll , int > tmp; tmp=(*s1.begin());s1.erase(s1.begin());
            pair<int, int> temp = con_to_2d(tmp.second);
            int curx = temp.first, cury = temp.second;
            if(used[curx-1][cury] == true){
                int cost1 = con_to_num(curx-1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][1];
                }
            }
            if(used[curx+1][cury] == true){
                int cost1 = con_to_num(curx+1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][1];
                }
            }
            if(used[curx][cury-1] == true){
                int cost1 = con_to_num(curx, cury-1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][1];
                }
            }
            if(used[curx][cury+1] == true){
                int cost1 = con_to_num(curx, cury+1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][1]){
                    dist[cost1][1]=tmp.first+cost2;
                    s1.insert(make_pair(dist[cost1][1],cost1));
                    nodes[cost1][1] = nodes[tmp.second][1];
                }
            }

            if(used[curx-1][cury] == false && used[curx-2][cury] == true){
                int cost1 = con_to_num(curx-2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][1];
                    nodes[cost1][2].push_back(con_to_num(curx-1, cury));
                }
            }

            if(used[curx+1][cury] == false && used[curx+2][cury] == true){
                int cost1 = con_to_num(curx+2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][1];
                    nodes[cost1][2].push_back(con_to_num(curx+1, cury));
                }
            }
            if(used[curx][cury-1] == false && used[curx][cury-2] == true){
                int cost1 = con_to_num(curx, cury-2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][1];
                    nodes[cost1][2].push_back(con_to_num(curx, cury-1));
                }
            }
            if(used[curx][cury+1] == false && used[curx][cury+2] == true){
                int cost1 = con_to_num(curx, cury+2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][1];
                    nodes[cost1][2].push_back(con_to_num(curx, cury+1));
                }
            }
        }

        while(!s2.empty()){
            pair < ll , int > tmp; tmp=(*s2.begin());s2.erase(s2.begin());
            pair<int, int> temp = con_to_2d(tmp.second);
            int curx = temp.first, cury = temp.second;
            if(used[curx-1][cury] == true){
                int cost1 = con_to_num(curx-1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][2];
                }
            }
            if(used[curx+1][cury] == true){
                int cost1 = con_to_num(curx+1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][2];
                }
            }
            if(used[curx][cury-1] == true){
                int cost1 = con_to_num(curx, cury-1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][2];
                }
            }
            if(used[curx][cury+1] == true){
                int cost1 = con_to_num(curx, cury+1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][2]){
                    dist[cost1][2]=tmp.first+cost2;
                    s2.insert(make_pair(dist[cost1][2],cost1));
                    nodes[cost1][2] = nodes[tmp.second][2];
                }
            }

            if(used[curx-1][cury] == false && used[curx-2][cury] == true){
                int cost1 = con_to_num(curx-2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][2];
                    nodes[cost1][3].push_back(con_to_num(curx-1, cury));
                }
            }

            if(used[curx+1][cury] == false && used[curx+2][cury] == true){
                int cost1 = con_to_num(curx+2, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][2];
                    nodes[cost1][3].push_back(con_to_num(curx+1, cury));
                }
            }
            if(used[curx][cury-1] == false && used[curx][cury-2] == true){
                int cost1 = con_to_num(curx, cury-2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][2];
                    nodes[cost1][3].push_back(con_to_num(curx, cury-1));
                }
            }
            if(used[curx][cury+1] == false && used[curx][cury+2] == true){
                int cost1 = con_to_num(curx, cury+2);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][2];
                    nodes[cost1][3].push_back(con_to_num(curx, cury+1));
                }
            }
        }

        while(!s3.empty()){
            pair < ll , int > tmp; tmp=(*s3.begin());s3.erase(s3.begin());
            pair<int, int> temp = con_to_2d(tmp.second);
            int curx = temp.first, cury = temp.second;
            if(used[curx-1][cury] == true){
                int cost1 = con_to_num(curx-1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][3];
                }
            }
            if(used[curx+1][cury] == true){
                int cost1 = con_to_num(curx+1, cury);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][3];
                }
            }
            if(used[curx][cury-1] == true){
                int cost1 = con_to_num(curx, cury-1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][3];
                }
            }
            if(used[curx][cury+1] == true){
                int cost1 = con_to_num(curx, cury+1);
                int cost2 = 1;
                if(tmp.first+cost2<dist[cost1][3]){
                    dist[cost1][3]=tmp.first+cost2;
                    s3.insert(make_pair(dist[cost1][3],cost1));
                    nodes[cost1][3] = nodes[tmp.second][3];
                }
            }
        }

        int sonnum = con_to_num(sonx, sony);
        int ans = 2000000000;
        int idx = -1;
        for(int i = 0; i < 4; ++i)
            if(ans > dist[sonnum][i])
                idx = i, ans = dist[sonnum][i];

        cout<<"Case #"<<c<<":"<<endl;
        for(int i : nodes[sonnum][idx]){
            pair<int, int> temp = con_to_2d(i);
            cout<<temp.second<<" "<<temp.first<<endl;
        }
        for(int i = idx + 1; i < 4; ++i)
            cout<<"unused"<<endl;
    }

    return 0;
}
