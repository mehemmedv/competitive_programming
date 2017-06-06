#include <bits/stdc++.h>

using namespace std;

int n, c, m;
bool g[160][160];
int color[160];
bool flag = false;

bool isPossible(int v, int ccc) {
    for (int i = 0; i < n; i++) {
        if (g[v][i] == 1 && ccc == color[i]) {
            return false;
        }
    }
    return true;
}

void calc(int v) {
    if (v == n) {
        flag = true;
        return;
    }

    for (int i = 1; i <= c; i++) {
        if (isPossible(v, i)) {
            color[v] = i;
            calc(v + 1);
            if (flag == true)
                return;
            color[v] = 0;
        }
    }
}

void display() {
    if (flag == true) {
        for (int i = 0; i < n; ++i)
            cout << " " << color[i];
        cout << endl;
    } else
        cout << " impossible" << endl;
}

int main() {

    int t, x, y;
    cin >> t;
    for (int cc = 1; cc <= t; ++cc) {
        cin >> n >> m >> c;
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x - 1][y - 1] = 1;
            g[y - 1][x - 1] = 1;
        }
        memset(color, 0, sizeof(color));
        cout << "Case #" << cc << ":";
        flag = false;
        calc(0);

        display();
    }
    return 0;
}