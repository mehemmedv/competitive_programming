#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp(vector<int> a, vector<int> b){
    for(int i = 0; i < 5; i ++){
        if(a[i] > b[i])
            return true;
        if(a[i] < b[i])
            return false;
    }
    return false;
}

int main() {

    int t, n;
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        vector<int> v[n];
        for(int i = 0; i < n; i ++){
            v[i].resize(5);
            for(int j = 0; j < 5; j ++){
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }

        sort(v, v + n, cmp);

        cout <<"Case #"<<c+1<<":"<<endl;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < 5; j ++){
                cout << v[i][j];
                if(j < 4)
                    cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}