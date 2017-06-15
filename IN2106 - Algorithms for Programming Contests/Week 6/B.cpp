#include<bits/stdc++.h>

using namespace std;

vector <vector<int>> G;
vector <vector<int>> visited;
int next_i[4] = {0, -1, 0, 1};
int next_j[4] = {-1, 0, 1, 0};
int nr_tools;
int si, sj;
int w, h;

int ct;

bool search(int i, int j, int nr_tools_collected) {
    ct++;
    visited[i][j] = 1;
    if (nr_tools_collected == nr_tools) {
        return true;
    }
    if (G[i][j] == 1) {
        nr_tools_collected += 1;
    }
    if (nr_tools_collected == nr_tools) {
        return true;
    }

    for (int k = 0; k < 4; ++k) {
        int neighbor_i = i + next_i[k];
        int neighbor_j = j + next_j[k];
        if (neighbor_i >= 0 && neighbor_i < h && neighbor_j >= 0 && neighbor_j < w &&
            (G[neighbor_i][neighbor_j] == 0 || G[neighbor_i][neighbor_j] == 1) &&
            visited[neighbor_i][neighbor_j] == 0) {
            if (search(neighbor_i, neighbor_j, nr_tools_collected))
                return true;
        }
    }
    visited[i][j] = 0;
    return false;
}


int main() {

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> w >> h;
        nr_tools = 0;
        G.clear();
        visited.clear();
        ct = 0;

        G.resize(h, vector<int>(w, 0));
        visited.resize(h, vector<int>(w, 0));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;
                if (c == '_') {
                    G[i][j] = 0;
                } else if (c == 'T') {
                    G[i][j] = 1;
                    nr_tools++;
                } else if (c == 'L') {
                    si = i;
                    sj = j;
                    G[i][j] = 0;
                } else if (c == '#') {
                    G[i][j] = -1;
                    visited[i][j] = 1;
                }
            }
        }
        cout << "Case #" << t << " ";
        if (search(si, sj, 0))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}