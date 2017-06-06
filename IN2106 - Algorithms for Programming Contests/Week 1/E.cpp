#include <bits/stdc++.h>
#define MAX 10010
using namespace std;
typedef long long ll;

deque <pair<int, int> > deq;

short used[MAX][MAX];

int main() {

    int t, n, m, curx, cury, x,y,w,h;
    cin >> t;

    for(int c = 1; c <= t; c ++){
        memset(used, 0, sizeof(used));
        cin>>n>>m;
        cin>>curx>>cury;
        deq.clear();
        deq.push_front(make_pair(curx, cury));
        used[curx][cury] = 2;
        int movex = 1, movey = 0;
        int steps = 0, points = 0;

        for(int i = 0; i < m; ++i){
            cin>>x>>y>>w>>h;
            for(int j = x; j < x + w; ++j)
                for(int k = y; k < y + h; ++k)
                    used[j][k] = 1;
        }
        int l;
        cin>>l;
        char ch;
        string str;
        cin>>str;

        for(int i = 0; i < l; ++i){
            steps++;
            ch = str[i];
            if(ch == 'R'){
                if(movex == 0){
                    if(movey == 1)
                        movey = 0, movex = -1;
                    else
                        movey = 0, movex = 1;
                } else if(movey == 0){
                    if(movex == 1)
                        movex = 0, movey = 1;
                    else
                        movex = 0, movey = -1;

                }
            } else if(ch == 'L'){
                if(movex == 0){
                    if(movey == 1)
                        movey = 0, movex = 1;
                    else
                        movey = 0, movex = -1;
                } else if(movey == 0){
                    if(movex == 1)
                        movex = 0, movey = -1;
                    else
                        movex = 0, movey = 1;
                }
            }
            curx += movex;
            cury += movey;
            if(curx == 0)
                curx = n;
            else if(curx == n + 1)
                curx = 1;

            if(cury == 0)
                cury = n;
            else if(cury == n + 1)
                cury = 1;

            deq.push_front(make_pair(curx, cury));
            pair<int, int> last = deq.back();
            used[last.first][last.second] = 0;
            if(used[curx][cury] == 2){
                --steps;
                break;
            }

            if(used[curx][cury] == 1){
                ++points;
                used[last.first][last.second] = 2;
                used[curx][cury] = 2;
            } else{
                used[last.first][last.second] = 0;
                used[curx][cury] = 2;
                deq.pop_back();
            }
        }
        cout<<"Case #"<<c<<": "<<steps<<" "<<points<<endl;

    }

    return 0;
}