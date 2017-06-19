#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
#include <cstdio>


#include <map>
#include <set>
#include <list>
#include <cassert>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <utility>

using namespace std;

map<char, string> m;

string production(string s){
    string news = "";
    int len = s.size();
    for(int i = 0; i < len; ++i){
        if(s[i] == '+' || s[i] == '-')
            news += s[i];
        else{
            news += m[s[i]];
        }
    }
    return news;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int t, n, d;
    cin >> t;
    double newdeg;
    string s;
    for(int c = 1; c <= t; ++c)
    {
        m.clear();
        double degree = 0, a, x = 0, y = 0;
        cout<<"Case #"<<c<<":"<<endl;

        cin>>n>>d>>a>>s;
        string temp;
        newdeg = (a*M_PI)/180.0;
        for(int i = 0; i < n; ++i){
            cin>>temp;
            m[temp[0]] = temp.substr(3);
        }
        for(int i = 0; i < d; ++i)
            s = production(s);
        int len = s.size();
        //cout<<"0.0 0.0"<<endl;
        for(int i = 0; i < len; ++i){
            if(s[i] == '+')
                degree += newdeg;
            else if(s[i] == '-')
                degree -= newdeg;
            else{
                printf("%.16lf %.16lf\n", (double)x, (double)y);
                x += cos(degree);
                y += sin(degree);
                //cout.precision(20);
                //cout<<fixed<<x<<" "<<y<<endl;
                //cout<<x<<" "<<y<<endl;

            }
        }
        printf("%.16lf %.16lf\n", (double)x, (double)y);
    }

    return 0;
}
